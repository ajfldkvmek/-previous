#include "cross.h"
#include "array.h"

Cross::Cross(int c1, int c2, int c3, int c4, int c5) {
	Array::arr[1][3] = c1;
	Array::arr[1][1] = c2;
	Array::arr[2][2] = c3;
	Array::arr[0][2] = c4;
	Array::arr[1][2] = c5;
}

bool Cross::move_left() {
	if (row - 2 >= 0) return true;
	else return false;
}

bool Cross::move_right() {
	if (row + 1 < 5) return true;
	else return false;
}

bool Cross::move_down() {
	if (col + 2 < 12) return true;
	else return false;
}

void Cross::left() {
	if (this->move_left()) {
		int temp = Array::arr[col][row];
		int i = 0;
		while (i < 4) {
			Array::arr[col + y[i]][row + x[i] - 1] = Array::arr[col + y[i]][row + x[i]];
			Array::arr[col + y[i]][row + x[i]] = 0;
			i++;
		}
		Array::arr[col][row - 1] = temp;
		row--;
	}
}

void Cross::right() {
	if (this->move_right()) {
		int temp = Array::arr[col][row];
		int i = 0;
		while (i < 4) {
			Array::arr[col + y[i]][row + x[i] + 1] = Array::arr[col + y[i]][row + x[i]];
			Array::arr[col + y[i]][row + x[i]] = 0;
			i++;
		}
		Array::arr[col][row + 1] = temp;
		row--;
	}
}


bool Cross::down() {
	if (this->move_down()) {
		int temp = Array::arr[col][row];
		int i = 0;

		while (i < 4) {
			Array::arr[col + y[i] + 1][row + x[i]] = Array::arr[col + y[i]][row + x[i]];
			Array::arr[col + y[i]][row + x[i]] = 0;
			i++;
		}
		Array::arr[col + 1][row] = temp;
		col++;
		return true;
	}
	return false;
}

bool Cross::rotate() {
	int temp = Array::arr[col + y[3]][row + x[3]];
	int i = 3;

	while (i > 0) {
		Array::arr[col + y[i]][row + x[i]] = Array::arr[col + y[i - 1]][row + x[i - 1]];
		i--;
	}

	Array::arr[col][row + 1] = temp;
	return true;
}