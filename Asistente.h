#pragma once
#include <string>


using namespace std;

class Asistente {
public:
    Asistente();
    int nacimiento;
    string nombre, apellido;

    void setNumeroasistente(int);
    void setNombre(string);
    void setApellido(string);
    void setNacimiento(int);
    void setGenero(string);
    int getNumeroasistente();
    int getNacimiento();
    string getNombre();
    string getApellido();
    string getGenero();
    void verDatosasistentes();

private:
    int numeroasistente;
    string genero;



};
