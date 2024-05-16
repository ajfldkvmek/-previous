#include "block.h"

class Tree : public Block {
private: 
	bool bo = false;

public:
	Tree(int t1, int t2, int t3);

	bool move_left();
	bool move_right();
	bool move_down();

	void left();
	void right();
	bool down();

	bool dest();
	bool rotate();
};