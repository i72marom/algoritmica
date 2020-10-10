#include "heapSort.h"

void ordenacionHeapSort() {
	vector<double> tiemposReales, ajuste(2);
	vector<double> nElementos, tEstimado;
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

	ajusteNlogN(nElementos, tiemposReales, ajuste);

	calcularTiemposEstimadosNlogN(nElementos, ajuste, tEstimado);
	
	escribeFichero(tiemposReales, tEstimado, nElementos);

	cout << "Coeficiente de determinacion: ";
	cout << calcularCoeficienteDeterminacion(tiemposReales, tEstimado);
	cout << endl;
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

		cout << nElementos.back() << " " << tiemposReales.back() << endl;
	}
}

void escribeFichero(vector<double> &tReal, vector<double> &tEstimado,
vector<double> &nElements) {
	ofstream f("../text/prueba.txt");

	for (int i = 0; i < nElements.size(); ++i) {
		f << nElements[i] << " " << tReal[i] << " " << tEstimado[i] << endl;
	}

	f.close();
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

	// Rellenar la matriz A
	A[0][0] = sumatorio(z, tiemposReales, 0, 0);
	A[0][1] = sumatorio(z, tiemposReales, 1, 0);
	A[1][0] = A[0][1];
	A[1][1] = sumatorio(z, tiemposReales, 2, 0);

	// Rellenar la matriz B.
	B[0][0] = sumatorio(z, tiemposReales, 0, 1);
	B[1][0] = sumatorio(z, tiemposReales, 1, 1);

	// Resolución del sistema de ecuaciones.
	resolverSistemaEcuaciones(A, B, 2, X);
	ajuste[0] = X[0][0];
	ajuste[1] = X[1][0];

	cout << "a0 : " << ajuste[0] << endl;
	cout << "a1 : " << ajuste[1] << endl;
}

double sumatorio(vector <double> &n, const vector <double> &t, int expN, int expT) {
	double sumatorio = 0;

	for (int i = 0; i < n.size(); ++i) 
		sumatorio += pow(n[i], expN) * pow(t[i], expT);

	return sumatorio;
}

void calcularTiemposEstimadosNlogN(const vector <double> &n,
const vector <double> &a, vector <double> &tiemposEstimados) {
	for (auto &i : n)
		tiemposEstimados.push_back(a[0] + a[1] * i * log(i));
}

double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales,
const vector <double> &tiemposEstimados) {
	double media_r = 0, media_e = 0, varianza_r = 0, varianza_e = 0;

	// calculo de la media
	for (int i = 0; i < tiemposReales.size(); ++i) {
		media_e += tiemposEstimados[i];
		media_r += tiemposReales[i];
	}

	media_r /= tiemposReales.size();
	media_e /= tiemposEstimados.size();

	// calculo de la varianza
	for (int i = 0; i < tiemposReales.size(); ++i) {
		varianza_e += pow(tiemposEstimados[i] - media_e, 2);
		varianza_r += pow(tiemposReales[i] - media_r, 2);
	}

	return varianza_e / varianza_r;
}
