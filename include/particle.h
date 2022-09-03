#pragma once
#include "game_manager.h"
#include "game_object.h"

class Particle {
public:
	Particle();

	virtual void Update();
	virtual void Draw();
public:
	olc::vf2d position, velocity;
	olc::Pixel color;
	bool is_active = false;
	
	enum class ParticleType {
		NONE,
		WIND
	} type = ParticleType::NONE;
};