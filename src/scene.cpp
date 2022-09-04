#include "scene.h"

int32_t Scene::scene_counter = 0u;

Scene::Scene() {
	id = "Scene" + std::to_string(scene_counter);
}

void Scene::Update() {
	for (auto& o : objects) o->Update();
}

void Scene::Draw() {
	for (auto& o : objects) o->Draw();
}

std::string Scene::AddObject(std::shared_ptr<GameObject> object) {
	objects.push_back(object);
	return object->id;
}

GameObject* Scene::Find(const std::string& id) {	
	auto res = std::find_if(objects.begin(), objects.end(), [&](const std::shared_ptr<GameObject>& obj) -> bool { return obj->id == id; });

	if (res == objects.end()) return nullptr;

	return (*res).get();
}
