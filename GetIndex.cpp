#pragma once
#include "include.h"

int GetIndex(List** Cur, int count) {
		int number;
		int index;
		int i = 0;
		if (count == 0) {
			count = 1;
		}
		for (i = 0; i < 10; i++) {
			std::cout << "\n ¬ведите индекс, из которого будет получен элемент\n";
			std::cin >> index;
			if ((index < 0) || (index > (count - 1))) {
				if (index < 0) {
					std::cout << "\n »ндекс должен быть не отрицательным\n";
				}
				else if (index > (count - 1)) {
					std::cout << "\n »ндекс не должен быть расположен после последнего индекса текущего списка\n";
				}
			}
			else {
				break;
			}
		}
		if (i == 10) {
			return 5;
		}
		else {
			if (index == 0) {
				number = (*Cur)->num;
				std::cout << "\n Ёлемент равен " << number << "\n";
			}
			else {
				for (i = index; i > 1; i--) {
					(*Cur) = (*Cur)->pNext;
				}
				number = (*Cur)->pNext->num;
				std::cout << "\n Ёлемент равен " << number << "\n";
			}
			return 1;
		}
}