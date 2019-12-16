#include "array_2d.h"

array_2d::array_2d() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 5; j++) {
			this->block_array[i][j] = new block(' ',i,j);
		}
	}

	this->score = 0;
}

// 1: tree 2: fold 3: cross
bool array_2d::can_make(int type) {
	if (type == 1) {
		if (this->block_array[0][2]->get_color() == ' ' &&
			this->block_array[1][2]->get_color() == ' ' &&
			this->block_array[2][2]->get_color() == ' ') {
			return true;
		}
	}
	else if (type == 2) {
		if (this->block_array[0][2]->get_color() == ' ' &&
			this->block_array[1][1]->get_color() == ' ' &&
			this->block_array[1][2]->get_color() == ' ') {
			return true;
		}
	}
	else if (type == 3) {
		if (this->block_array[0][2]->get_color() == ' ' &&
			this->block_array[1][1]->get_color() == ' ' &&
			this->block_array[1][2]->get_color() == ' ' &&
			this->block_array[1][3]->get_color() == ' ' &&
			this->block_array[2][2]->get_color() == ' ') {
			return true;
		}
	}
	return false;
}

void array_2d::print() {
	std::cout << "score: " << this->score << std::endl;
	std::cout << "----------" << std::endl;
	for (int i = 0; i < 12; i++) {
		std::cout << "|";
		for (int j = 0; j < 5; j++) {
			std::cout << this->block_array[i][j]->get_color();
			std::cout << "|";
		}
		std::cout << std::endl;
	}
	std::cout << "----------" << std::endl;
}

