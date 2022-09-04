#pragma once
#include "scene.h"
#include "wall.h"
#include "boundary.h"
#include "paddle.h"
#include "utils.h"
#include "ball.h"
#include "gui_text.h"
#include "particle.h"
#include "wind_particle.h"


class Scene0 : public Scene {
public:
	Scene0();
public:
	void Update() override;
	void Draw() override;
public:
	std::map<std::string, std::string> object_ids;
	std::vector<std::shared_ptr<Particle>> particles;

	float scene_rotation = 0.0f;
	float scene_rotational_velocity = 0.0f;
	Mat2x2 mat_rotation;

	int32_t score0 = 0, score1 = 0;
	
	// For the particle effects
	float accumulator = 0.0f, delay = 10.0f;

	// For the wall
	float wall_acc = 0.0f, wall_delay = 10.0f;
	bool wall_flipper = false;

	// Audio file wave forms
	olc::sound::Wave wall_hit;
	olc::sound::Wave wind_swoosh;
	olc::sound::Wave paddle_hit;
	olc::sound::Wave paddle0_win;
	olc::sound::Wave paddle1_win;
};