#pragma once
#include "include.h"

int PutListIndex(std::fstream& g, List** Cur, int count, List** Cur2) {
	g.open("out.txt", std::ios::app);
	if (g.is_open()) {
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
		for (i = 0; i < 10; i++) {
			std::cout << "\n ������� ������, � �������� ����� �������� ������ ������\n";
			std::cin >> index;
			if ((index < 0) || (index > count)) {
				if (index < 0) {
					std::cout << "\n ������ ������ ���� �� �������������\n";
				}
				else if (index > count) {
					std::cout << "\n ������ �� ������ ���� ���������� ����� ������� ������� �� ������ ������������ ������\n";
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
				List* Tmp = *Cur;
				List* Head2 = new List;
				*Cur = Head2;
				do {
					(*Cur)->num = (*Cur2)->num;
					if ((*Cur2)->pNext != NULL) {
						(*Cur)->pNext = new List;
						(*Cur) = (*Cur)->pNext;
						(*Cur2) = (*Cur2)->pNext;
					}
				} while ((*Cur2)->pNext != NULL);
				(*Cur)->num = (*Cur2)->num;
				if (k == 0) {
					(*Cur)->pNext = NULL;
					delete Tmp;
				}
				else {
					(*Cur)->pNext = Tmp;
				}
				(*Cur) = Head2;
				g << "\n\n��������� ������� 13\n���������� ������:\n\n";
				g.close();
				return 3;
			}

			else if (index == count) {
				List* Tmp = *Cur;
				for (int i = index; i > 1; i--) {
					(*Cur) = (*Cur)->pNext;
				}
				(*Cur)->pNext = new List;			
				*Cur = (*Cur)->pNext;
				List* Head = *Cur;
				do {
					(*Cur)->num = (*Cur2)->num;
					if ((*Cur2)->pNext != NULL) {
						(*Cur)->pNext = new List;
						(*Cur) = (*Cur)->pNext;
						(*Cur2) = (*Cur2)->pNext;
					}
				} while ((*Cur2)->pNext != NULL);
				(*Cur)->num = (*Cur2)->num;
				(*Cur)->pNext = NULL;
				if (k == 0) {
					(*Cur) = Head;
					delete Tmp;
					g << "\n\n��������� ������� 13\n���������� ������:\n\n";
					g.close();
					return 3;
				}
				g << "\n\n��������� ������� 13\n���������� ������:\n\n";
				g.close();
				return 1;
			}

			else {
				for (int i = index; i > 1; i--) {
					(*Cur) = (*Cur)->pNext;
				}
				List* Tmp = (*Cur)->pNext;
				List* Head2 = new List;
				(*Cur)->pNext = Head2;
				(*Cur) = (*Cur)->pNext;
				do {
					(*Cur)->num = (*Cur2)->num;
					if ((*Cur2)->pNext != NULL) {
						(*Cur)->pNext = new List;
						(*Cur) = (*Cur)->pNext;
						(*Cur2) = (*Cur2)->pNext;
					}
				} while ((*Cur2)->pNext != NULL);
				(*Cur)->num = (*Cur2)->num;
				(*Cur)->pNext = Tmp;
				g << "\n\n��������� ������� 13\n���������� ������:\n\n";
				g.close();
				return 1;
			}
		}
		
	}
	else {
		return 2;
	}
}