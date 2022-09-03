#include "..\include\gui_text.h"

gui::Text::Text() {
	id = "Text_" + std::to_string(object_counter++);
}

void gui::Text::Update() {
	
}

void gui::Text::Draw() {

	// Center of screen
	const olc::vf2d& center = { 0.5f, 0.5f };

	// Cache the pointer to the engine
	olc::PixelGameEngine* pge = GameManager::pge;

	// Transformed vectors
	const olc::vf2d& t_pos = mat_rotation * (position - center) + center;

	olc::vf2d text_size = pge->GetTextSizeProp(text);
	text_size.x /= pge->ScreenWidth();
	text_size.y /= pge->ScreenHeight();

	pge->DrawRotatedStringPropDecal(
		GameManager::Scale(t_pos), 
		text,
		rotation,
		text_size * 0.5f,
		color,
		scale
	);
}