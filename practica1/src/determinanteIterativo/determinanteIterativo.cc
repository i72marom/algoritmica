#include "determinanteIterativo.h"

void determinanteIterativo() {
	vector<double> tiemposReales, ajuste(4);
	vector<double> nElementos, tEstimado;
	int max, min, incremento;
	long n_estimado = -1;

	cout << "Número mínimo de elementos: ";
	cin >> min;
	cout << "Número máximo de elementos: ";
	cin >> max;
	cout << "Incremento: ";
	cin >> incremento;

	tiempoDeterminante(min, max, incremento, tiemposReales, nElementos);

	ajustePolinomico(nElementos, tiemposReales, ajuste);

	calcularTiemposEstimadosPolinomico(nElementos, tiemposReales, ajuste, tEstimado);
	
	escribeFichero(tiemposReales, tEstimado, nElementos, "../text/iterativo.txt");

	cout << "Ecuación ajustada: ";
	cout << ajuste[0] << " + ";
	cout << ajuste[1] << " * n + ";
	cout << ajuste[2] << " * n² + ";
	cout << ajuste[3] << " * n³";
	cout << endl;

	cout << "Coeficiente de determinacion: ";
	cout << calcularCoeficienteDeterminacion(tiemposReales, tEstimado);
	cout << endl;

	while (n_estimado != 0) {
		cout << "Tamaño de la muestra a estimar (0 para salir): ";
		cin >> n_estimado;

		if (n_estimado > 0)
			microsegundosADias(calcularTiempoEstimadoPolinomico(n_estimado, ajuste));
	}
}

void tiempoDeterminante(int min, int max, int incremento,
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
		det = calcularDeterminante(M, i);

		if (Tiempo.isStarted()) Tiempo.stop();

		tiemposReales.push_back(Tiempo.elapsed());
		nElementos.push_back(i);

		cout << nElementos.back() << " ";
		cout << tiemposReales.back() << " ";
		cout << det << endl;
	}
}

double calcularDeterminante(vector <vector <double>> &M, int n) {
	double aux;
	double determinante = 1;
	
	for(int k = 0; k < n-1; k++){//recorrer la diagonal
		determinante *= M[k][k];
		
		if(M[k][k]==0) return 0;
		else {
			for (int i = k+1; i < n; i++) {//recorrer fila
				aux = -M[i][k];
				
				for(int j = k; j < n; j++)
					M[i][j] = M[i][j] + aux * M[k][j] / M[k][k];
			}
		}
	  
	}
	
	return determinante * M[n-1][n-1];
}

void ajustePolinomico(const vector <double> &n,
const vector <double> &tiemposReales, vector <double> &a) {
	vector <vector <double>> A(4, vector <double>(4));
	vector <vector <double>> X(4, vector <double>(1));
	vector <vector <double>> B(4, vector <double>(1));
	vector <double> v(n);

	// Rellenar las matrices A y B
	rellenaA(A, tiemposReales, v);
	rellenaB(B, tiemposReales, v);

	// Resolución del sistema de ecuaciones.
	resolverSistemaEcuaciones(A, B, 4, X);
	for (int i = 0; i < 4; ++i) a[i] = X [i][0];
}

void calcularTiemposEstimadosPolinomico(
	const vector <double> &n, 
	const vector <double> &tiemposReales,
	const vector <double> &a,
	vector <double> &tiemposEstimados) {
	
	for (auto &i : n)
		tiemposEstimados.push_back(a[0] + a[1] * i + a[2] * pow(i,2) + a[3] * pow(i,3));
}

double calcularTiempoEstimadoPolinomico(const double &n, const vector<double> &a) {
	return a[0] + a[1] * n + a[2] * pow(n,2) + a[3] * pow(n,3);
}

