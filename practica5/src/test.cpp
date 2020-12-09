#include "medio_nivel.hpp"

int main() {
	int opt;

	do {
		std::cout << " 1. Backtraking." << std::endl;
		std::cout << " 2. N Queens." << std::endl;
		std::cout << " 0. Exit." << std::endl;
		std::cout << "Select an option: ";
		std::cin >> opt;

		switch (opt) {
			case 1:
				traveling_salesman_backtraking_algorithm();
				break;
			case 2:
				nReinas();
				break;
			case 0:
				break;
			default:
				std::cout << "Incorrect option" << std::endl;
		}

	} while (opt != 0);
}
