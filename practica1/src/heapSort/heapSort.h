#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "../funciones/funciones.h"
#include <algorithm>

using namespace std;

/**
 * Inicia el proceso para ajustar la función nlogn del metodo de ordenación heapsort.
 */
void ordenacionHeapSort();

/**
 * Rellena el vector con valores aleatorios entre 0 y 10000000.
 * @param v Vector para almacenar los valores aleatorios.
 */
void rellenarVector(vector<int> &v);

/**
 * Metodo de ordenación heap sort.
 * @param  v Vector a ordenar.
 * @return   True si está ordenado, False en caso contrario.
 */
bool heapSort(vector<int> &v);

/**
 * Comprueba si el vector se ha ordenado correctamente.
 * @param  v Vector.
 * @return   True si está ordenado, False en caso contrario.
 */
bool estaOrdenado(const vector<int> &v);

/**
 * Ejecuta el algoritmo de ordenación para cada uno de los tamaños de vector y calcula el tiempo medio para las repeticiones.
 * @param min       Tamaño mínimo del vector.
 * @param max       Tamaño máximo del vector.
 * @param rep       Número de repeticiones.
 * @param realTime  Vector para almacenar el tiempo.
 * @param nElements Vector para almacenar el tamaño de vector.
 */
void tiemposOrdenacionHeapSort(
	int min, 
	int max, 
	int rep, 
	int incremento,
	vector<double> &realTime, 
	vector<double> &nElementos
);

/**
 * Ajuste de la función a0 + a1*NlogN mediante el método de minimos cuadrados:
 * @li Se hace un cambio de variable: z = NlogN
 * @li Se ajusta una función lineal: a0 + a1*z.
 * @param n             Vector con los tamaños para los que se han hecho las pruebas.
 * @param tiemposReales Tiempos obtenidos en la ordenación del vector.
 * @param ajuste        Vector de coeficientes de la curva de ajuste.
 */
void ajusteNlogN(
	const vector <double> &n, 
	const vector <double> &tiemposReales,
	vector <double> &ajuste
);

/**
 * Teniendo en cuenta la función ajustada ajusteNlogN, se obtendrán 
 * los tiempos estimados mediante dicha función.
 * @param n                Tamaños de vector con los que se han hecho las pruebas iniciales.
 * @param a                Vector de coeficientes de la curva de ajuste.
 * @param tiemposEstimados Vector que almacena los tiempos estimados.
 */
void calcularTiemposEstimadosNlogN(
	const vector <double> &n,
	const vector <double> &a, 
	vector <double> &tiemposEstimados
);

/**
 * Estimación del tiempo que tardará una muestra de tamaño n en ordenarse.
 * @param  n Tamaño de la muestra a estimar.
 * @param  a Coeficientes de la función ajustada.
 * @return   Tiempo en días, que tardaría en ordenarse la muestra.
 */
double calcularTiempoEstimadoNlogN(const double &n, vector <double> &a);

#endif