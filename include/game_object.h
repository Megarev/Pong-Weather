#pragma once
#include "olcPixelGameEngine.h"

// Superclass
class GameObject {
public:
	void SetCustomID(const std::string& _id);
	
	// Some Virtual functions
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void OnWindowEvent() {}
public:
	GameObject();
public:
	std::string super_id, id;
	static int32_t object_counter;
};