#include <iostream>
#include <ctime>

#include "array_2d.h"
#include "tree_block.h"
#include "fold_block.h"
#include "cross_block.h"

int main() {	
	srand((unsigned int)time(0));
	array_2d *map = new array_2d();
	while (true) {
		big_block* bb;
		int randBB = (rand() % 3) + 1;

		if (!map->can_make(randBB)) {
			break;
		}
		if (randBB == 1) {
			bb = new tree_block();
			map->set_BlockLocation(bb, 2, 0);

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
					map->explosion();
					break;
				}
				fflush(stdin);
				map->print();

				char input = getchar();
				char trash = getchar();
				std::cout << std::endl;

				map->move(bb, input);
			}
		}
		else if (randBB == 2) {
			bb = new fold_block();
			map->set_BlockLocation(bb, 2, 0);

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
					map->explosion();
					break;
				}
				fflush(stdin);
				map->print();
				
				char input = getchar();
				char trash = getchar();
				std::cout << std::endl;

				map->move(bb, input);
			}
		}
		else if (randBB == 3) {
			bb = new cross_block;
			map->set_BlockLocation(bb, 2, 0);

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
					map->explosion();
					break;
				}
				fflush(stdin);
				map->print();

				char input = getchar();
				char trash = getchar();
				std::cout << std::endl;

				map->move(bb, input);
			}
		}
	}
	map->print();
	std::cout << "\n\nScore : " << map->get_score() << "!!" << std::endl;
	std::cout << "Press and button to end" << std::endl;
	int endB = getchar();
}
