#include "wall.h"

Wall::Wall() {
	id = "Wall_" + std::to_string(object_counter++);
}


void Wall::Update() {
	if (curr_state == States::FORMING) {
		accumulator += GameManager::pge->GetElapsedTime();

		if (accumulator > delay) {
			accumulator = 0.0f;
			curr_state = States::ACTIVE;
		}
	}
}


void Wall::Draw() {

	// Get the screen's center
	const olc::vf2d& center = { 0.5f, 0.5f };
	const olc::vf2d& h_size = 0.5f * size;

	olc::vf2d points[4] = {
		{ position.x - h_size.x, position.y - h_size.y },
		{ position.x + h_size.x, position.y - h_size.y },
		{ position.x + h_size.x, position.y + h_size.y },
		{ position.x - h_size.x, position.y + h_size.y }
	};


	if (curr_state == States::FORMING) {
		for (int32_t i = 0; i < std::size(points); i++) {

			int32_t j = (i + 1) % std::size(points);

			const olc::vf2d& a = GameManager::Scale(mat_rotation * (points[i] - center) + center);
			const olc::vf2d& b = GameManager::Scale(mat_rotation * (points[j] - center) + center);

			GameManager::pge->DrawLine(a, b, tex.color, 3681400539);
		}
	}
	else if (curr_state == States::ACTIVE) {

		points[0] = GameManager::Scale(mat_rotation * (points[0] - center) + center);
		points[1] = GameManager::Scale(mat_rotation * (points[1] - center) + center);
		points[2] = GameManager::Scale(mat_rotation * (points[2] - center) + center);
		points[3] = GameManager::Scale(mat_rotation * (points[3] - center) + center);

		olc::vf2d uvs[4] = { {0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f}, {0.0f, 0.0f} };
		olc::Pixel colors[4] = { tex.color, tex.color, tex.color, tex.color };

		GameManager::pge->DrawExplicitDecal(nullptr, points, uvs, colors, 4u);
	}
}