#ifndef TRAVELING_H
#define TRAVELING_H

#include "graph.hpp"
#include "graph_utils.hpp"

/**
 * Implementacion del algoritmo voraz para resolver el problema de viajante de comercio.
 * @param  g        Grafo de entrada.
 * @param  newGraph Grafo que contiene la ruta.
 */
template <class T>
float traveling_salesman_greedy(WGraph<T> & g) {
	float total_weight = 0;
	
	g.goto_first_node();
	for (size_t n = 0; n < g.size(); ++n) {
		g.goto_first_edge();

		auto u = g.current_node();
		auto v = g.current_edge()->second();
		auto w = std::numeric_limits<float>::max();
		
		while(g.has_current_edge()) {
			auto e = g.current_edge();

			if (e->item() < w && !e->second()->is_visited()) {
				v = e->second();
				w = e->item();
			}
			
			g.goto_next_edge();
		}

		total_weight += w;
		v->set_visited(true);
		
		g.goto_node(v);
	} 

	return total_weight; 
}


#endif //__RANDON_GRAPH_ALGORITHM_HPP__
