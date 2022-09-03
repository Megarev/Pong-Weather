#include "wind_particle.h"

WindParticle::WindParticle() {
	type = ParticleType::WIND;
}

void WindParticle::Update() {
	if (!is_active) return;

	position += velocity * GameManager::pge->GetElapsedTime();
}

void WindParticle::Draw() {
	if (!is_active) return;

	// TMP: Using AA rects instead of Oriented rects
	GameManager::pge->FillRect(GameManager::Scale(position), GameManager::Scale(size), color);
}