#include "determinanteRecursivo.h"

void determinanteRecursivo() {
	vector<double> tiemposReales, ajuste(2);
	vector<double> nElementos, tEstimado;
	int max, min, incremento;
	long n_estimado = -1;

	cout << "Número mínimo de elementos: ";
	cin >> min;
	cout << "Número máximo de elementos: ";
	cin >> max;
	cout << "Incremento: ";
	cin >> incremento;

	tiempoDeterminanteRecursivo(min, max, incremento, tiemposReales, nElementos);

	ajusteRecursivo(nElementos, tiemposReales, ajuste);

	calcularTiemposEstimadosRecursivo(nElementos, ajuste, tEstimado);
	
	escribeFichero(tiemposReales, tEstimado, nElementos, "../text/recursivo.txt");

	cout << "Ecuación ajustada: ";
	cout << ajuste[0] << " + ";
	cout << ajuste[1] << " * n! ";
	cout << endl;

	cout << "Coeficiente de determinacion: ";
	cout << calcularCoeficienteDeterminacion(tiemposReales, tEstimado);
	cout << endl;

	while (n_estimado != 0) {
		cout << "Tamaño de la muestra a estimar (0 para salir): ";
		cin >> n_estimado;

		if (n_estimado > 0)
			microsegundosADias(calcularTiempoEstimadoRecursivo(n_estimado, ajuste));
	}
}

void tiempoDeterminanteRecursivo(int min, int max, int incremento,
vector<double> &tiemposReales, vector<double> &nElementos) {
	vector<vector <double>> M;
	Clock Tiempo;
	double det;
	int manual;

	cout << "Pulsa 1 para rellenar la matriz de forma manual: ";
	cin >> manual;

	for (int i = min; i <= max; i += incremento) {
		M = vector <vector <double>>(i, vector <double>(i));
		
		if (manual == 1) rellenarMatrizManual(M);
		else rellenarMatriz(M);

		Tiempo.start();
		det = calcularDeterminanteRecursivo(M, i);

		if (Tiempo.isStarted()) Tiempo.stop();

		tiemposReales.push_back(Tiempo.elapsed());
		nElementos.push_back(i);

		cout << nElementos.back() << " ";
		cout << tiemposReales.back() << " ";
		cout << det << endl;
	}
}

double calcularDeterminanteRecursivo(vector <vector <double>> &M, int n) {
	if (n == 1) return M[0][0];
	
	int f = 1;
	double det = 0;

	for (int i=0; i < n; i++) {
		vector <vector <double>> submatriz(n-1, vector <double>(n-1));
		
		for (int j = 0; j < n-1; j++) {
			
			for (int k = 0; k < n-1; k++) {
				if (k < i)  submatriz[j][k] = M[j+1][k];
				if (k >= i) submatriz[j][k] = M[j+1][k+1];
			}
		}

		det += f * M[0][i] * calcularDeterminanteRecursivo(submatriz, n-1);
		f *= -1;
	}

	return det;
}

void ajusteRecursivo(const vector <double> &n,
const vector <double> &tiemposReales, vector <double> &a) {
	vector <vector <double>> A(2, vector <double>(2));
	vector <vector <double>> X(2, vector <double>(1));
	vector <vector <double>> B(2, vector <double>(1));
	
	vector <double> z;
	for (auto &i : n)
		z.push_back(fact(i));

	// Rellenar las matrices A y B
	rellenaA(A, tiemposReales, z);
	rellenaB(B, tiemposReales, z);

	// Resolución del sistema de ecuaciones.
	resolverSistemaEcuaciones(A, B, 2, X);
	for (int i = 0; i < 2; ++i) a[i] = X [i][0];
}

void calcularTiemposEstimadosRecursivo(
	const vector <double> &n, 
	const vector <double> &a,
	vector <double> &tiemposEstimados) {
	
	for (auto &i : n)
		tiemposEstimados.push_back(a[0] + a[1] * fact(i));
}

double calcularTiempoEstimadoRecursivo(const double &n, const vector<double> &a) {
	return a[0] + a[1] * fact(n);
}

