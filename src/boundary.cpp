#include "boundary.h"

Boundary::Boundary() {
	id = "Boundary_" + std::to_string(object_counter++);
}

void Boundary::Update() {

}

void Boundary::Draw() {
	for (auto& line : lines) {
		if (line.tex.IsSprite()) {
			GameManager::pge->DrawSprite(GameManager::Scale(line.a), line.tex.sprite);
		}
		else {
			// Get the screen's center
			const olc::vf2d& center = { 0.5f, 0.5f };

			const olc::vf2d& a = GameManager::Scale(mat_rotation * (line.a - center) + center);
			const olc::vf2d& b = GameManager::Scale(mat_rotation * (line.b - center) + center);

			GameManager::pge->DrawLine(a, b, line.tex.color);
		}
	}
}

int32_t Boundary::AddLine(const Line& line) {
	lines.push_back(line);

	return int32_t(lines.size());
}
