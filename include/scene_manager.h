#pragma once
#include "scene.h"
#include <cassert>

class SceneManager {
public:
	std::string AddScene(const std::shared_ptr<Scene>& scene);
	void SetActiveScene(const std::string& scene_id);

	void Update();
private:
	std::map<std::string, std::shared_ptr<Scene>> scenes;	
	Scene* active_scene = nullptr;
};