#include "paddle.h"

Paddle::Paddle() {
	id = "Paddle_" + std::to_string(object_counter++);
}

void Paddle::Update() {

	// Cache the engine pointer
	auto* pge = GameManager::pge;

	// Logic //
	position += velocity * pge->GetElapsedTime();
	velocity *= 0.9f; // Friction
}

void Paddle::Draw() {
	if (tex.IsSprite()) {
		GameManager::pge->DrawSprite(GameManager::Scale(position), tex.sprite);
	}
	else {

		// Screen center
		const olc::vf2d& center = { 0.5f, 0.5f };
		const olc::vf2d& h_size = size * 0.5f;

		olc::vf2d points[4] = { 
			{ position.x - h_size.x, position.y - h_size.y },
			{ position.x + h_size.x, position.y - h_size.y },
			{ position.x + h_size.x, position.y + h_size.y },
			{ position.x - h_size.x, position.y + h_size.y }
		};
		points[0] = GameManager::Scale(mat_rotation * (points[0] - center) + center);
		points[1] = GameManager::Scale(mat_rotation * (points[1] - center) + center);
		points[2] = GameManager::Scale(mat_rotation * (points[2] - center) + center);
		points[3] = GameManager::Scale(mat_rotation * (points[3] - center) + center);

		olc::vf2d uvs[4] = { {0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f} };
		olc::Pixel colors[4] = { tex.color, tex.color, tex.color, tex.color };

		GameManager::pge->DrawExplicitDecal(nullptr, points, uvs, colors, 4u);
	}
}