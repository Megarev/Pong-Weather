#include "particle.h"

Particle::Particle() {

}


void Particle::Update() {

	// Cache the pointer to the engine
	olc::PixelGameEngine* pge = GameManager::pge;

	if (is_active) {
		position += velocity * pge->GetElapsedTime();
	}
}


void Particle::Draw() {
	if (!is_active) return;

}