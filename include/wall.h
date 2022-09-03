#pragma once
#include "game_object.h"
#include "texture.h"
#include "game_manager.h"

class Wall : public GameObject {
public:
	Wall();
public:
	// Override some virtual functions
	void Update() override;
	void Draw() override;
public:
	olc::vf2d position, size;
	Texture tex;
};
