#pragma once
#include "olcPixelGameEngine.h"

struct Texture {
	olc::Sprite* sprite = nullptr;
	olc::Pixel color = olc::BLACK;

	inline bool IsSprite() const { return !!sprite; }
};