#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;
class Proveedores
{
private: string nit;

public:	string prov; string dir; int tel;  string n;
		string proveedor = prov;
		string direccion = dir;
		int telefono = tel;


	void setNit(string n) { nit = n; }
	void setNombres(string prov) { proveedor = prov; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	
	string getNit() { return nit; }
	string getNombres() { return proveedor; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }

	
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string  insertar = "INSERT INTO proveedor(nit,proveedor,direccion,telefono) VALUES ('" + nit + "','" + proveedor + "','" + direccion + "'," + t + ")";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Datos de Proveedores ------------" << endl;
			string consulta = "SELECT * FROM db_proveedor.proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string id = to_string(id_Proveedor);
		if (cn.getConectar()) {

			string update = "UPDATE `db_proveedor`.`proveedores` SET `id_Proveedor` = '', `proveedor` = '', `nit` = '', `direccion` = '', `telefono` = '' WHERE (`id_Proveedor` = '1')";

			const char* i = update.c_str();

			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "INGRESADO CON EXITO .... \n";

			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_conexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;

		cn.abrir_conexion();
		string id = to_string(id_Proveedor);
		if (cn.getConectar()) {

			string delite = "DELETE FROM `db_proveedor`.`proveedores` WHERE (`id_Proveedor` = ' ')";

			const char* i = delite.c_str();

			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {

				cout << "ELIMINADO CON EXITO .... \n";

			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_conexion();
	}
};