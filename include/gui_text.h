#pragma once
#include "game_manager.h"
#include "game_object.h"
#include "utils.h"

namespace gui {
	class Text : public GameObject {
	public:
		Text();
	public:
		void Update() override;
		void Draw() override;
	public:
		olc::vf2d position, scale;
		olc::Pixel color;
		std::string text;

		float rotation = 0.0f;
		Mat2x2 mat_rotation;
	};
}
