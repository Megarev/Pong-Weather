#include "scene0.h"

Scene0::Scene0() {

	id = "Scene0";
	float padding = 0.15f;

	scene_rotation = 0.0f;
	mat_rotation.SetRotation(scene_rotation);

	/*std::shared_ptr<GameObject> obj_wall0 = std::make_unique<Wall>();
	auto wall0 = std::static_pointer_cast<Wall>(obj_wall0);
	wall0->position = { 0.5f, 0.5f };
	wall0->size = { 0.1f, 0.1f };
	wall0->tex.color = { 255, 255, 255 };
	object_ids["wall0"] = (AddObject(obj_wall0));*/

	std::shared_ptr<GameObject> obj_paddle0 = std::make_unique<Paddle>();
	auto paddle0 = std::static_pointer_cast<Paddle>(obj_paddle0);
	paddle0->position = { 0.5f, 1.0f - padding };
	paddle0->size = { 0.25f, 0.05f };
	paddle0->tex.color = olc::CYAN * 0.75f;
	paddle0->rotation = scene_rotation;
	paddle0->mat_rotation.SetRotation(scene_rotation);
	object_ids["paddle0"] = (AddObject(obj_paddle0));

	std::shared_ptr<GameObject> obj_paddle1 = std::make_unique<Paddle>();
	auto paddle1 = std::static_pointer_cast<Paddle>(obj_paddle1);
	paddle1->position = { 0.5f, 0.0f + padding };
	paddle1->size = { 0.25f, 0.05f };
	paddle1->tex.color = olc::MAGENTA * 0.75f;
	paddle1->rotation = scene_rotation;
	paddle1->mat_rotation.SetRotation(scene_rotation);
	object_ids["paddle1"] = (AddObject(obj_paddle1));

	std::shared_ptr<GameObject> obj_ball = std::make_unique<Ball>();
	auto ball = std::static_pointer_cast<Ball>(obj_ball);
	ball->position = { 0.5f, 0.5f };
	ball->size = { 0.020f, 0.025f };
	ball->tex.color = { 255, 255, 255 };
	ball->velocity = { 0.1f, 0.1f };
	ball->rotation = scene_rotation;
	ball->mat_rotation.SetRotation(scene_rotation);
	object_ids["ball"] = (AddObject(obj_ball));

	std::shared_ptr<GameObject> obj_boundary = std::make_unique<Boundary>();
	auto boundary = std::static_pointer_cast<Boundary>(obj_boundary);
	
	Boundary::Line lineA;
	lineA.a = { 0.0f + padding, 0.0f + padding };
	lineA.b = { 1.0f - padding, 0.0f + padding };
	lineA.tex.color = { 255, 0, 255 };
	lineA.is_score_boundary = true;
	boundary->AddLine(lineA);

	Boundary::Line lineB;
	lineB.a = { 1.0f - padding, 0.0f + padding };
	lineB.b = { 1.0f - padding, 1.0f - padding };
	lineB.tex.color = { 255, 255, 255 };
	lineB.is_score_boundary = false;
	boundary->AddLine(lineB);

	Boundary::Line lineC;
	lineC.a = { 1.0f - padding, 1.0f - padding };
	lineC.b = { 0.0f + padding, 1.0f - padding };
	lineC.tex.color = { 255, 0, 255 };
	lineC.is_score_boundary = true;
	boundary->AddLine(lineC);

	Boundary::Line lineD;
	lineD.a = { 0.0f + padding, 1.0f - padding };
	lineD.b = { 0.0f + padding, 0.0f + padding };
	lineD.tex.color = { 255, 255, 255 };
	lineD.is_score_boundary = false;
	boundary->AddLine(lineD);

	object_ids["boundary"] = (AddObject(obj_boundary));

	std::shared_ptr<GameObject> obj_show_boundary = std::make_unique<Boundary>();
	auto show_boundary = std::static_pointer_cast<Boundary>(obj_show_boundary);

	Boundary::Line line;
	line.a = lineB.a + 0.5f * (lineB.b - lineB.a);
	line.b = lineD.a + 0.5f * (lineD.b - lineD.a);
	line.is_score_boundary = false;
	line.tex.color = olc::VERY_DARK_MAGENTA;
	show_boundary->AddLine(line);

	object_ids["show_boundary"] = (AddObject(obj_show_boundary));

	std::shared_ptr<GameObject> obj_scoretext0 = std::make_unique<gui::Text>();
	auto scoretext0 = std::static_pointer_cast<gui::Text>(obj_scoretext0);

	scoretext0->position = { line.a.x + 0.01f, line.a.y + 0.05f };
	scoretext0->color = olc::WHITE;
	scoretext0->scale = { 4.0f, 5.0f };
	scoretext0->text = "0";
	scoretext0->rotation = scene_rotation;
	scoretext0->mat_rotation = mat_rotation;



	object_ids["scoretext0"] = (AddObject(obj_scoretext0));

	std::shared_ptr<GameObject> obj_scoretext1 = std::make_unique<gui::Text>();
	auto scoretext1 = std::static_pointer_cast<gui::Text>(obj_scoretext1);

	scoretext1->position = { line.a.x + 0.01f, line.a.y - 0.1f };
	scoretext1->color = olc::WHITE;
	scoretext1->scale = { 4.0f, 5.0f };
	scoretext1->text = "0";
	scoretext1->rotation = scene_rotation;
	scoretext1->mat_rotation = mat_rotation;

	object_ids["scoretext1"] = (AddObject(obj_scoretext1));

	std::shared_ptr<GameObject> obj_text_indicator0 = std::make_unique<gui::Text>();
	auto text_indicator0 = std::static_pointer_cast<gui::Text>(obj_text_indicator0);

	text_indicator0->position = { paddle0->position.x - paddle0->size.x * 0.65f, paddle0->position.y };
	text_indicator0->color = olc::YELLOW;
	text_indicator0->scale = { 4.0f, 5.0f };
	text_indicator0->text = "A";
	text_indicator0->rotation = scene_rotation;
	text_indicator0->mat_rotation = mat_rotation;

	object_ids["text_indicator0"] = (AddObject(obj_text_indicator0));

	std::shared_ptr<GameObject> obj_text_indicator1 = std::make_unique<gui::Text>();
	auto text_indicator1 = std::static_pointer_cast<gui::Text>(obj_text_indicator1);

	text_indicator1->position = { paddle0->position.x + paddle0->size.x * 0.5f, paddle0->position.y };
	text_indicator1->color = olc::YELLOW;
	text_indicator1->scale = { 4.0f, 5.0f };
	text_indicator1->text = "D";
	text_indicator1->rotation = scene_rotation;
	text_indicator1->mat_rotation = mat_rotation;

	object_ids["text_indicator1"] = (AddObject(obj_text_indicator1));


	// Particles //
	int n = 200;
	for (int i = 0; i < n; i++) {
		std::shared_ptr<Particle> p = std::make_unique<WindParticle>();
		auto _p = std::static_pointer_cast<WindParticle>(p);
		
		_p->position = {};
		_p->size = { Util::Random(0.05f, 0.25f), Util::Random(0.01f, 0.02f) };
		_p->color = olc::DARK_GREY;
		_p->velocity = {};
	
		particles.push_back(p);
	}
}

