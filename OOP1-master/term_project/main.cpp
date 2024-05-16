#include <queue>
#include "array.h"
#include "block.h"
#include "location.h"
#include <iostream>
using namespace std;

Array* block = new Array();
int score = 0;

bool make_block() {
	for (int i = 0; i < 5; i++) {
		if (block->arr[0][i] != 0) return false;
	}
	return block->make();
}

void command(char ch) {	
	if (ch = 'x') block->bottom();
	else if (ch = 's') block->down();
	else if (ch = 'a') block->left();
	else if (ch = 'd') block->right();
	else if (ch = 'e') block->rotate();
}

void print() {
	cout << "Score: ";
	cout << score << endl;
	cout << "" << endl;

	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 5; x++) {
			if (x == 0) {
				cout << (block->getColor(x, y));
				cout << (" ");
			}

			if (x > 0 && x < 5) {
				cout << (block->getColor(x, y));
				cout << " ";
			}
			if (x == 5) {
				cout << (block->getColor(x, y));
				cout << (" ¤±");
			}
		}
	}
}

int main() {
	
	cout << "Game Start" << endl;
	
	while (1) {
		make_block();
		print();

		do {
			char inp = getchar();
			command(inp);
			if (inp = 'q') break;
			print();
		} while (block->merge());

		if (block->merge()) block->bottom();
	}
}
