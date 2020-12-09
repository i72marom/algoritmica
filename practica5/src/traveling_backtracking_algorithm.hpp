#ifndef __RANDON_GRAPH_ALGORITHM_HPP__
#define __RANDON_GRAPH_ALGORITHM_HPP__

#include "traveling_salesman_greedy_algorithm.hpp"

/**
 * @brief Create a new graph from the old graph by selecting the edges whose weight is greter than 200.
 * @arg[in] g is a weighted graph.
 * @arg[out] newGraph is the new graph.
 * @pre the weigths meet the triangular inequality: d(u,v) <= d(u,k) + d(k,v) for all u!=v!=k.
 */
template <class T>
bool traveling_salesman_backtraking (WGraph<T> & g, WGraph<T> & newGraph) {
	std::vector<bool> visited(g.capacity());
	std::vector<size_t> currentPath;
	std::vector< std::vector <size_t> > allPaths;
	int n_podas = 0;	

	for(size_t i = 0; i < g.capacity(); i++)
		visited[i] = false; 

	// obtener valor de poda
	g.goto_first_node();
	float poda = traveling_salesman_greedy(g);

	// algoritmo con poda
	g.goto_first_node();
	deep_travel(g, g.current_node()->item(), visited, currentPath, allPaths);

	for (size_t n = 0; n < g.size(); ++n)
        newGraph.add_node(g.node(n)->item());

	size_t pos;
	float w = std::numeric_limits<float>::max();
	for(size_t i = 0; i < allPaths.size(); i++) {
		float aux = 0;
		
		typename WGraph<T>::EdgeRef e;
		
		for(size_t j = 0; j < g.capacity(); j++) {
			size_t a = j+1;
			if (j == g.capacity()-1) a = 0;

			g.goto_edge(g.node(allPaths[i][j]), g.node(allPaths[i][a]));
			e = g. current_edge();

			aux += e->item();

			if (aux >= poda) {
				n_podas++;
				break;
			}
		}

		if (aux < poda) {
			poda = aux;
			pos = i;
		}
	}

	for (size_t n = 0; n < g.size(); ++n) {
		size_t a = n+1;
		if (n == g.size()-1) a = 0;

		auto u = g.node(allPaths[pos][n]);
		auto v = g.node(allPaths[pos][a]);
		
		g.goto_edge(u, v);
		auto e = g. current_edge();
		auto w = e->item();
		
		newGraph.set_weight(newGraph.find(u->item()), newGraph.find(v->item()), w);
	}

	std::cout << "Numero de podas: " << n_podas << std::endl;

	return true;
}

template <class T>
void deep_travel (
	WGraph<T>  &g, 
	const T keyNode, 
	std::vector<bool> visited, 
	std::vector<size_t> currentPath,  
	std::vector< std::vector <size_t> > &allPaths
) {
	typename WGraph<T>::NodeRef u, v;
	typename WGraph<T>::EdgeRef e;
	
	u = g.find(keyNode); 
	visited[u->label()] = true; 
	currentPath.push_back(u->label()); 

	if (currentPath.size() == g.capacity()) 
		allPaths.push_back(currentPath); 
		
	g.goto_first_edge();

	while (g.has_current_edge()) {
		e = g.current_edge();
		v = e->other(u);
		
		if (not visited[v->label()]) {
			deep_travel(g, v->item(), visited, currentPath, allPaths);
			g.goto_edge(u, v); 
		}
		
		g.goto_next_edge(); 
	}
}

#endif //__RANDON_GRAPH_ALGORITHM_HPP__