void array_2d::move(big_block* bb, char input) {
	int pre_x = bb->get_x();
	int pre_y = bb->get_y();

	if (input == 'a') {
		if (bb->get_y() <= 0) {
			return;
		}

		if (bb->get_y()-1>0) {
			if (this->block_array[bb->get_x()][bb->get_y()-2]->get_color() == ' ') {
				bb->move('a');
			}
			
		}
		else {
			if (!bb->is_block(1, 0)) {
				bb->move('a');
			}
		}
	}
	else if (input == 'd') {
		if (bb->get_y() >= 4) {
			return;
		}

		if (bb->get_y()+1<4) {
			if (this->block_array[bb->get_x()][bb->get_y()+2]->get_color() == ' ') {
				bb->move('d');
			}
		}
		else {
			if (!bb->is_block(1, 2)) {
				bb->move('d');
			}
		}
	}
	else if (input == 's') {
		for (int i = 2; i >= 0; i--) {
			for (int j = 0; j < 3; j++) {
				if (bb->get_block(i, j)->get_color() != ' ') {
					if (i < 2) {
						if (bb->get_block(i + 1, j)->get_color() == ' ') {
							if (bb->get_block(i, j)->get_x() + 1 < 12) {
								if (this->block_array[bb->get_block(i, j)->get_x() + 1][bb->get_block(i, j)->get_y()]->get_color() != ' ') {
									for (int k = 0; k < 3; k++) {
										bb->get_block(k, j)->set_downable(false);
									}
								}
							}
							else {
								for (int k = 0; k < 3; k++) {
									bb->get_block(k, j)->set_downable(false);
								}
							}
						}
					}
					else {
						if (bb->get_block(i, j)->get_x() + 1 < 12) {
							if (this->block_array[bb->get_block(i, j)->get_x() + 1][bb->get_block(i, j)->get_y()]->get_color() != ' ') {
								for (int k = 0; k < 3; k++) {
									bb->get_block(k, j)->set_downable(false);
								}
							}
						}
						else {
							for (int k = 0; k < 3; k++) {
								bb->get_block(k, j)->set_downable(false);
							}
						}
					}
					if (bb->get_block(i, j)->get_x() >= 11) {
						bb->get_block(i, j)->set_downable(false);
					}
				}
			}
		}
		if (bb->get_x() < 11) {
			bb->move('s');
		}
	}
	else if (input == 'e') {
		this->delete_block(bb);
		bool flag = true;
		if(bb->get_y() == 4) {
			if (bb->get_block(1, 0)->get_color() != ' ') {
				if (bb->get_block(0, 1)->get_color() != ' ') {
					bb->move('a');
				}
			}
			else {
				if (this->block_array[bb->get_x()][bb->get_y() - 2]->get_color() != ' ') {
					flag = false;
				}
				else {
					bb->move('a');
				}
			}
		}
		else if (bb->get_y() == 0) {
			if (bb->get_block(1, 2)->get_color() != ' ') {
				if (bb->get_block(2, 1)->get_color() != ' ') {
					bb->move('d');
				}
			}
			else {
				if (this->block_array[bb->get_x()][bb->get_y() + 2]->get_color() != ' ') {
					flag = false;
				}
				else {
					bb->move('d');
				}
			}
		}
		else if (bb->get_y() < 4 && bb->get_y() > 0) {
			if (bb->get_block(1, 2)->get_color() == ' ' && 
				this->block_array[bb->get_x()][bb->get_y()+1]->get_color() != ' ') {
				if (bb->get_block(1, 0)->get_color() != ' ') {
					if (bb->get_block(0, 1)->get_color() != ' ') {
						bb->move('a');
					}
				}
				else {
					if (this->block_array[bb->get_x()][bb->get_y() - 2]->get_color() != ' ') {
						flag = false;
					}
					else {
						bb->move('a');
					}
				}
			}
			else if (bb->get_block(1, 0)->get_color() == ' ' &&
				this->block_array[bb->get_x()][bb->get_y() - 1]->get_color() != ' ') {
				if (bb->get_block(1, 2)->get_color() != ' ') {
					if (bb->get_block(2, 1)->get_color() != ' ') {
						bb->move('d');
					}
				}
				else {
					if (this->block_array[bb->get_x()][bb->get_y() + 2]->get_color() != ' ') {
						flag = false;
					}
					else {
						bb->move('d');
					}
				}
			}
			else {
				if (bb->get_block(1, 2)->get_color() == ' ' &&
					this->block_array[bb->get_x()][bb->get_y() + 1]->get_color() != ' ') {
					flag = false;
				}
				if (bb->get_block(2, 1)->get_color() == ' ' &&
					this->block_array[bb->get_x() + 1][bb->get_y()]->get_color() != ' ') {
					flag = false;
				}
				if (bb->get_block(1, 0)->get_color() == ' ' &&
					this->block_array[bb->get_x()][bb->get_y() - 1]->get_color() != ' ') {
					flag = false;
				}
			}
		}

		if (flag) {
			bb->rotate();
		}
		this->set_BlockLocation(bb, pre_x, pre_y);
	}
	else if (input == 'x') {
		while (true) {
			bool flag = false;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (bb->get_block(i, j)->get_color() != ' ' && bb->get_block(i, j)->get_downable()) {
						flag = true;
					}
				}
			}
			if (!flag) {
				break;
			}
			this->move(bb, 's');
		}
	}
	else {
		return;
	}
	this->set_BlockLocation(bb, pre_x, pre_y);
}

int array_2d::get_score() {
	return this->score;
}

block* array_2d::get_block(int x, int y) {
	return this->block_array[x][y];
}

void array_2d::set_BlockLocation(big_block* bb, int pre_x, int pre_y) {
	if (bb->is_block(0, 0) && bb->get_block(0 ,0)->get_downable()) {
		this->block_array[pre_x - 1][pre_y - 1]->set_color(' ');
	}
	if (bb->is_block(0, 1) && bb->get_block(0, 1)->get_downable()) {
		this->block_array[pre_x-1][pre_y]->set_color(' ');
	}
	if (bb->is_block(0, 2) && bb->get_block(0, 2)->get_downable()) {
		this->block_array[pre_x - 1][pre_y + 1]->set_color(' ');
	}
	if (bb->is_block(1, 0) && bb->get_block(1, 0)->get_downable()) {
		this->block_array[pre_x][pre_y-1]->set_color(' ');
	}
	if (bb->is_block(1, 1) && bb->get_block(1, 1)->get_downable()) {
		this->block_array[pre_x][pre_y]->set_color(' ');
	}
	if (bb->is_block(1, 2) && bb->get_block(1, 2)->get_downable()) {
		this->block_array[pre_x][pre_y+1]->set_color(' ');
	}

	if (pre_x < 11) {
		if (bb->is_block(2, 0) && bb->get_block(2, 0)->get_downable()) {
			this->block_array[pre_x + 1][pre_y - 1]->set_color(' ');
		}
		if (bb->is_block(2, 1) && bb->get_block(2, 1)->get_downable()) {
			this->block_array[pre_x + 1][pre_y]->set_color(' ');
		}
		if (bb->is_block(2, 2) && bb->get_block(2, 2)->get_downable()) {
			this->block_array[pre_x + 1][pre_y + 1]->set_color(' ');
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (bb->get_block(i, j)->get_color() != ' ') {
				this->block_array[bb->get_block(i, j)->get_x()][bb->get_block(i, j)->get_y()]
					->set_color(bb->get_block(i, j)->get_color());
			}
		}
	}
}

