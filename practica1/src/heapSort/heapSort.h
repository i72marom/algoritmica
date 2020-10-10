#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "../classTime/classTime.h"
#include "../sistemaEcuaciones/sistemaEcuaciones.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <fstream>

using namespace std;

/**
 * [ordenacionHeapSort description]
 */
void ordenacionHeapSort();

/**
 * [rellenarVector description]
 * @param v [description]
 */
void rellenarVector(vector<int> &v);

/**
 * [heapSort description]
 * @param  v [description]
 * @return   [description]
 */
bool heapSort(vector<int> &v);

/**
 * [estaOrdenado description]
 * @param  v [description]
 * @return   [description]
 */
bool estaOrdenado(const vector<int> &v);

/**
 * [tiemposOrdenacionHeapSort description]
 * @param min       [description]
 * @param max       [description]
 * @param rep       [description]
 * @param realTime  [description]
 * @param nElements [description]
 */
void tiemposOrdenacionHeapSort(int min, int max, int rep, int incremento,
	vector<double> &realTime, vector<double> &nElementos);

/**
 * [escribeFichero description]
 * @param time      [description]
 * @param nElements [description]
 */
void escribeFichero(vector<double> &tReal, vector<double> &tEstimado,
vector<double> &nElements);

/**
 * Ajuste de la función a0 + a1*NlogN mediante el método de minimos cuadrados:
 * @li Se hace un cambio de variable: z = NlogN
 * @li Se ajusta una función lineal: a0 + a1*z.
 * @param n             Vector con los tamaños para los que se han hecho las pruebas.
 * @param tiemposReales Tiempos obtenidos en la ordenación del vector.
 * @param ajuste        Vector de coeficientes de la curva de ajuste.
 */
void ajusteNlogN(const vector <double> &n, const vector <double> &tiemposReales,
	vector <double> &ajuste);

/**
 * Sumatorio matemático.
 * @param n     Recibe los valores de z = NlogN.
 * @param  t    Tiempos reales.
 * @param  expN Exponente para los valores de n.
 * @param  expT Exponente para los valores de t.
 * @return      Devuelve el sumatorio de n^epxN * t^expT.
 */
double sumatorio(vector <double> &n, const vector <double> &t, int expN, int expT);

/**
 * Teniendo en cuenta la función ajustada ajusteNlogN, se obtendrán 
 * los tiempos estimados mediante dicha función.
 * @param n                Tamaños de vector con los que se han hecho las pruebas iniciales.
 * @param a                Vector de coeficientes de la curva de ajuste.
 * @param tiemposEstimados Vector que almacena los tiempos estimados.
 */
void calcularTiemposEstimadosNlogN(const vector <double> &n,
const vector <double> &a, vector <double> &tiemposEstimados);

double calcularCoeficienteDeterminacion(const vector <double> &tiemposReales,
const vector <double> &tiemposEstimados);

#endif