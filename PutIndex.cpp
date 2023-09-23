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
		std::cout << "\n Введите добавляемый элемент\n";
		std::cin >> number;
		for (i = 0; i < 10;i++) {
			std::cout << "\n Введите индекс, по которому будет расположен элемент\n";
			std::cin >> index;
			if ((index < 0) || (index > (count - 1))) {
				if (index < 0) {
					std::cout << "\n Индекс должен быть не отрицательным\n";
				}
				else if (index > (count - 1)){
					std::cout << "\n Индекс не должен быть расположен после последнего индекса текущего списка\n";
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
				g << "\n\nВыполение функции 5\nОбновлённый список:\n\n";
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
				g << "\n\nВыполение функции 5\nОбновлённый список:\n\n";
				g.close();
				return 1;
			}
		}
	}
	else {
		return 2;
	}
}