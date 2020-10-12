#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <fstream>
#include <string>
#include "../classTime/classTime.h"
#include "../sistemaEcuaciones/sistemaEcuaciones.hpp"

/**
 * Convierte el tiempo en microsegundos a formato dias, horas, minutos, segundos y milisegundos.
 * @param ms Tiempo en microsegundos.
 */
void microsegundosADias(double ms);

/**
 * Sumatorio matemático.
 * @param n     Recibe los valores de z = NlogN.
 * @param  t    Tiempos reales.
 * @param  expN Exponente para los valores de n.
 * @param  expT Exponente para los valores de t.
 * @return      Devuelve el sumatorio de n^epxN * t^expT.
 */
double sumatorio(
	vector <double> &n, 
	const vector <double> &t, 
	int expN, 
	int expT
);

/**
 * Rellena la matriz de forma aleatoria con valores de tipo double de entre 0.95 y 1.05.
 * @param M Matriz a rellenar.
 */
void rellenarMatriz(vector<vector <double>> &M);

/**
 * Rellena la matriz de forma manual, pidiendo por pantalla el valor de cada elemento de la matriz.
 * @param M Matriz a rellenar.
 */
void rellenarMatrizManual(vector<vector <double>> &M);

/**
 * Guarda los datos en un fichero para poder generar la gráfica.
 * @param tReal     Vector de tiempos reales.
 * @param tEstimado Vector de tiempos estimados.
 * @param nElements Vector con el tamaño de los vectores estimados.
 * @param nombre    Nombre del fichero.
 */
void escribeFichero(
	vector<double> &tReal, 
	vector<double> &tEstimado,
	vector<double> &nElements,
	string nombre
);

/**
 * Rellena las matrices necesarias para el ajuste polinomico.
 * @param M Matriz de coeficientes o termino independiente.
 * @param T Vector de tiempos reales.
 * @param N Vector con los tamaños de los vectores o z.
 */
void rellenaA(
	vector <vector <double>> &M,
	const vector <double> &T,
	vector <double> &N
);

/**
 * Rellena las matrices necesarias para el ajuste polinomico.
 * @param M Matriz de coeficientes o termino independiente.
 * @param T Vector de tiempos reales.
 * @param N Vector con los tamaños de los vectores o z.
 */
void rellenaB(
	vector <vector <double>> &M,
	const vector <double> &T,
	vector <double> &N
);

/**
 * Calcula el coeficiente de determinación de los tiempos reales y estimados.
 * @param  tiemposReales    Vector de tiempos reales.
 * @param  tiemposEstimados Vector de tiempos estimados.
 * @return                  Coeficiente de determinación.
 */
double calcularCoeficienteDeterminacion(
	const vector <double> &tiemposReales,
	const vector <double> &tiemposEstimados
);

/**
 * Calcula el factorial de un numero.
 * @param  n Numero.
 * @return   Factorial.
 */
double fact(double n);

#endif