void Scene0::Update() {


	// ==========[CONVENIENCE VARIABLES]==========

	// Get the screen's center
	const olc::vf2d& center = { 0.5f, 0.5f };
	olc::PixelGameEngine* pge = GameManager::pge;
	
	// Time-stepping //
	accumulator += pge->GetElapsedTime();

	if (accumulator > delay) {
		accumulator = 0.0f;
		
		int32_t dir = rand() % 2;
		for (auto& p : particles) {

			p->is_active = true;

			// TMP: Temp solution
			// LEFT Direction
			if (dir == 0) {
				p->position = { 1.15f + Util::Random(0.05f, 1.0f), Util::Random(0.01f, 0.99f) };
				p->velocity = { Util::Random(-1.0f, -0.5f), 0.0f };

				scene_rotational_velocity = -Util::Random(0.1f, 0.5f);
			}

			// RIGHT Direction
			else {
				p->position = { -(0.15f + Util::Random(0.05f, 1.0f)), Util::Random(0.01f, 0.99f) };
				p->velocity = { Util::Random(0.5f, 1.0f), 0.0f };

				scene_rotational_velocity = Util::Random(0.1f, 0.5f);
			}
		}

		delay = Util::Random(10.0f, 15.0f);
	}

	// ==========[CACHE OBJECTS]==========
	Paddle* paddle0 = nullptr;
	Paddle* paddle1 = nullptr;
	Boundary* boundary = nullptr;
	Boundary* show_boundary = nullptr;
	Ball* ball = nullptr;
	
	gui::Text* scoretext0 = nullptr;
	gui::Text* scoretext1 = nullptr;
	gui::Text* text_indicator0 = nullptr;
	gui::Text* text_indicator1 = nullptr;

	for (auto obj : objects) {

		// Paddle0
		if (obj->id == object_ids["paddle0"]) paddle0 = static_cast<Paddle*>(obj.get());
		// Paddle1
		if (obj->id == object_ids["paddle1"]) paddle1 = static_cast<Paddle*>(obj.get());
		// Boundary
		if (obj->id == object_ids["boundary"]) boundary = static_cast<Boundary*>(obj.get());
		// Show Boundary
		if (obj->id == object_ids["show_boundary"]) show_boundary = static_cast<Boundary*>(obj.get());
		// Ball
		if (obj->id == object_ids["ball"]) ball = static_cast<Ball*>(obj.get());
		// ScoreText0
		if (obj->id == object_ids["scoretext0"]) scoretext0 = static_cast<gui::Text*>(obj.get());
		// ScoreText1
		if (obj->id == object_ids["scoretext1"]) scoretext1 = static_cast<gui::Text*>(obj.get());
		// ScoreText0
		if (obj->id == object_ids["text_indicator0"]) text_indicator0 = static_cast<gui::Text*>(obj.get());
		// ScoreText1
		if (obj->id == object_ids["text_indicator1"]) text_indicator1 = static_cast<gui::Text*>(obj.get());

		obj->Update();
	}

	bool is_pointer_valid = (
		Util::IsPointerEmpty(paddle0) &
		Util::IsPointerEmpty(paddle1) &
		Util::IsPointerEmpty(boundary) &
		Util::IsPointerEmpty(show_boundary) &
		Util::IsPointerEmpty(ball) &
		Util::IsPointerEmpty(scoretext0) &
		Util::IsPointerEmpty(scoretext1)
		);

	assert(is_pointer_valid && "One of the objects is invalid!");

	// ==========[CONVENIENT LAMBDA FUNCTIONS]==========
	auto ResetBall = [&]() -> void {
		ball->velocity = { 0.01f + 5.0f * Util::Random(-0.1f, 0.1f), 0.01f + 5.0f * Util::Random(-0.1f, 0.1f) };
		ball->position = center;
	};




	// ==========[INPUTS]==========
	if (pge->GetKey(olc::A).bHeld) paddle0->velocity.x -= 0.05f;
	if (pge->GetKey(olc::D).bHeld) paddle0->velocity.x += 0.05f;

	text_indicator0->position = { paddle0->position.x - paddle0->size.x * 0.65f, paddle0->position.y };
	text_indicator1->position = { paddle0->position.x + paddle0->size.x * 0.5f, paddle0->position.y };



	// ==========[LOGIC INVOLVING THE OBJECTS]==========

	scene_rotation += scene_rotational_velocity * pge->GetElapsedTime();
	mat_rotation.SetRotation(scene_rotation);

	// Rotate all the objects that affected by the scene's rotation
	paddle0->mat_rotation = mat_rotation;
	paddle0->rotation = scene_rotation;

	paddle1->mat_rotation = mat_rotation;
	paddle1->rotation = scene_rotation;

	boundary->mat_rotation = mat_rotation;
	boundary->rotation = scene_rotation;

	ball->mat_rotation = mat_rotation;
	ball->rotation = scene_rotation;

	show_boundary->mat_rotation = mat_rotation;
	show_boundary->rotation = scene_rotation;

	scoretext0->mat_rotation = mat_rotation;
	scoretext0->rotation = scene_rotation;

	scoretext1->mat_rotation = mat_rotation;
	scoretext1->rotation = scene_rotation;

	text_indicator0->mat_rotation = mat_rotation;
	text_indicator0->rotation = scene_rotation;

	text_indicator1->mat_rotation = mat_rotation;
	text_indicator1->rotation = scene_rotation;


#if FALSE
	if (pge->GetKey(olc::LEFT).bHeld) paddle1->velocity.x -= 0.05f;
	if (pge->GetKey(olc::RIGHT).bHeld) paddle1->velocity.x += 0.05f;
#else
	// PADDLE1 AI system //
	paddle1->velocity.x = (ball->position.x - paddle1->position.x) * 3.5f;

	float velocity_threshold = 5.0f;
	paddle1->velocity.x = std::fmaxf(-velocity_threshold, std::fminf(paddle1->velocity.x, velocity_threshold));
#endif


	// PADDLE-BOUNDARY LOGIC
	// TMP: Quick and easy solution (TOP=0, RIGHT=1, BOTTOM=2, LEFT=3)

	// Get the line objects
	Boundary::Line lineA0 = boundary->lines[1];
	Boundary::Line lineB0 = boundary->lines[3];

	// Apply the transformations on the line objects
	lineA0.a = mat_rotation * (lineA0.a - center) + center;
	lineA0.b = mat_rotation * (lineA0.b - center) + center;
	lineB0.a = mat_rotation * (lineB0.a - center) + center;
	lineB0.b = mat_rotation * (lineB0.b - center) + center;

	// Compute the line normals
	const olc::vf2d& line_normal_A0 = (lineA0.b - lineA0.a).perp();
	const olc::vf2d& line_normal_B0 = (lineB0.b - lineB0.a).perp();

	// Compute the paddle extents
	olc::vf2d paddle0_extents[2] = {
		{ paddle0->position + olc::vf2d{ paddle0->size.x * 0.5f, 0.0f } },
		{ paddle0->position - olc::vf2d{ paddle0->size.x * 0.5f, 0.0f } }
	};

	olc::vf2d paddle1_extents[2] = {
		{ paddle1->position + olc::vf2d{ paddle1->size.x * 0.5f, 0.0f } },
		{ paddle1->position - olc::vf2d{ paddle1->size.x * 0.5f, 0.0f } }
	};

	// Apply the transformations on the paddle extents
	paddle0_extents[0] = mat_rotation * (paddle0_extents[0] - center) + center;
	paddle0_extents[1] = mat_rotation * (paddle0_extents[1] - center) + center;

	paddle1_extents[0] = mat_rotation * (paddle1_extents[0] - center) + center;
	paddle1_extents[1] = mat_rotation * (paddle1_extents[1] - center) + center;

	// Compute the dot products
	float paddle0_a_overlap = (paddle0_extents[0] - lineA0.a).dot(line_normal_A0);
	float paddle0_b_overlap = (paddle0_extents[1] - lineB0.a).dot(line_normal_B0);

	float paddle1_a_overlap = (paddle1_extents[0] - lineA0.a).dot(line_normal_A0);
	float paddle1_b_overlap = (paddle1_extents[1] - lineB0.a).dot(line_normal_B0);

	float bounce_force = 0.025f;

	// Test for collision & resolution
	if (paddle0_a_overlap < 0.0f) {
		paddle0->position.x += paddle0_a_overlap;
		paddle0->velocity.x = -bounce_force;
	}
	if (paddle0_b_overlap < 0.0f) {
		paddle0->position.x -= paddle0_b_overlap;
		paddle0->velocity.x = bounce_force;
	}

	if (paddle1_a_overlap < 0.0f) {
		paddle1->position.x += paddle1_a_overlap;
		paddle1->velocity.x = -bounce_force;
	}
	if (paddle1_b_overlap < 0.0f) {
		paddle1->position.x -= paddle1_b_overlap;
		paddle1->velocity.x = bounce_force;
	}



	// BALL LOGIC //
	olc::vf2d ball_extents[2] = {
		{ ball->position + olc::vf2d{ ball->size.x * 0.5f, 0.0f } },
		{ ball->position - olc::vf2d{ ball->size.x * 0.5f, 0.0f } }
	};

	// Apply the transformations on the paddle extents
	ball_extents[0] = mat_rotation * (ball_extents[0] - center) + center;
	ball_extents[1] = mat_rotation * (ball_extents[1] - center) + center;

	// Compute the dot products
	float ball_a_overlap = (ball_extents[0] - lineA0.a).dot(line_normal_A0);
	float ball_b_overlap = (ball_extents[1] - lineB0.a).dot(line_normal_B0);

	// Test for collision & resolution
	if (ball_a_overlap < 0.0f) {
		ball->position.x += ball_a_overlap;

		// TMP: Quick and easy trick
		ball->velocity.x *= -1.0f;
	}

	if (ball_b_overlap < 0.0f) {
		ball->position.x -= ball_b_overlap;

		// TMP: Quick and easy trick
		ball->velocity.x *= -1.0f;
	}



	// PADDLE-BALL LOGIC //
	// Continuous Collision System

	// To work with the paddle & ball in AABB space rather than OBB space...

	float t_near = 0.0f;
	olc::vf2d cp;
	int axis = 0;

	if (Collisions::StaticRectVsDynamicRect(paddle0->position - 0.5f * paddle0->size, paddle0->size,
		ball->position - 0.5f * ball->size, ball->size, ball->velocity, pge->GetElapsedTime(), t_near, cp, axis)) {

		ball->position = cp;

		if (axis < 0) {
			ball->velocity.y *= -1.15f;
			ball->velocity.x = paddle0->velocity.x * 0.85f + Util::Random(-0.05f, 0.05f);
		}
		else {
			ball->velocity.x = paddle0->velocity.x;
		}

		// Clamp the ball's velocity in the y-axis
		ball->velocity.y = std::fminf(std::fabsf(ball->velocity.y), 3.5f) * Util::Sign(ball->velocity.y);
	}

	if (Collisions::StaticRectVsDynamicRect(paddle1->position - 0.5f * paddle1->size, paddle1->size,
		ball->position - 0.5f * ball->size, ball->size, ball->velocity, pge->GetElapsedTime(), t_near, cp, axis)) {

		ball->position = cp;

		if (axis < 0) {
			ball->velocity.y *= -1.15f;
			ball->velocity.x = paddle1->velocity.x * 0.85f + Util::Random(-0.05f, 0.05f);
		}
		else {
			ball->velocity.x = paddle1->velocity.x;
		}

		// Clamp the ball's velocity in the y-axis
		ball->velocity.y = std::fminf(std::fabsf(ball->velocity.y), 3.5f) * Util::Sign(ball->velocity.y);
	}




	// SCORE SYSTEM //
	// Get the line objects
	Boundary::Line lineA1 = boundary->lines[2];
	Boundary::Line lineB1 = boundary->lines[0];

	// Apply the transformations on the line objects
	lineA1.a = mat_rotation * (lineA1.a - center) + center;
	lineA1.b = mat_rotation * (lineA1.b - center) + center;
	lineB1.a = mat_rotation * (lineB1.a - center) + center;
	lineB1.b = mat_rotation * (lineB1.b - center) + center;

	const olc::vf2d& transformed_ball_position = mat_rotation * (ball->position - center) + center;

	// Compute the line normals
	const olc::vf2d& line_normal_A1 = (lineA1.b - lineA1.a).perp();
	const olc::vf2d& line_normal_B1 = (lineB1.b - lineB1.a).perp();

	// Compute the dot products
	float test_A1 = (transformed_ball_position - lineA1.a).dot(line_normal_A1);
	float test_B1 = (transformed_ball_position - lineB1.a).dot(line_normal_B1);

	float threshold = 0.5f;

	if (test_A1 < 0.0f && std::fabsf(test_A1) < threshold) {
		// WIN for Paddle1
		score1++;

		scoretext1->text = std::to_string(score1);
		scoretext1->color = olc::GREEN;
		scoretext0->color = olc::RED;

		ResetBall();
	}

	if (test_B1 < 0.0f && std::fabsf(test_B1) < threshold) {
		// WIN for Paddle0
		score0++;

		scoretext0->text = std::to_string(score0);
		scoretext0->color = olc::GREEN;
		scoretext1->color = olc::RED;

		ResetBall();
	}


	bool is_environment_still = false;

	// Particles //
	for (auto& p : particles) {
		p->Update();
		
		// TMP: Temp solution for getting things started
		if (p->velocity.x > 0.0f) {
			if (p->position.x > 1.5f) p->is_active = false;
		}

		else if (p->velocity.x < 0.0f) {
			if (p->position.x < -0.5f) p->is_active = false;
		}

		is_environment_still |= p->is_active;
	}

	if (!is_environment_still) {
		scene_rotational_velocity *= 0.95f;
	}
}

void Scene0::Draw() {
	for (auto& obj : objects) obj->Draw();


	// Particles //
	for (auto& p : particles) p->Draw();

	// GUI //



}