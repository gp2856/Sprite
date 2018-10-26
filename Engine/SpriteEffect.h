#pragma once
#include "Colors.h"
#include "Graphics.h"
namespace SpriteEffect
{
	class Chroma
	{
	public:
		Chroma(Color c)
			:
			chroma(c)
		{}
		void operator() (Color cSrc, int xDest, int yDest, Graphics& gfx) const
		{
			if (cSrc != chroma)
			{
				gfx.PutPixel(xDest, yDest, cSrc);
			}
		}
	private:
		Color chroma;
	};

	class Copy
	{
	public:
		void operator() (Color cSrc, int xDest, int yDest, Graphics& gfx) const
		{
			gfx.PutPixel(xDest, yDest, cSrc);
		}
	};

	class Substitute
	{
	public:
		Substitute(Color s, Color c)
			:
			substitute(s),
			chroma(c)
		{}

		void operator() (Color cSrc, int xDest, int yDest, Graphics& gfx) const
		{
			if (cSrc != chroma)
			{
				gfx.PutPixel(xDest, yDest, substitute);
			}
		}
	private:
		Color substitute;
		Color chroma;
	};

	class Ghost
	{
	public:
		Ghost(Color cDest, Color chroma, float alpha)
			:
			chroma(chroma),
			cDest(cDest),
			alpha(alpha)
		{}

		void operator() (Color cSrc, int xDest, int yDest, Graphics& gfx) const
		{
			Color blendedColor = { Blend(cSrc.GetR(), cDest.GetR()), Blend(cSrc.GetG(), cDest.GetG()), Blend(cSrc.GetB(), cDest.GetB()) };
		}
	private:
		Color chroma;
		Color cDest;
		float alpha;

		unsigned char Blend(unsigned char newColor, unsigned char oldColor) const
		{
			return (unsigned char)(newColor * alpha) + (1 - alpha) * oldColor;
		}
	};
}