#ifndef __RANDON_GRAPH_ALGORITHM_HPP__
#define __RANDON_GRAPH_ALGORITHM_HPP__

#include <stack>
#include <utility>
#include <valarray>

#include "graph.hpp"
#include "graph_utils.hpp"



/**
 * @brief Create a new graph from the old graph by selecting the edges whose weight is greter than 200.
 * @arg[in] g is a weighted graph.
 * @arg[out] newGraph is the new graph.
 * @pre the weigths meet the triangular inequality: d(u,v) <= d(u,k) + d(k,v) for all u!=v!=k.
 */

template <class T>
bool traveling_salesman_dynamic(WGraph<T> & g, WGraph<T> & newGraph) {
	//This algorithm travel the graph from the first node
	//std::vector< typename WGraph<T>::EdgeRef > edges;
	std::vector<bool> visited(g.capacity()); //This vector is used to check if the node has been visited.
	std::vector<size_t> currentPath;
	std::vector< std::vector <size_t> > allPaths;
	for(size_t i = 0; i < g.capacity(); i++) //All the nodes are marked as not visited
		visited[i] = false; 

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
		}

		if (aux < w) {
			w = aux;
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


/*
template <class T>
float d(WGraph<T>  &g, const T keyNode, std::vector<bool> visited, std::vector<size_t> &I) {
	typename WGraph<T>::NodeRef u, v;
	typename WGraph<T>::EdgeRef e;
	float w;
	
	u = g.find(keyNode); //KeyNode is searched in the graph
	visited[u->label()] = true; //The current node is marked as visited
	bool all = true;

	for (int i = 0; i < visited.size(); ++i) 
		if (!visited[i]) all = false;

	if (all) {
		g.goto_first_node();
		v = g.current_node();
		
		g.goto_edge(u, v);
		e = g.current_edge();
		w = e->item();

		return w; 
	}

	w = std::numeric_limits<float>::max();

	for (size_t i = 0; i < g.size(); ++i) {
		if (visited[i] == false) {
			v = g.node(i);
			g.goto_edge(u, v);
			e = g.current_edge();
			float dist = e->item() + d(g, g.node(i)->item(), visited, I);

			if (dist < w) w = dist;
		}
	}
	
	return w;
}
*/


#endif //__RANDON_GRAPH_ALGORITHM_HPP__

