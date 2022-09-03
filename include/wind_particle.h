#pragma once
#include "particle.h"

class WindParticle : public Particle {
public:
	WindParticle();
public:
	void Update() override;
	void Draw() override;
public:
	olc::vf2d size;
};