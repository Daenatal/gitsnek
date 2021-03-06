#pragma once

#include "Graphics.h"
#include "Location.h"


class Board
{
public:
	Board(Graphics& gfx);
	//what functions do we need?
	void DrawCell(const Location& loc, Color c);
	int GetWidth() const;
	int GetHeight() const;
	bool IsInsideBoard(const Location& loc) const;
	void DrawBorder();
private:
	static constexpr Color borderColor = Colors::Blue;
	static constexpr int dimension = 20;
	static constexpr int cellPadding = 1;
	static constexpr int width = 32;
	static constexpr int height = 24;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	static constexpr int x = 70;
	static constexpr int y = 50;
	Graphics& gfx; //so we don't have to pass it in everytime
};