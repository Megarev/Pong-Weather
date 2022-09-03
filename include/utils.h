#pragma once
#include "olcPixelGameEngine.h"
#include <random>

// Some constants //
constexpr float PI = 3.1415926f;

struct Util {
	static bool IsPointerEmpty(void* p) { return !!p; }
	static float Random(float a, float b) {
		std::random_device rd;
		std::mt19937 m(rd());
		std::uniform_real_distribution<> dist(a, b);
	
		return dist(m);
	}
	static float Sign(float value) { return value == 0.0f ? 0.0f : (value > 0.0f ? 1.0f : -1.0f); }
};

struct Collisions {
	static bool RayVsRect(const olc::vf2d& rect_position, const olc::vf2d& rect_size, 
		const olc::vf2d& ray_start, const olc::vf2d& ray_dir, float& t_near_factor, olc::vf2d& cp, int& axis) {

		olc::vf2d t_near = (rect_position - ray_start) / ray_dir;
		olc::vf2d t_far = (rect_position + rect_size - ray_start) / ray_dir;

		if (t_near.x > t_far.x) std::swap(t_near.x, t_far.x);
		if (t_near.y > t_far.y) std::swap(t_near.y, t_far.y);

		if (t_near.x > t_far.y || t_near.y > t_far.x) return false;
	
		t_near_factor = std::fmaxf(t_near.x, t_near.y);
		axis = t_near.x > t_near.y ? 1 : -1;
		float t_far_factor = std::fminf(t_far.x, t_far.y);

		if (t_far_factor < 0.0f) return false;

		cp = ray_start + t_near_factor * ray_dir;

		return true;
	}

	// Dynamic AABB (CCD)
	static bool StaticRectVsDynamicRect(const olc::vf2d& rect_position_A, const olc::vf2d& rect_size_A,
		const olc::vf2d& rect_position_B, const olc::vf2d& rect_size_B, const olc::vf2d& rect_vel_B, 
		float dt, float& t_near_factor, olc::vf2d& cp, int& axis) {

		// Positions are w.r.t. center...
		// Convert these positions w.r.t. top-left corner

		olc::vf2d expanded_rect_target_pos = rect_position_A - rect_size_B * 0.5f;
		olc::vf2d expanded_rect_target_size = rect_size_A + rect_size_B;

		if (RayVsRect(expanded_rect_target_pos, expanded_rect_target_size, rect_position_B + rect_size_B * 0.5f, rect_vel_B * dt, t_near_factor, cp, axis)) {
			if (t_near_factor < 1.0f) return true;
		}

		return false;
	}
};

struct Mat2x2 {
	float m00, m01;
	float m10, m11;
	
	void SetIdentity() {
		m00 = 1.0f; m01 = 0.0f;
		m10 = 0.0f; m11 = 1.0f;
	}

	void SetRotation(float rotation) {
		float c = cosf(rotation), s = sinf(rotation);

		m00 = c; m01 = -s;
		m10 = s; m11 = c;
	}

	olc::vf2d operator*(const olc::vf2d& other) {
		return olc::vf2d{
			other.x * m00 + other.y * m01,
			other.x * m10 + other.y * m11
		};
	}
};