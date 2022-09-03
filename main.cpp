#define OLC_PGE_APPLICATION
#include "game_manager.h"
#include "scenes/scene0.h"

#include <cassert>

// Driver class
class GameMain : public olc::PixelGameEngine {
public:
	GameMain() {
		// Initialize the static variables
		GameManager::pge = this;
		sAppName = "Game";
	}

	bool OnUserCreate() override {

		std::shared_ptr<Scene> scene0 = std::make_shared<Scene0>();
		const std::string& scene0_id = GameManager::AddScene(scene0);
		GameManager::SetActiveScene(scene0_id);

		return true;
	}

	bool OnUserUpdate(float dt) override {
		
		GameManager::Update();

		return true;
	}
private:
};

int main() {
	
	GameMain game;
	assert(game.Construct(768, 512, 1, 1, false, true));
	game.Start();

	return 0;
}