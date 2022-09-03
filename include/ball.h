#pragma once
#include "game_object.h"
#include "texture.h"
#include "game_manager.h"
#include "utils.h"

class Ball : public GameObject {
public:
	Ball();
public:
	void Update() override;
	void Draw() override;
public:
	olc::vf2d position, velocity, size;
	Texture tex;

	float rotation = 0.0f;
	Mat2x2 mat_rotation;
};