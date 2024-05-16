#include "array.h"
#include "cross.h"
#include "fold.h"
#include "tree.h"

int Array::arr[12][5];

Array::Array() {
	init();
}

void Array::init() {
	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 5; b++) arr[b][a] = 0;
	}
}

int Array::getColor(int x, int y) {
	return arr[y][x];
}

void Array::setColor(int x, int y, int color) {
	arr[y][x] = color;
}

bool Array::make() { //ºí·°¸¸µê
	int shape = rand() % 3;
	//rand()%4 + 1 -> 4»ö
	if (shape == Block::cross && (arr[1][2] == arr[0][2] == arr[1][1] == arr[1][3] == arr[2][2] == 0)) {
		Block = new Cross(rand() % 4 + 1, rand() % 4 + 1, rand() % 4 + 1, rand() % 4 + 1, rand() % 4 + 1);
	}
	else if (shape == Block::fold && (arr[1][2] == arr[0][2] == arr[1][3] == 0)) {
		Block = new Fold(rand() % 4 + 1, rand() % 4 + 1, rand() % 4 + 1);
	}
	else if (shape == Block::tree && (arr[1][2] == arr[0][2] == arr[2][2] == 0)) {
	Block = new Tree(rand() % 4 + 1, rand() % 4 + 1, rand() % 4 + 1);
	}

	return false;
}

bool Array::down() {
	return this->Block->down();
}

bool Array::left() {
	if (this->Block->move_left()) {
		this->Block->left();
		return true;
	}
	else return false;
}

bool Array::right() {
	if (this->Block->move_right()) {
		this->Block->right();
		return true;
	}
	else return false;
}

bool Array::rotate() {
	return this->Block->rotate();
}

void Array::bottom() {
	for (int x = 0; x < 5; x++) {
		int down = 11;
		for (int y = 11; y >= 0; y--) {
			if (arr[y][x] == 0)  continue;

			else if (arr[y][x] != 0 && down == y) arr[down][x] = arr[y][x];

			else if (arr[y][x] != 0 && down != y) {
				arr[down][x] = arr[y][x];
				arr[y][x] = 0;
			}
			down--;
		}
	}
}

bool Array::merge() {
	return Block->merge();
}