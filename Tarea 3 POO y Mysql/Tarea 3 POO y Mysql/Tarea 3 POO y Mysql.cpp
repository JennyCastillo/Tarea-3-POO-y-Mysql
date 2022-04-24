#include "Proveedores.h"
#include <iostream>
using namespace  std;

int main()
{

	string nit, prove, direccion;
	int telefono;
	cout << "Ingrese Nit: ";
	getline(cin, nit);
	cout << "Ingrese Proveedor: ";
	getline(cin, prove);
	cout << "Ingrese Direccion: ";
	getline(cin, direccion);
	cout << "Ingrese Telefono: ";
	cin >> telefono;
	cin.ignore();

	Proveedores p = Proveedores(prove, direccion, telefono, nit);

	p.crear();
	p.leer();
	p.actualizar();
	p.eliminar();

	system("pause");
	return 0;
}
