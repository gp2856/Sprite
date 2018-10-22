#pragma once
#include "Vei2.h"
#include "RectI.h"
#include "Graphics.h"
#include "Surface.h"
#include "Colors.h"
#include <string>

class Font
{
public:
	Font(const std::string& filename, Color chroma = Colors::White);
	void DrawText(const std::string& text, const Vei2& pos, Color color, Graphics& gfx) const;
private:
	// Helper function to map a character to a glyph on the fontsheet
	RectI MapGlyphRect(char c) const;
	Surface surface;
	int glyphWidth;
	int glyphHeight;
	static constexpr int nColumns = 32;
	static constexpr int nRows = 3;
	Color chroma;
	// Quick indices to the first and last drawable characters
	static constexpr char firstChar = ' ';
	static constexpr char lastChar = '~';
};