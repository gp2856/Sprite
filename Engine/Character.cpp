#include "Character.h"

Character::Character(const Vec2 & pos, const Surface& sprite)
	:
	pos(pos),
	sprite(sprite)
{
	for (auto i = 0; i < (int)Sequence::StandingLeft; i++)
	{
		animations.emplace_back(90, 90 * i, 90, 90, 4, sprite, 0.16f, Colors::Magenta);
	}
	for (auto i = (int)Sequence::StandingLeft; i < (int)Sequence::Count; i++)
	{
		animations.emplace_back(0, 90 * (i - (int)Sequence::StandingLeft), 90, 90, 1, sprite, 0.16f, Colors::Magenta);
	}
}

void Character::Draw(Graphics & gfx) const
{
	if (effectActive)
	{
		animations[(int)iCurrentSequence].DrawSubstitute((Vei2)pos, gfx, Colors::Red);
	}
	else
	{
		animations[(int)iCurrentSequence].Draw((Vei2)pos, gfx);
	}
}

void Character::SetDirection(const Vec2 & dir)
{
	if (dir.x > 0.0f)
	{
		iCurrentSequence = Sequence::WalkingRight;
	}
	else if (dir.x < 0.0f)
	{
		iCurrentSequence = Sequence::WalkingLeft;
	}
	else if (dir.y > 0.0f)
	{
		iCurrentSequence = Sequence::WalkingDown;
	}
	else if (dir.y < 0.0f)
	{
		iCurrentSequence = Sequence::WalkingUp;
	}
	else
	{
		if (vel.x > 0.0f)
		{
			iCurrentSequence = Sequence::StandingRight;
		}
		else if (vel.x < 0.0f)
		{
			iCurrentSequence = Sequence::StandingLeft;
		}
		else if (vel.y > 0.0f)
		{
			iCurrentSequence = Sequence::StandingDown;
		}
		else if (vel.y < 0.0f)
		{
			iCurrentSequence = Sequence::StandingUp;
		}
	}
	vel = dir * speed;
}

void Character::Update(float dt)
{
	pos += vel * dt;
	animations[(int)iCurrentSequence].Update(dt);
	if (effectActive)
	{
		effectTimer += dt;
		if (effectTimer >= effectHoldTime)
		{
			effectTimer -= effectHoldTime;
			effectActive = false;
		}
	}
}

void Character::ActivateEffect()
{
	effectActive = true;
}

float Character::GetEffectTimer()
{
	return effectTimer;
}

bool Character::GetEffectActive()
{
	return effectActive;
}
