#ifndef DETERMINATEITERATIVO_H
#define DETERMINATEITERATIVO_H

#include "../funciones/funciones.h"

/**
 * Inicia el proceso para ajustar la función polinomica del determinante iterativo.
 */
void determinanteIterativo();

/**
 * Se ajustará un polinomio de grado 3. 
 * @param n             Vector con los distintos ordenes de la matriz.
 * @param tiemposReales Vector con los tiempos reales de cálculo de determinante.
 * @param a             Vector de coeficientes del polinomio de ajuste.
 */
void ajustePolinomico(
	const vector <double> &n,
	const vector <double> &tiemposReales,
	vector <double> &a
);

/**
 * Calcula los valores estimados para los distintos valores del vector n.
 * @param n                Vector con los distintos ordenes de la matriz.
 * @param a                Vector de coeficientes del polinomio de ajuste.
 * @param tiemposEstimados Vector que almacenará los tiempo que se obtengan en la estimación.
 */
void calcularTiemposEstimadosPolinomico(
	const vector <double> &n, 
	const vector <double> &tiemposReales,
	const vector <double> &a, 
	vector <double> &tiemposEstimados
);

/**
 * Calcula el tiempo estimado para obterner el determinante de una matriz de orden n.
 * @param n Orden de la matriz a estimar
 * @param a Vector de coeficientes del polinomio de ajuste.
 */
double calcularTiempoEstimadoPolinomico(const double &n, const vector<double> &a);

/**
 * Ejecuta el algoritmo de ordenación para cada uno de los tamaños de vector y calcula el tiempo medio para las repeticiones.
 * @param min           Tamaño mínimo del vector.
 * @param max           Tamaño máximo del vector.
 * @param incremento    El orden de la matriz se incrementa de x en x.
 * @param tiemposReales Vector para almacenar el tiempo.
 * @param nElementos    Vector para almacenar el tamaño de vector.
 */
void tiempoDeterminante(
	int min, 
	int max, 
	int incremento,
	vector<double> &tiemposReales, 
	vector<double> &nElementos
);

/**
 * Calcula el determinante de una matriz de orden n de forma iterativa.
 * @param  M Matriz.
 * @param  n Orden de la matriz.
 * @return   Determinante para poder comprobar si funciona de forma correnta.
 */
double calcularDeterminante(vector <vector <double>> &M, int n);

#endif