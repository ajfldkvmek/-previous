#pragma once
#include "block.h"

class Fold : public Block {
	
private:
	int state = 0;

public:
	Fold(int f1, int f2, int f3);
	
	bool move_left();
	bool move_right();
	bool move_down();

	void left();
	void right();
	bool down();

	bool rotate();
};