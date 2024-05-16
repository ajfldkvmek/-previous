#pragma once
#include <vector>

class Block {
protected:
	int row = 2, col = 1;
	int x[4] = { 1,0,-1,0 };
	int y[4] = { 0,1,0,-1 };

	bool block_check;

public:
	enum type {
		cross,
		fold,
		tree
	};
	Block();

	virtual bool move_left() = 0;
	virtual bool move_right() = 0;
	virtual bool move_down() = 0;

	bool merge();

	virtual bool down() = 0;
	virtual void right() = 0;
	virtual void left() = 0;
	virtual bool rotate() = 0;
};