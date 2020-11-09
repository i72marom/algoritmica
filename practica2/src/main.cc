#include "funciones/funciones.h"

int main() {
	int min, max, inc, exp;
//	vector<vector<double>> orden, exponenciacion, dyv, dyv_iterativo;
	srand(time(NULL));

	pedirDatos(&min, &max, &inc, &exp);

	cout << "==========================================" << endl;
	cout << "==============Exponenciacion==============" << endl;
	cout << "==========================================" << endl;
	tiemposExponenciacion(min, max, inc, exp);

	cout << "==========================================" << endl;
	cout << "============Exponenciacion DyV============" << endl;
	cout << "==========================================" << endl;
	tiemposExponenciacionDyV(min, max, inc, exp);

	cout << "==========================================" << endl;
	cout << "=======Exponenciacion DyV Iterativo=======" << endl;
	cout << "==========================================" << endl;
	tiemposExponenciacionDyVIterativo(min, max, inc, exp);
}
