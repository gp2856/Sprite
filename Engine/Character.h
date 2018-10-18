#pragma once
#include "Animation.h"
#include "Graphics.h"
#include "Colors.h"
#include "Vei2.h"
#include "Vec2.h"
#include <vector>

class Character
{
private:
	Vec2 pos;
	Vec2 vel = { 0.0f, 0.0f };
	float speed;
	std::vector<Animation> animations;
};