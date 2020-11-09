#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <fstream>
#include <string>
#include <vector>
#include "../classTime/classTime.h"

using namespace std;

/**
 * Convierte el tiempo en microsegundos a formato dias, horas, minutos, segundos y milisegundos.
 * @param ms Tiempo en microsegundos.
 */
void microsegundosADias(double ms);

/**
 * Rellena la matriz de forma aleatoria con valores de tipo double de entre 0.95 y 1.05.
 * @param M Matriz a rellenar.
 */
void rellenarMatriz(vector<vector <double>> &M);

/**
 * Guarda los datos en un fichero para poder generar la gráfica.
 * @param tReal     Vector de tiempos reales.
 * @param tEstimado Vector de tiempos estimados.
 * @param nElements Vector con el tamaño de los vectores estimados.
 * @param nombre    Nombre del fichero.
 */
void escribeFichero(
	vector<double> &tiempos, 
	vector<double> &orden,
	string nombre
);

/**
 * Calcula el producto de dos matrices de orden n.
 * @param A         Primera matriz.
 * @param B         Segunda matriz.
 * @param resultado Resultado del producto.
 */
void productoMatriz(
	vector<vector<double>> &A, 
	vector<vector<double>> &B,
	vector<vector<double>> &resultado
);

void pedirDatos(
	int *orden_min,
	int *orden_max,
	int *incremento,
	int *exponente
);

void tiemposExponenciacion(int min, int max, int inc, int exp);

void exponenciacion(vector<vector<double>> M, int o, int exp);

void tiemposExponenciacionDyV(int min, int max, int inc, int exp);

vector<vector<double>> exponenciacionDyV(
	vector<vector<double>> M, 
	int o, 
	int exp
);

void tiemposExponenciacionDyVIterativo(int min, int max, int inc, int exp);

void exponenciacionDyVIterativo(
	vector<vector<double>> M, 
	int o, 
	int exp
);

void identidad(vector<vector<double>> M, int o);

#endif