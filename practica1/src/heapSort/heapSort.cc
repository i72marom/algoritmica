#include "heapSort.h"

void ordenacionHeapSort() {
	std::vector<double> tiemposReales;
	std::vector<int> nElementos;
	int max, min, incremento, rep;

	std::cout << "Número mínimo de elementos: ";
	std::cin >> min;
	std::cout << "Número máximo de elementos: ";
	std::cin >> max;
	std::cout << "Incremento: ";
	std::cin >> incremento;
	std::cout << "Numero de repeticiones: ";
	std::cin >> rep;

	tiemposOrdenacionHeapSort(min, max, rep, incremento, tiemposReales, nElementos);
}

bool heapSort(std::vector<int> &v) {
	make_heap(v.begin(), v.end());
	sort_heap(v.begin(), v.end());

	return true;
	// return estaOrdenado(v);
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
	Clock Tiempo;
	double media_tiempo = 0;

	for (int i = min; i <= max; i += incremento) {
		for (int j = 0; j < rep; ++j) {
			heap.resize(i);
			rellenarVector(heap);

			Tiempo.start();
			heapSort(heap);

			if (Tiempo.isStarted()) {
				Tiempo.stop();
				media_tiempo += Tiempo.elapsed();
			}
		}

		tiemposReales.push_back(media_tiempo/rep);
		nElementos.push_back(i);
	}
}
