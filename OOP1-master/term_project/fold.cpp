#include "fold.h"
#include "array.h"

Fold::Fold(int f1, int f2, int f3) {
	state = 0;

	Array::arr[1][2] = f1;
	Array::arr[0][2] = f2;
	Array::arr[1][3] = f3;
}

bool Fold::move_left() {
	if (state == 0 && row - 2 >= 0) return true;
	else if (state == 1 && row -2 >= 0) return true;
	else if (state == 2 && row - 1 >= 0) return true;
	else if (state == 3 && row - 2 >= 0) return true;
	else return false;
}

bool Fold::move_right() {
	if (state == 0 && row + 1 < 5 ) return true;
	else if (state == 1 && row + 1 < 5) return true;
	else if (state == 2 && row + 1 < 5) return true;
	else if (state == 3 && row + 1 < 5) return true;
	else return false;
}

bool Fold::move_down() {
	if (state == 0 && col + 1 < 12) return true;
	else if (state == 1 && col < 12) return true;
	else if (state == 2 && col < 12) return true;
	else if (state == 3 && col + 1 < 12) return true;
	else return false;
}

void Fold::left() {
	if (move_left()) {
		int temp = Array::arr[col][row];
		
		int i = 0;

		while (i < 4) {

			if (state == 0 && (i == 0 || i == 3)) {
				Array::arr[col + y[i]][row + x[i] - 1] = Array::arr[col + y[i]][row + x[i]];
				Array::arr[col + y[i]][row + x[i]] = 0;
			}
			else if (state == 1 && (i == 0 || i == 1)) {
				Array::arr[col + y[i]][row + x[i] - 1] = Array::arr[col + y[i]][row + x[i]];
				Array::arr[col + y[i]][row + x[i]] = 0;
			}
			else if (state == 2 && (i == 1 || i == 2)) {
				Array::arr[col + y[i]][row + x[i] - 1] = Array::arr[col + y[i]][row + x[i]];
				Array::arr[col + y[i]][row + x[i]] = 0;
			}
			else if (state == 3 && (i == 2 || i == 3)) {
				Array::arr[col + y[i]][row + x[i] - 1] = Array::arr[col + y[i]][row + x[i]];
				Array::arr[col + y[i]][row + x[i]] = 0;
			}
			i++;
		}
		Array::arr[col][row - 1] = temp;
		row--;
	}
}

void Fold::right() {
	if (move_right()) {
		int temp = Array::arr[col][row];

		int i = 0;

		while (i < 4) {

			if (state == 0 && (i == 0 || i == 3)) {
				Array::arr[col + y[i]][row + x[i] + 1] = Array::arr[col + y[i]][row + x[i]];
				Array::arr[col + y[i]][row + x[i]] = 0;
			}
			else if (state == 1 && (i == 0 || i == 1)) {
				Array::arr[col + y[i]][row + x[i] + 1] = Array::arr[col + y[i]][row + x[i]];
				Array::arr[col + y[i]][row + x[i]] = 0;
			}
			else if (state == 2 && (i == 1 || i == 2)) {
				Array::arr[col + y[i]][row + x[i] + 1] = Array::arr[col + y[i]][row + x[i]];
				Array::arr[col + y[i]][row + x[i]] = 0;
			}
			else if (state == 3 && (i == 2 || i == 3)) {
				Array::arr[col + y[i]][row + x[i] + 1] = Array::arr[col + y[i]][row + x[i]];
				Array::arr[col + y[i]][row + x[i]] = 0;
			}
			i++;
		}
		Array::arr[col][row - 1] = temp;
		row++;
	}
}

bool Fold::down() {
	if (move_down()) {
		int temp = Array::arr[col][row];
		Array::arr[col][row] = 0;

		int i = 0;
		while (i < 4) {

			if (state == 0 && (i == 0 || i == 3)) {
				Array::arr[col + y[i] + 1][row + x[i]] = Array::arr[col + y[i]][row + x[i]];
				Array::arr[col + y[i]][row + x[i]] = 0;
			}
			else if (state == 1 && (i == 0 || i == 1)) {
				Array::arr[col + y[i] + 1][row + x[i]] = Array::arr[col + y[i]][row + x[i]];
				Array::arr[col + y[i]][row + x[i]] = 0;
			}
			else if (state == 2 && (i == 1 || i == 2)) {
				Array::arr[col + y[i] + 1][row + x[i]] = Array::arr[col + y[i]][row + x[i]];
				Array::arr[col + y[i]][row + x[i]] = 0;
			}
			else if (state == 3 && (i == 2 || i == 3)) {
				Array::arr[col + y[i] + 1][row + x[i]] = Array::arr[col + y[i]][row + x[i]];
				Array::arr[col + y[i]][row + x[i]] = 0;
			}
			i++;
		}
		Array::arr[col + 1][row] = temp;
		col++;
		return true;
	}
	return false;
}

bool Fold::rotate() {
	if (state == 0 && Array::arr[col + 1][row] == 0) {
		Array::arr[col + 1][row] = Array::arr[col][row + 1];
		Array::arr[col + y[0]][row + x[0]] = Array::arr[col + y[3]][row + x[3]];
		Array::arr[col + y[3]][row + x[3]] = 0;
		state++;
		return true;
	}
	else if (state == 1 && row - 1 >= 0 && Array::arr[col][row - 1] == 0) {
		Array::arr[col + y[2]][row + x[2]] = Array::arr[col + y[1]][row + x[1]];
		Array::arr[col + y[1]][row + x[1]] = Array::arr[col + y[0]][row + x[0]];
		Array::arr[col + y[0]][row + x[0]] = 0;
		state++;
		return true;
	}
	else if (state == 2) {
		Array::arr[col + y[3]][row + x[3]] = Array::arr[col + y[2]][row + x[2]];
		Array::arr[col + y[2]][row + x[2]] = Array::arr[col + y[1]][row + x[1]];
		Array::arr[col + y[1]][row + x[1]] = 0;
		state++;
		return true;
	}
	else if (state == 3 && row + 1 < 5 && Array::arr[col][row + 1] == 0) {
		Array::arr[col + y[0]][row + x[0]] = Array::arr[col + y[3]][row + x[3]];
		Array::arr[col + y[3]][row + x[3]] = Array::arr[col + y[2]][row + x[2]];
		Array::arr[col + y[2]][row + x[2]] = 0;
		state = (state + 1) % 4;
		return true;
	}
	return false;
}