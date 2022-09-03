#include "game_object.h"

int32_t GameObject::object_counter = 0;

GameObject::GameObject() {
	// Generate an ID
	super_id = std::to_string(object_counter);
}

void GameObject::SetCustomID(const std::string& _id) {
	id = _id;
}