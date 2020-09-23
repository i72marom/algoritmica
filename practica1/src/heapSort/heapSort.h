#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * [ordenacionHeapSort description]
 */
void ordenacionHeapSort();

/**
 * [rellenarVector description]
 * @param v [description]
 */
void rellenarVector(std::vector<int> &v);

/**
 * [heapSort description]
 * @param  v [description]
 * @return   [description]
 */
bool heapSort(std::vector<int> &v);

/**
 * [estaOrdenado description]
 * @param  v [description]
 * @return   [description]
 */
bool estaOrdenado(const std::vector<int> &v);

/**
 * [tiemposOrdenacionHeapSort description]
 * @param min       [description]
 * @param max       [description]
 * @param rep       [description]
 * @param realTime  [description]
 * @param nElements [description]
 */
void tiemposOrdenacionHeapSort(int min, int max, int rep, int incremento,
	std::vector<double> &realTime, std::vector<int> &nElements);

#endif