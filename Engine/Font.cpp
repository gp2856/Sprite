#include "Font.h"
#include "SpriteEffect.h"
#include <assert.h>

Font::Font(const std::string & filename, Color chroma)
	:
	surface(filename),
	glyphWidth(surface.GetWidth() / nColumns),
	glyphHeight(surface.GetHeight() / nRows),
	chroma(chroma)
{
	assert(glyphHeight * nRows == surface.GetHeight());
	assert(glyphWidth * nColumns == surface.GetWidth());
}

void Font::DrawText(const std::string & text, const Vei2& pos, Color color, Graphics & gfx) const
{
	SpriteEffect::Substitute effect(color, chroma);
	auto curPos = pos;
	for (auto c : text)
	{
		if (c == '\n')
		{
			curPos.x = pos.x;
			curPos.y += glyphHeight;
			continue;
		}
		else if (c >= firstChar + 1 && c <= lastChar)
		{
			gfx.DrawSprite(curPos.x, curPos.y, MapGlyphRect(c), surface, effect);
		}
		curPos.x += glyphWidth;
	}
}

RectI Font::MapGlyphRect(char c) const
{
	assert(c >= firstChar && c <= lastChar);
	// Indexing starts at space, so the glyphIndex is the distance from firstChar
	const int glyphIndex = c - ' ';
	// Map 1D glyph to 2D coordinates
	const int yGlyph = glyphIndex / nColumns;
	const int xGlyph = glyphIndex % nColumns;
	// Convert grid coordinates to pixel coordinates in the font sheet
	return RectI({xGlyph * glyphWidth, yGlyph * glyphHeight }, glyphWidth, glyphHeight);
}
