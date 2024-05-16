#include "block.h"

Block::Block() {
	row = 2; //x
	col = 1; //y
	block_check = false;
}

bool Block::merge() {
	if (!move_down()) block_check = true;
	return block_check;
}