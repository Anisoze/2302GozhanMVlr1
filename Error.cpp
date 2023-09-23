#pragma once
#include "include.h"

void Error(std::fstream& g, int res) {
	if (res == 2) {
		std::cout << "\n Ошибка файл не был открыт\n";
	}
	else {
		g.open("out.txt", std::ios::app);
		if (g.is_open()) {
			if (res == 5) {
				std::cout << "\n\n Ошибка, индекс был введен неверно слишком много раз\n";
			}
			else if (res == 0) {
				g << "\nОшибка, in.txt не был открыт\n";
				std::cout << "\n Ошибка, in.txt не был открыт\n";
			}
		}
	}
	
	
}