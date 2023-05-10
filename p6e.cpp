#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Alumno {
public:
    string nombre;
    int edad;
    double promedio;

    Alumno(string nombre, int edad, double promedio) {
        this->nombre = nombre;
        this->edad = edad;
        this->promedio = promedio;
    }

    friend ostream& operator<<(ostream& os, const Alumno& alumno);
    friend bool operator<(const Alumno& alumno1, const Alumno& alumno2);
};

ostream& operator<<(ostream& os, const Alumno& alumno) {
    os << "[" << alumno.nombre << ", " << alumno.edad << ", " << alumno.promedio << "]" << endl;
    return os;
}

bool operator<(const Alumno& alumno1, const Alumno& alumno2) {
    return alumno1.promedio < alumno2.promedio;
}

class Grupo{
        vector<Alumno>alumnos;
        int cantidad;
};
