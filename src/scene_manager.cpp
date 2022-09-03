#include "scene_manager.h"

std::string SceneManager::AddScene(const std::shared_ptr<Scene>& scene) {
	scenes.insert({ scene->id, scene });
	return scene->id;
}

void SceneManager::SetActiveScene(const std::string& id) {
	auto res = scenes.find(id);
	assert(res != scenes.end());

	active_scene = res->second.get();
}

void SceneManager::Update() {
	if (!active_scene) return;

	active_scene->OnWindowEvent();
	active_scene->Update();
	active_scene->Draw();
}