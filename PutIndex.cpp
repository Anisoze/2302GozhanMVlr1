#pragma once
#include "include.h"

int PutIndex(std::fstream& g, List** Cur, int count) {
	g.open("out.txt", std::ios::app);
	if (g.is_open()) {
		int number;
		int index;
		int i = 0;
		int k;
		if (count == 0) {
			k = 0;
		}
		else {
			k = 1;
		}
		if (count == 0) {
			count = 1;
		}
		std::cout << "\n ������� ����������� �������\n";
		std::cin >> number;
		for (i = 0; i < 10;i++) {
			std::cout << "\n ������� ������, �� �������� ����� ���������� �������\n";
			std::cin >> index;
			if ((index < 0) || (index > (count - 1))) {
				if (index < 0) {
					std::cout << "\n ������ ������ ���� �� �������������\n";
				}
				else if (index > (count - 1)){
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
				if (k == 1) {
					List* Tmp = new List;
					Tmp->num = number;
					Tmp->pNext = (*Cur);
					*Cur = Tmp;
				}
				else {
					(*Cur)->num = number;
				}
				g << "\n\n��������� ������� 5\n���������� ������:\n\n";
				g.close();
				return 3;
			}
			else {
				List* Tmp = new List;
				Tmp->num = number;
				for (i = index; i > 1; i--) {
					(*Cur) = (*Cur)->pNext;
				}
				Tmp->pNext = (*Cur)->pNext;
				(*Cur)->pNext = Tmp;
				g << "\n\n��������� ������� 5\n���������� ������:\n\n";
				g.close();
				return 1;
			}
		}
	}
	else {
		return 2;
	}
}