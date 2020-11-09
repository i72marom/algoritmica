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

void escribeFichero(vector<double> &tiempos, vector<double> &orden, string nombre) {
	ofstream f(nombre);

	for (int i = 0; i < orden.size(); ++i)
		f << orden[i] << " " << tiempos[i] << endl;

	f.close();
}

void rellenarMatriz(vector<vector <double>> &M) {
	for (auto &i : M) {
		for (auto &v : i)
			v = double(rand() % 3) + (double(rand() % 101)) / 100;
	}
}

vector<vector<double>> productoMatriz(
vector<vector<double>> &A, vector<vector<double>> &B) {
	vector<vector<double>> resultado(A.size(), vector <double>(A.size()));

	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A.size(); ++j) {
			resultado[i][j] = 0;

			for (int k = 0; k < A.size(); ++k) {
				resultado[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return resultado;
}

void pedirDatos(int *min, int *max, int *incremento, int *exp) {
	cout << "Orden mínimo: ";
	cin >> *min;
	cout << "Orden máximo: ";
	cin >> *max;
	cout << "Incremento: ";
	cin >> *incremento;
	cout << "Exponente: ";
	cin >> *exp;
}

void tiemposExponenciacion(int min, int max, int inc, int exp) {
	vector<vector <double>> M;
	vector<double> orden, tiempos;
	Clock Tiempo;

	for (int i = min; i <= max; i += inc) {
		M = vector <vector <double>>(i, vector <double>(i));
		rellenarMatriz(M);

		Tiempo.start();
		exponenciacion(M, i, exp);

		if (Tiempo.isStarted()) Tiempo.stop();

		tiempos.push_back(Tiempo.elapsed());
		orden.push_back(i);

		cout << orden.back() << " ";
		cout << tiempos.back() << " " << endl;
	}

	escribeFichero(tiempos, orden, "../text/exponenciacion.txt");
}

void exponenciacion(vector<vector<double>> M, int o, int exp) {
	vector<vector<double>> resultado(o, vector <double>(o));

	resultado = productoMatriz(M, M);
	for (int i = 3; i < exp; ++i)
		resultado = productoMatriz(M, resultado);
}

void tiemposExponenciacionDyV(int min, int max, int inc, int exp) {
	vector<vector <double>> M;
	vector<double> orden, tiempos;
	Clock Tiempo;

	for (int i = min; i <= max; i += inc) {
		M = vector <vector <double>>(i, vector <double>(i));
		rellenarMatriz(M);

		Tiempo.start();
		exponenciacionDyV(M, i, exp);

		if (Tiempo.isStarted()) Tiempo.stop();

		tiempos.push_back(Tiempo.elapsed());
		orden.push_back(i);

		cout << orden.back() << " ";
		cout << tiempos.back() << " " << endl;
	}

	escribeFichero(tiempos, orden, "../text/exponenciacionDyV.txt");
}

vector<vector<double>> exponenciacionDyV(vector<vector<double>> M, int o, int exp) {
	vector<vector<double>> resultado(o, vector <double>(o));
	vector<vector<double>> aux(o, vector <double>(o));

	if (exp == 1) return M;
	else {
		if (exp % 2 == 0) {
			resultado = exponenciacionDyV(M, o, exp/2);
			return productoMatriz(resultado, resultado);
		} else{
			aux = exponenciacionDyV(M, o, exp-1);
			return productoMatriz(M, aux);
		}
	}
}

void tiemposExponenciacionDyVIterativo(int min, int max, int inc, int exp) {
	vector<vector <double>> M;
	vector<double> orden, tiempos;
	Clock Tiempo;

	for (int i = min; i <= max; i += inc) {
		M = vector <vector <double>>(i, vector <double>(i));
		rellenarMatriz(M);

		Tiempo.start();
		exponenciacionDyVIterativo(M, i, exp);

		if (Tiempo.isStarted()) Tiempo.stop();

		tiempos.push_back(Tiempo.elapsed());
		orden.push_back(i);

		cout << orden.back() << " ";
		cout << tiempos.back() << " " << endl;
	}

	escribeFichero(tiempos, orden, "../text/exponenciacionDyVIterativo.txt");
}

void exponenciacionDyVIterativo(vector<vector<double>> M, int o, int exp) {
	int i = exp;
	vector<vector<double>> X = M;
	vector<vector<double>> R(o, vector <double>(o));
	identidad(R, o);

	while (i > 0) {
		if (i % 2 == 1) R = productoMatriz(R, X);
		X = productoMatriz(X, X);
		i /= 2;
	}

}

void identidad(vector<vector<double>> M, int o) {
	for (int i = 0; i < o; ++i) {
		for (int j = 0; j < o; ++j) {
			if (i == j) M[i][j] = 1;
			else M[i][j] = 0;
		}
	}
}
