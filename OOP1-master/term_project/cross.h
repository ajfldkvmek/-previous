#pragma once
#include "block.h"

class Cross : public Block {

public:
	
	Cross(int c1, int c2, int c3, int c4, int c5);

	bool move_left();
	bool move_right();
	bool move_down();

	void left();
	void right();
	bool down();

	bool dest();
	bool rotate();
};