#include "funciones.h"

void microsegundosADias(double ms) {
	cout << int(ms/8.64e10) << " días ";
	ms = long(ms) % long(8.64e10);
	cout << int(ms/3.64e9) << " horas ";
	ms = long(ms) % long(3.64e9);
	cout << int(ms/6e7) << " minutos ";
	ms = long(ms) % long(6e7);
	cout << int(ms/1e6) << " segundos ";
	ms = long(ms) % long(1e6);
	cout << int(ms/1000) << " milisegundos." << endl;
}

double sumatorio(vector <double> &n, const vector <double> &t, int expN, int expT) {
	double sumatorio = 0;

	for (int i = 0; i < n.size(); ++i) 
		sumatorio += pow(n[i], expN) * pow(t[i], expT);

	return sumatorio;
}

void escribeFichero(vector<double> &tReal, 
vector<double> &tEstimado, vector<double> &nElements, string nombre) {
	ofstream f(nombre);

	for (int i = 0; i < nElements.size(); ++i) {
		f << nElements[i] << " " << tReal[i] << " " << tEstimado[i] << endl;
	}

	f.close();
}

void rellenarMatriz(vector<vector <double>> &M) {
	for (auto &i : M) {
		for (auto &v : i)
			v = 0.95 + (double(rand() % 10)) / 100;
	}
}

void rellenarMatrizManual(vector<vector <double>> &M) {
	for (int i = 0; i < M.size(); ++i) {
		for (int j = 0; j < M[0].size(); ++j) {
			cout << "M[" << i << "][" << j << "]: ";
			cin >> M[i][j]; 
		}
	}
}

void rellenaA(vector <vector <double>> &M, 
const vector <double> &T, vector <double> &N) {
	int grado;

	for (int i = 0; i < M.size(); i++) {
		grado = 2*i;
		
		for (int j = i; j < M[0].size(); j++) {
			M[i][j] = sumatorio(N, T, grado, 0);
			M[j][i] = M[i][j];
			grado++;
		}
	}
}

void rellenaB(vector <vector <double>> &M, 
const vector <double> &T, vector <double> &N) {
	for (int i = 0; i < M.size(); i++)
		M[i][0] = sumatorio(N, T, i, 1);
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

double fact(double n) {
	double f = 1;

	for (double c = 1; c <= n; c++) f *= c;

	return f;
}
