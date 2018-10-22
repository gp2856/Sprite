#pragma once
#include "Animation.h"
#include "Graphics.h"
#include "Colors.h"
#include "Vei2.h"
#include "Vec2.h"
#include <vector>

class Character
{
	enum class Sequence
	{
		WalkingLeft,
		WalkingRight,
		WalkingUp,
		WalkingDown,
		StandingLeft,
		StandingRight,
		StandingUp,
		StandingDown,
		Count
	};
public:
	Character(const Vec2& pos, const Surface& sprite);
	void Draw(Graphics& gfx) const;
	void SetDirection(const Vec2& dir);
	void Update(float dt);
private:
	const Surface& sprite;
	Vec2 pos;
	Vec2 vel = { 0.0f, 0.0f };
	float speed = 110.0f;
	std::vector<Animation> animations;
	Sequence iCurrentSequence = Sequence::StandingDown;
};