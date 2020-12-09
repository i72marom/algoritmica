#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <vector>
#include <valarray>

#include "city.hpp"
#include "graph.hpp"
#include "graph_utils.hpp"
#include "traveling_backtracking_algorithm.hpp"
#include "nReinas.hpp"

int traveling_salesman_backtraking_algorithm()
{
	int exit_code = EXIT_SUCCESS;
	try
	{
		char file_name_graph[100];

		std::cout << "File of the graph: ";
		std::cin >> file_name_graph;

		std::ifstream input_file (file_name_graph);
		if (!input_file)
		{
			std::cerr << "Error: could not open input filename '" << file_name_graph << "'." << std::endl;
			return EXIT_FAILURE;
		}
		std::string type;
		input_file >> type;
		input_file.ignore();
		
		if(type == "CITY")
		{
			auto g = create_wgraph<City>(input_file);
			if (!g)
			{
				std::cerr << "Error: could not load a valid wgraph for cities." << std::endl;
				return EXIT_FAILURE;
			}
			WGraph<City> newGraph(g->capacity());
			traveling_salesman_backtraking(*g, newGraph); //deep travel of the graph g
			fold_wgraph(std::cout, newGraph);
		}
		else
		{
			std::cerr << "Error: unknown graph type." << std::endl;
			return EXIT_FAILURE;
		}
	}
	catch(std::runtime_error &e)
	{
		std::cerr << "Run time exception: " << e.what() << std::endl;
		exit_code = EXIT_FAILURE;
	}
	catch(...)
	{
		std::cerr << "Catched unknown exception!." << std::endl;
		exit_code = EXIT_FAILURE;
	}
	return exit_code;
}

void nReinas() {
	int n_reinas, n_intentos = 0;
	bool found = false;
   
	do {
		std::cout<<"Debe haber al menos 4 reinas en el tablero. Numero de reinas: ";
		std::cin >> n_reinas;
	} while (n_reinas < 4);
		
	std::vector<int> v;
	v.resize(n_reinas);
   
	do {
		n_intentos++;
		found = nReinasAlgoritmo(n_reinas, v);
		
		if (found) {
			for(int i = 0; i < v.size(); i++) {
				for (int j = 0; j < v.size(); ++j)
					std::cout << "----";
				std::cout << std::endl;

				for(int j = 0; j < v.size(); j++) {
					if (v[j] == i) std::cout << "|" << " Q ";
					else std::cout << "|" << "   ";
					if(j == v.size()-1) std::cout << "|" << std::endl;
				}
			}
			
			for (int j = 0; j < v.size(); ++j)
				std::cout << "----";
			std::cout << std::endl;
		}
	} while (!found);
	
	std::cout << "Numero de intentos: " << n_intentos << std::endl;
}
