#pragma once
#include "scene_manager.h"
#include "olcPixelGameEngine.h"

// Singleton to manage game related routines
class GameManager {
public:
	static void Update();
	static olc::vi2d Scale(const olc::vf2d& normalized_point);

	static std::string AddScene(std::shared_ptr<Scene>& scene);	
	static void SetActiveScene(const std::string& scene_id);
private:
	GameManager() {}
public:
	static olc::PixelGameEngine* pge;
	static SceneManager scene_mgr;

	static float aspect_ratio;
};