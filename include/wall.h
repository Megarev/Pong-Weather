#pragma once
#include "game_object.h"
#include "texture.h"
#include "game_manager.h"
#include "utils.h"

class Wall : public GameObject {
public:
	Wall();

	enum class States {
		INACTIVE = 0,
		FORMING = 1,
		ACTIVE = 2
	} curr_state = States::INACTIVE;
public:
	// Override some virtual functions
	void Update() override;
	void Draw() override;
public:
	olc::vf2d position, size;
	Texture tex;

	float rotation = 0.0f;

	Mat2x2 mat_rotation;
	
	float accumulator = 0.0f, delay = 2.5f;
};
