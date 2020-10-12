#include "heapSort.h"

void ordenacionHeapSort() {
	vector<double> tiemposReales, ajuste(2);
	vector<double> nElementos, tEstimado;
	int max, min, incremento, rep;
	long n_estimado = -1;

	cout << "Número mínimo de elementos: ";
	cin >> min;
	cout << "Número máximo de elementos: ";
	cin >> max;
	cout << "Incremento: ";
	cin >> incremento;
	cout << "Numero de repeticiones: ";
	cin >> rep;

	tiemposOrdenacionHeapSort(min, max, rep, incremento, tiemposReales, nElementos);

	ajusteNlogN(nElementos, tiemposReales, ajuste);

	calcularTiemposEstimadosNlogN(nElementos, ajuste, tEstimado);
	
	escribeFichero(tiemposReales, tEstimado, nElementos, "../text/nlogn.txt");

	cout << "Ecuación ajustada: ";
	cout << ajuste[0] << " + " << ajuste[1] << " * NlogN";
	cout << endl;

	cout << "Coeficiente de determinacion: ";
	cout << calcularCoeficienteDeterminacion(tiemposReales, tEstimado);
	cout << endl;

	while (n_estimado != 0) {
		cout << "Tamaño de la muestra a estimar (0 para salir): ";
		cin >> n_estimado;

		if (n_estimado > 0)
			microsegundosADias(calcularTiempoEstimadoNlogN(n_estimado, ajuste));
	}
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
	vector<double> &tiemposReales, vector<double> &nElementos) {
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

		media_tiempo = 0;

		cout << nElementos.back() << " " << tiemposReales.back() << endl;
	}
}

void ajusteNlogN(const vector <double> &n, const vector <double> &tiemposReales,
	vector <double> &ajuste) {

	// z = n*log(n): cambio de variable para facilitar el ajuste
	vector<double> z;
	for (auto &it : n) z.push_back(it * log(it));

	// Declaración de matrices
	// A: Matriz de coeficientes.
	// X: Matriz de incognitas (a0 y a1).
	// B: Matriz de terminos independientes.
	vector <vector <double>> A(2, vector <double>(2));
	vector <vector <double>> X(2, vector <double>(1));
	vector <vector <double>> B(2, vector <double>(1));

	// Rellenar las matrices A y B
	rellenaA(A, tiemposReales, z);
	rellenaB(B, tiemposReales, z);

	// Resolución del sistema de ecuaciones.
	resolverSistemaEcuaciones(A, B, 2, X);
	ajuste[0] = X[0][0];
	ajuste[1] = X[1][0];
}

void calcularTiemposEstimadosNlogN(const vector <double> &n,
const vector <double> &a, vector <double> &tiemposEstimados) {
	for (auto &i : n)
		tiemposEstimados.push_back(a[0] + a[1] * i * log(i));
}

double calcularTiempoEstimadoNlogN(const double &n, vector <double> &a) {
	return a[0] + a[1] * n * log(n);
}
