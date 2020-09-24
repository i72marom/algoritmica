#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "../classTime/classTime.h"
#include <vector>
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
	vector<double> &realTime, vector<int> &nElements);

/**
 * [escribeFichero description]
 * @param time      [description]
 * @param nElements [description]
 */
void escribeFichero(vector<double> &time, vector<int> &nElements);

#endif