#pragma once
#include "Location.h"
#include "Board.h"

//put it in the same header file as snake since they are tied together
//class SnakeSegment
//{
//private: //we can actually do better than this, we can declare a class inside a class.
//};

class Snake //has an array of segment objects that manages them, snake is what other entities in the game interact with.
{
private:
	class Segment //this inner class doesn't know about how the snake implements its segments
	{
	public:
		//functions to initialize segments when the snake grows
		void InitHead(const Location& in_loc); //specifies location of the head when the snake is created
		void InitBody(Color c_in);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd) const;
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc); //move the snake by a delta value
	Location GetNextHeadLocation(const Location& delta_loc) const;
	void Grow();
	void Draw(Board& brd) const;
	bool IsInTileExceptEnd(const Location& target) const;
	bool IsInTile(const Location& target) const;

private:
	static constexpr Color headColor = Colors::Yellow;
	//static constexpr Color bodyColor = Colors::Green; this is now being handled by bodyColors array
	static constexpr int nSegmentsMax = 100; //max size of our array.
	Segment segments[nSegmentsMax]; //have to give the array a size but what size do we give it? As it eats it grows
	int nSegments = 1; //how many elements of the array we are currently using
};