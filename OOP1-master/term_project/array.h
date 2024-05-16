#pragma once
#include <iostream>
#include <string.h>
#include "block.h"
#include <ctime>

class Array {
private:
	void init();

public:
	static int arr[12][5];

	Array();

	Block* Block;

	int getColor(int x, int y);
	void setColor(int x, int y, int color);

	void bottom();
	bool down();
	bool left();
	bool right();
	bool rotate();

	bool merge();
	bool make();
};