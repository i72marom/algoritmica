#ifndef __N_REINAS__
#define __N_REINAS__

#include <vector>

bool Lugar(int k, std::vector<int> &result) {
	for(int i = 0;i<k;i++)
		if (result[i] == result[k] || abs(result[i] - result[k]) == abs(i-k))
			return false;

	return true;
}

bool nReinasAlgoritmo(const int n_reinas, std::vector<int>&result) {
	for(int i = 0; i < n_reinas; i++)
		result[i] = 0;

	int cont;
	for(int i = 0;i<n_reinas;i++)   {
		cont = 0;
		std::vector<int> ok;
		
		for(int j = 0;j<n_reinas;j++) {
			result[i] = j;
		   
			if(Lugar(i, result)) {
				cont++;
				ok.push_back(j);
			}
		}
		
		if(cont == 0) return false;
		result[i] = ok[rand() % cont];
	}

	return true;
}

#endif