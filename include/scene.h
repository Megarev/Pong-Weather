#pragma once
#include "game_object.h"
#include <functional>

class Scene : public GameObject {
public:
	Scene();
public:
	void Update() override;
	void Draw() override;
public:
	std::string AddObject(std::shared_ptr<GameObject> object);
	GameObject* Find(const std::string& id);
public:
	std::vector<std::shared_ptr<GameObject>> objects;

	static int32_t scene_counter;
	float rotation = 0.0f;
};
