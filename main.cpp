#include <iostream>     
#include <fstream>      
#include <sstream>      
#include <vector>       
#include <limits>       
#include "Asistente.h" 
#define maximoPersonas 100

using namespace std;

vector<string> split(string, char);
void agregarPersonas(Asistente[], int&);
void leerArchivo(string, Asistente[], int&);
void guardarDatos(string, Asistente[], int);
void mostrarDatos(Asistente[], int);                       //vector y funciones prototipos definidos
void eliminarAsistentes(Asistente [], int&);
void editarAsistentes(Asistente [], int&);
void ordenarPersonas(Asistente[], int&);

int main() {

    int opcion, indice = 0;
    Asistente personas[maximoPersonas];
    string Archivo = "Datosasistentes.txt";
    leerArchivo(Archivo, personas, indice); // Un de las primeras cosas que el programa hace al iniciarse es leer el archivo
                                            // de esta manera, al retornar al menu, se leera siempre el archivo por cada
                                            // cambio que se le haga
                               //Menu

    cout << "                   Bienvenido              " << endl << endl;
    cout << "-------   .Por favor, elija una opcion.  -------" << endl << endl;
    cout << "1. ----|       Agregar Asistentes       |----" << endl;
    cout << "2. ----|       Mostrar Asistentes       |----" << endl;
    cout << "3. ----|  Ordenar Asistentes por edad   |----" << endl;
    cout << "4. ----|       Editar un Asistente      |----" << endl;
    cout << "5. ----|       Eliminar Asistente       |----" << endl;
    cout << "6. ----|            SALIR               |----" << endl;
    cout << endl;
    cin >> opcion;
   

    switch (opcion)
    {
    case 1:
        agregarPersonas(personas, indice);
        guardarDatos(Archivo, personas, indice);
        break;
    case 2:
        mostrarDatos(personas, indice);
        
        break;

    case 3:
        ordenarPersonas(personas, indice);
        guardarDatos(Archivo, personas, indice);
            break;

    case 4:
        editarAsistentes(personas, indice);
        guardarDatos(Archivo, personas, indice);              // El menu simplemente ejecuta directamente cada funcion, seguido de un guardado de datos
                                                              // para que al terminar la operacion deseada, los cambios se guarden
       
            break;

    case 5:
            eliminarAsistentes(personas, indice);
            guardarDatos(Archivo, personas, indice);
            break;

    case 6:

        guardarDatos(Archivo, personas, indice);
        return 0;
    }
    return main();
}
void agregarPersonas(Asistente a[], int &indice) {       // Funcion que agrega asistentes 

    Asistente persona;
    int numeroasistente, nacimiento;
    string nombre, apellido, genero;

    cout << "Ingrese numero de la persona" << endl<<endl;
    cin >> numeroasistente;
    persona.setNumeroasistente(numeroasistente);

    cout << "Ingrese nombre de la persona" << endl << endl;
    cin >> nombre;
    persona.setNombre(nombre);

    cout << "Ingrese apellido de la persona" << endl << endl;
    cin >> apellido;
    persona.setApellido(apellido);

    cout << "Ingrese fecha de nacimiento de la persona" << endl << endl;
    cin >> nacimiento; 
    if (nacimiento >=1000)                   // un "if" para condicionar de cierta forma el formato del nacimiento ingresado
        persona.setNacimiento(nacimiento);
    else
        cout << "Error al ingresar fecha de nacimiento" << endl << endl;

    cout << "Ingrese genero de la persona" << endl << endl;
    cin >> genero;
    persona.setGenero(genero);

    a[indice] = persona;
    indice++;
}

void mostrarDatos(Asistente a[], int n) {   // Funcion que muestra los datos almacenados
    for (int i = 0; i <n; i++)             
        a[i].verDatosasistentes();          //  Un "for" pequeño que recorre el vector para luego llamar a la funcion
                                            //  "verDatosasistentes"  en Asistente.ccp
}

void ordenarPersonas(Asistente a[], int &indice) {  // Funcion que ordena los datos almacenados segun su Nacimiento

    Asistente ordenando;
    int ordenador1, ordenador2;
    for (int i = 0; i < indice; i++) {            // Creacion de 2 "for" que reccoren el vector
        for (int j = i; j < indice; j++) {
            ordenador1 = ((a[i].getNacimiento() % 10000));   
            ordenador2 = ((a[j].getNacimiento() % 10000));


            if (ordenador1 < ordenador2) {      

                ordenando = a[i];
                a[i] = a[j];                    // una vez obtenidos estos vectores asignados por "ordenandor1/2", obteniendo especificamente el año
                a[j] = ordenando;               // se comparan con un "if" y con la ayuda de un aux "ordenando" se hace el traspaso

            }

        }
    }

}

