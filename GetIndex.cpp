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
			std::cout << "\n ������� ������, �� �������� ����� ������� �������\n";
			std::cin >> index;
			if ((index < 0) || (index > (count - 1))) {
				if (index < 0) {
					std::cout << "\n ������ ������ ���� �� �������������\n";
				}
				else if (index > (count - 1)) {
					std::cout << "\n ������ �� ������ ���� ���������� ����� ���������� ������� �������� ������\n";
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
				std::cout << "\n ������� ����� " << number << "\n";
			}
			else {
				for (i = index; i > 1; i--) {
					(*Cur) = (*Cur)->pNext;
				}
				number = (*Cur)->pNext->num;
				std::cout << "\n ������� ����� " << number << "\n";
			}
			return 1;
		}
}