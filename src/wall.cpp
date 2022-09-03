#include "wall.h"

Wall::Wall() {
	id = "Wall_" + std::to_string(object_counter++);
}

void Wall::Update() {

}

void Wall::Draw() {

	if (tex.IsSprite()) {
		GameManager::pge->DrawSprite(GameManager::Scale(position), tex.sprite);
	}
	else {
		GameManager::pge->DrawRect(GameManager::Scale(position), GameManager::Scale(size), tex.color);
	}
}