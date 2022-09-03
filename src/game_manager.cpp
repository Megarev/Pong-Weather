#include "game_manager.h"

olc::PixelGameEngine* GameManager::pge = nullptr;
SceneManager GameManager::scene_mgr;

float GameManager::aspect_ratio = 0.0f;

void GameManager::Update() {
	if (!pge) return;

	//aspect_ratio = float(pge->ScreenHeight()) / float(pge->ScreenWidth());
	
	aspect_ratio = 1.0f;

	pge->Clear(olc::BLACK);
	scene_mgr.Update();
}

olc::vi2d GameManager::Scale(const olc::vf2d& normalized_point) {
	return { int(normalized_point.x * aspect_ratio * pge->ScreenWidth()), int(normalized_point.y * pge->ScreenHeight()) };
}

std::string GameManager::AddScene(std::shared_ptr<Scene>& scene) {
	return scene_mgr.AddScene(scene);
}

void GameManager::SetActiveScene(const std::string& scene_id) {
	scene_mgr.SetActiveScene(scene_id);
}
