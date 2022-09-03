#pragma once
#include "scene.h"
#include "wall.h"
#include "boundary.h"
#include "paddle.h"
#include "utils.h"
#include "ball.h"
#include "gui_text.h"
#include "particle.h"
#include "wind_particle.h"

class Scene0 : public Scene {
public:
	Scene0();
public:
	void Update() override;
	void Draw() override;
public:
	std::map<std::string, std::string> object_ids;
	std::vector<std::shared_ptr<Particle>> particles;
	
	float scene_rotation = 0.0f;
	float scene_rotational_velocity = 0.0f;
	Mat2x2 mat_rotation;

	int32_t score0 = 0, score1 = 0;
	float accumulator = 0.0f, delay = 10.0f;
};