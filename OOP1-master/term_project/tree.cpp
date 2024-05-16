#include "tree.h"
#include "array.h"


Tree::Tree(int t1, int t2, int t3) {
	Array::arr[col][row] = t1;
	Array::arr[col- 1][row] = t2;
	Array::arr[col + 1][row] = t3;
}

bool Tree::move_left() {
	if (bo && row - 2 >= 0) return true;
	else if (!bo && row - 1 >= 0) return true;
	else return false;
}

bool Tree::move_right() {
	if (bo && row + 2 < 5) return true;
	else if (!bo && row + 1 < 5) return true;
	else return false;
}

bool Tree::move_down() {
	if (bo && col + 1 < 12) return true;
	else if (!bo && col + 2 < 12) return true;
	return false;
}


void Tree::left() {
	
	if (this->move_left()) {
		
		int temp = Array::arr[col][row];
		Array::arr[col][row] = 0;
		
		int i = 0;
		while (i < 4) {
			Array::arr[col + y[i]][row + x[i] - 1] = Array::arr[col + y[i]][row + x[i]];
			Array::arr[col + y[i]][row + x[i]] = 0;
			i++;
		}
		Array::arr[col][row] = temp;
		row--;
	}
}

void Tree::right() {

	if (this->move_right()) {

		int temp = Array::arr[col][row];
		Array::arr[col][row] = 0;

		int i = 0;
		while (i < 4) {
			Array::arr[col + y[i]][row + x[i] + 1] = Array::arr[col + y[i]][row + x[i]];
			Array::arr[col + y[i]][row + x[i]] = 0;
			i++;
		}
		Array::arr[col][row] = temp;
		row++;		
	}
}

bool Tree::down() {
	if (this->move_down()) {
		int temp = Array::arr[col][row];
		int i = 0;
		while (i < 4) {
			if (bo && i % 2 == 0) {
				Array::arr[col + y[i] + 1][row + x[i]] = Array::arr[col + y[i]][row + x[i]];
				Array::arr[col + y[i]][row + x[i]] = 0;
			}
			else if (!bo && i % 2 == 1) {
				Array::arr[col + y[i] + 1][row + x[i]] = Array::arr[col + y[i]][row + x[i]];
				Array::arr[col + y[i]][row + x[i]] = 0;
			}
			i++;
		}
		Array::arr[col+1][row] = temp;
		col++;
		return true;
	}
	return false;
}

bool Tree::rotate() {

	if (bo && col + 1 < 12) { //가로
		if (Array::arr[col + 1][row] == 0) {
			int i = 0;
			while (i < 4) {
				Array::arr[col + y[i + 1]][row + x[i + 1]] = Array::arr[col + y[i]][row + x[i]];
				Array::arr[col + y[i]][row + x[i]] = 0;
				i = i + 2;
			}
			bo = !bo;
			return true;
		}
	}

	else if (!bo && (row - 1 >= 0 && row + 1 < 5)) { //세로
		int i = 0;
		while (i < 4) {
			int i = 0;
			Array::arr[col + y[i]][row + x[i]] = Array::arr[col + y[i]-1][row + x[i]-1];
			Array::arr[col + y[i]-1][row + x[i]-1] = 0;
			i = i + 2;
		}
		bo = !bo;
		return true;
	}
	return false;
}