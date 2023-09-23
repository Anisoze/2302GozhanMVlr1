#pragma once
#include <fstream>
#include "include.h"

int Read(std::fstream& f, int* count, List** Cur) {
	if (f.is_open()) {
		int tmp = -9999;
		f >> tmp;
		if (f.eof() && tmp != -9999) {
			(*count)++;
			(*Cur)->num = tmp;
			(*Cur)->pNext = NULL;
		}
		if (!f.eof()) {
			(*count)++;
			(*Cur)->num = tmp;
			tmp = -9999;
			f >> tmp;
			if (tmp != -9999) {
				do {
					(*Cur)->pNext = new List;
					(*Cur) = (*Cur)->pNext;
					(*Cur)->pNext = NULL;
					(*count)++;
					(*Cur)->num = tmp;
					tmp = -9999;
					f >> tmp;
					if (f.eof() && tmp != -9999) {
						(*Cur)->pNext = new List;
						(*Cur) = (*Cur)->pNext;
						(*Cur)->pNext = NULL;
						(*count)++;
						(*Cur)->num = tmp;
					}
				} while (!f.eof());
			}
		}	
		return 1;	
	}
	else {
		return 0;
	}
}