void editarAsistentes(Asistente a[], int& indice) {  //Funcion de editor de asistentes, compuesta por un minimenu para editar por dato
    Asistente perEditada;
    string valor;
    int editor = 0, editando = 0, opcion = 0;
    cout << "Ingrese numero del asistente a editar" << endl; //se pregunta y se ingresa el numero de asiste nte
    cin >> editor;
    for (int i = 0; i < indice; i++) {               //se recorre el vector
        if (a[i].getNumeroasistente() == editor)                                        
            editando = i;                                                              
    }
    cout << "Que desea editar?" << endl;
    cout << "1.----|   Nombre   |----" << endl;
    cout << "2.----|  Apellido  |----" << endl;
    cout << "3.----| Nacimiento |----" << endl;
    cout << "4.----|   Salir    |----" << endl;
    cin >> opcion;
    switch (opcion) {
    
    case 1:
        cout << "Ingrese Nombre nuevo" << endl << endl;
        cin >> valor;
        a[editando].setNombre(valor);
        break;
    
    case 2:
        cout << "Ingrese Apellido nuevo" << endl << endl;            //Se pregunta y se ingresan los datos a editar
        cin >> valor;
        a[editando].setApellido(valor);
        break;
     
    case 3:
        cout << "Ingrese Nacimiento nuevo" << endl << endl;
        cin >> valor;
        a[editando].setNacimiento(atoi(valor.c_str()));
        break;
    case 4:
        cout << "Saliendo...." << endl << endl << endl;
    }
}


void eliminarAsistentes(Asistente a[], int &indice) { // Funcion que elimina un asistente de los datos
    Asistente perEliminada;
    string valor;
    int eliminador = 0,eliminando=0;
    cout << "Ingrese numero de asistente a eliminar" << endl; 
    cin >> eliminador;
    for (int i = 0; i < indice; i++) // se recorre el vector
        if (a[i].getNumeroasistente() == eliminador) { 
            cout << "El asistente que esta editando es:  " << a[i].getNombre() << endl; // se obtiene y muestra el nombre del asistente a eliminar segun numero de asistente
            eliminando = i;
            cout << "Confirme ingresando [0]" << endl;   //El metodo usado para eliminar un asistente es bastante similar al editor,
            cin >> valor;                                //con la ayuda del string"valor", se pedia la confirmacion con el ingreso de un 0                  
            if(valor=="0")                               //como se trata de un string se tuvo que usar =="0"
            {
                a[eliminando].setNumeroasistente(atoi(valor.c_str())); //si el "valor" ingresado corresponde a 0, el numero de asistente de la persona
            }                                                          //pasaria a ser un 0
            else
                cout << "Saliendo......." << endl << endl; //caso contrario, simplemente se "Cancelaba" la operacion, sin afectar el numero del asistente
        } 
    //Una vez el asistente figurase con un numero 0 como numero de asistente, este pasaria a "no estar disponible"** pero aun almacenado en el archivo "Datosasistente.exe"
}   //** Vease "Asistente.cpp" linea 45

vector<string> split(string lineaASeparar, char delimitador) {
    vector<string> vector_interno;
    stringstream linea(lineaASeparar);
    string parteDelString;

    while (getline(linea, parteDelString, delimitador))
        vector_interno.push_back(parteDelString);

    return vector_interno;
}
void leerArchivo(string Archivo, Asistente a[], int& indice) { //Funcion para leer y separar el archivo
    ifstream archivo;
    string linea;
    string palabra;

    archivo.open(Archivo, ios::in);

    if (archivo.is_open() == true) {
        while (getline(archivo, linea, '\n')) {
            vector<string> data = split(linea, ';');
            a[indice].setNumeroasistente(atoi(data[0].c_str()));
            a[indice].setNombre(data[1]);                          //Se lee el vector los datos, estos separados por un ";"
            a[indice].setApellido(data[2]);
            a[indice].setNacimiento(atoi(data[3].c_str()));
            a[indice].setGenero(data[4]);
            indice++;
        }
    }
    archivo.close();
}
void guardarDatos(string Archivo, Asistente a[], int indice) { //funcion que guarda datos en archivo
    ofstream archivo;
    archivo.open(Archivo, ios::out);
    if (archivo.is_open() == true) {
        for (int i = 0; i < indice; i++)                       // se recorre con un "for", se obtienen los datos y se les separa con un ";"
            archivo << a[i].getNumeroasistente() << ";" << a[i].getNombre() << ";" << a[i].getApellido() << ";" << a[i].getNacimiento() << ";" << a[i].getGenero() << ";" << endl;

        archivo.close(); //se cierra el archivo

    }
    else
        cout << "|Error|" << endl;
}
