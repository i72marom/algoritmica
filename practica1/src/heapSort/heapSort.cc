#include "heapSort.h"

void ordenacionHeapSort() {
	vector<double> tiemposReales;
	vector<int> nElementos;
	int max, min, incremento, rep;

	cout << "Número mínimo de elementos: ";
	cin >> min;
	cout << "Número máximo de elementos: ";
	cin >> max;
	cout << "Incremento: ";
	cin >> incremento;
	cout << "Numero de repeticiones: ";
	cin >> rep;

	tiemposOrdenacionHeapSort(min, max, rep, incremento, tiemposReales, nElementos);

	escribeFichero(tiemposReales, nElementos);
}

bool heapSort(vector<int> &v) {
	make_heap(v.begin(), v.end());
	sort_heap(v.begin(), v.end());

	return true;
	// return estaOrdenado(v);
}

bool estaOrdenado(const vector<int> &v) {
	for (const auto &i : v) 
		if (i > i+1) return false;

	return true;
}

void rellenarVector(vector<int> &v) {
	for (auto &i : v) i = rand() % 10000000;
}

void tiemposOrdenacionHeapSort(int min, int max, int rep, int incremento,
	vector<double> &tiemposReales, vector<int> &nElementos) {
	vector<int> heap;
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

void escribeFichero(vector<double> &time, vector<int> &nElements) {
	auto it_nElements = nElements.begin();
	ofstream f("../text/prueba.txt");

	for (auto &it_tiempos : time) {
		f << *it_nElements << " : " << it_tiempos << endl;
		it_nElements++;
	}

	f.close();
}
