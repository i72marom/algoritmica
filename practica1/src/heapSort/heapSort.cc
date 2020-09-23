#include "heapSort.h"

void ordenacionHeapSort() {
	std::vector<double> tiemposReales;
	std::vector<int> nElementos;
	int max, min, incremento, rep, size;

	std::cout << "Número mínimo de elementos: ";
	std::cin >> min;
	std::cout << "Número máximo de elementos: ";
	std::cin >> max;
	std::cout << "Incremento: ";
	std::cin >> incremento;
	std::cout << "Numero de repeticiones: ";
	std::cin >> rep;

	size = (max-min)/incremento;
	tiemposReales.resize(size);
	nElementos.resize(size);

	tiemposOrdenacionHeapSort(min, max, rep, incremento, tiemposReales, nElementos);
}

bool heapSort(std::vector<int> &v) {
	make_heap(v.begin(), v.end());
	sort_heap(v.begin(), v.end());

	return estaOrdenado(v);
}

bool estaOrdenado(const std::vector<int> &v) {
	for (const auto &i : v) 
		if (i > i+1) return false;

	return true;
}

void rellenarVector(std::vector<int> &v) {
	for (auto &i : v) i = rand() % 10000000;
}

void tiemposOrdenacionHeapSort(int min, int max, int rep, int incremento,
	std::vector<double> &tiemposReales, std::vector<int> &nElementos) {
	std::vector<int> heap;

	for (int i = min; i <= max; i += incremento) {
		heap.resize(i);
		rellenarVector(heap);
		if (heapSort(heap)) std::cout << "true" << std::endl;
		else std::cout << "false" << std::endl;
	}
}
