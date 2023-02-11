#include "Asistente.h"
#include <iostream>

using namespace std;

    Asistente::Asistente(){
	this->numeroasistente = 0;
	this->nombre = "";
	this->apellido = "";
	this->nacimiento = 0;
	this->genero = "";	
}
void Asistente::setNumeroasistente(int valor) {
	this->numeroasistente = valor;
}
void Asistente::setNombre(string valor) {
	this->nombre = valor;
}
void Asistente::setApellido(string valor) {
	this->apellido = valor;
}
void Asistente::setNacimiento(int valor) {
	this->nacimiento = valor;
}
void Asistente::setGenero(string valor) {
	this->genero = valor;
}
int Asistente::getNumeroasistente() {
	return this->numeroasistente;
}
int Asistente::getNacimiento() {
	return this->nacimiento;
}

string Asistente::getNombre() {
	return this->nombre;
}
string Asistente::getApellido() {
	return this->apellido;
}
string Asistente::getGenero() {
	return this->genero;
}
void Asistente::verDatosasistentes() {
	if (this->numeroasistente != 0) {
		cout << "Asistente N" << this->numeroasistente << endl;
		cout << "Nombre:" << this->nombre << endl;
		cout << "Apellido:" << this->apellido << endl;
		cout << "Año de nacimiento:" << this->nacimiento << endl;
		cout << "Genero:" << this->genero << endl;
		cout << endl;
	}
	else
		cout << "Este usuario no esta disponible" << endl << endl;
		



	
}
