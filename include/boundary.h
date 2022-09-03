#pragma once
#include "game_object.h"
#include "texture.h"
#include "game_manager.h"
#include "utils.h"

class Boundary : public GameObject {
public:
	Boundary();
public:
	void Update() override;
	void Draw() override;
public:
	struct Line {
		olc::vf2d a, b;
		Texture tex;
		bool is_score_boundary = false;
	};

	std::vector<Line> lines;
	Mat2x2 mat_rotation;
	float rotation = 0.0f;
public:
	int32_t AddLine(const Line& line);
};