void array_2d::delete_block(big_block* bb) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (bb->get_block(i, j)->get_color() != ' ') {
				this->block_array[bb->get_block(i, j)->get_x()][bb->get_block(i, j)->get_y()]->set_color(' ');
			}
		}
	}
}

void array_2d::explosion() {
	bool flag = false;
	for (int i = 11; i >= 1; i--) {
		for (int j = 0; j < 5; j++) {
			if (!(this->block_array[i][j]->get_color() == ' ' || this->block_array[i][j]->get_color() == 'N')) {
				if (j < 4) {
					if (this->block_array[i][j]->get_color() == this->block_array[i][j + 1]->get_color()) {
						if (*this->block_array[i][j]->getGroup() < *this->block_array[i][j + 1]->getGroup()) {
							this->block_array[i][j]->setGroup(this->block_array[i][j + 1]->getGroup());
							this->block_array[i][j + 1]->addGroup();
						}
						else {
							this->block_array[i][j + 1]->setGroup(this->block_array[i][j]->getGroup());
							this->block_array[i][j]->addGroup();
						}
					}
				}

				 
				if (this->block_array[i][j]->get_color() == this->block_array[i-1][j]->get_color()) {
					this->block_array[i - 1][j]->setGroup(this->block_array[i][j]->getGroup());
					this->block_array[i][j]->addGroup();
				}
				
			}
		}
	}

	for (int i = 11; i >= 0; i--) {
		for (int j = 0; j < 5; j++) {
			if (*this->block_array[i][j]->getGroup() > 3) {
				this->block_array[i][j]->set_color(' ');
				this->NBom(i, j);
				flag = true;
			}
		}
	}
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 5; j++) {
			this->block_array[i][j]->reset();
		}
	}
	
	if (flag) {
		this->score = this->score + 1;
		for (int i = 0; i < 11; i++) {
			this->gravity();
		}
		this->explosion();
	}
}

void array_2d::gravity() {
	for (int i = 10; i >= 0; i--) {
		for (int j = 0; j < 5; j++) {
			if (this->block_array[i + 1][j]->get_color() == ' ') {
				this->block_array[i + 1][j]->set_color(this->block_array[i][j]->get_color());
				this->block_array[i][j]->set_color(' ');
			}
		}
	}
}

void array_2d::NBom(int i, int j) {
	if (i > 0) {
		if (this->block_array[i - 1][j]->get_color() == 'N') {
			this->block_array[i - 1][j]->set_color(' ');
			NBom(i - 1, j);
		}
	}
	if (j > 0) {
		if (this->block_array[i][j - 1]->get_color() == 'N') {
			this->block_array[i][j - 1]->set_color(' ');
			NBom(i, j - 1);
		}
	}
	if (j < 4) {
		if (this->block_array[i][j + 1]->get_color() == 'N') {
			this->block_array[i][j + 1]->set_color(' ');
			NBom(i, j + 1);
		}
	}
	if (i < 11) {
		if (this->block_array[i + 1][j]->get_color() == 'N') {
			this->block_array[i + 1][j]->set_color(' ');
			NBom(i + 1, j);
		}
	}
}
