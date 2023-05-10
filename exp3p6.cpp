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

class Grupo {
public:
    static int size1;
    vector<Alumno> alumnos;
    int cantidad;
    
    Grupo() {
        cantidad = 0;
    }


    void agregarAlumno(string nombre, int edad, double promedio) {
        if (size1 > cantidad){
            Alumno nuevoAlumno(nombre, edad, promedio);
            alumnos.push_back(nuevoAlumno);
            cantidad++;
        }

        else{
            cout << "Se ha intentado crear mas de "<<size1<<" objetos." <<endl;
        }

    }

    void mostrarAlumnos() {
        for (int i = 0; i < cantidad; i++) {
            cout <<"Nommbre: "<< alumnos[i].nombre << " Edad: " << alumnos[i].edad << " Nota: " << alumnos[i].promedio << endl;
        }
    }

    void ordenarPorPromedio() {
        for (int i = 0; i < cantidad; i++) {
            for (int j = i + 1; j < cantidad; j++) {
                if (alumnos[j].promedio < alumnos[i].promedio) {
                    swap(alumnos[i], alumnos[j]);
                }
            }
        }
    }

    double promedioPromedios() {
        double sumaPromedios = 0.0;
        for (int i = 0; i < cantidad; i++) {
            sumaPromedios += alumnos[i].promedio;
        }
        return sumaPromedios / cantidad;
    }

    Alumno mejorPromedio() {
        Alumno mejor = alumnos[0];
        for (int i = 1; i < cantidad; i++) {
            if (alumnos[i].promedio > mejor.promedio) {
                mejor = alumnos[i];
            }
        }
        return mejor;
    }
};

int Grupo::size1 =5;

int main() {
    Grupo grupo;
    grupo.agregarAlumno("Juan", 18, 17);
    grupo.agregarAlumno("Guchi", 19, 11);
    grupo.agregarAlumno("Luis", 20, 14);
    grupo.agregarAlumno("Kikin", 18, 16);
    grupo.agregarAlumno("Chorosor",19,19);
    grupo.agregarAlumno("Juli0", 19, 19);

    cout << "Alumnos: " << endl<<"====================================="<< endl;
    grupo.mostrarAlumnos();
    cout <<"====================================="<< endl;
    grupo.ordenarPorPromedio();
    cout << "Alumnos ordenados por promedio: " << endl;
    for (int i = 0; i < grupo.cantidad; i++) {
        cout << grupo.alumnos[i];
    }
    cout <<"====================================="<< endl;
    cout << "Promedio de todos los promedios: "<< grupo.promedioPromedios() << endl;

    Alumno mejorPromedio = grupo.mejorPromedio();
    cout << "Mejor promedio: "<< endl <<"Nombre: " << mejorPromedio.nombre << " Edad: " << mejorPromedio.edad << " Nota: " << mejorPromedio.promedio<<endl;

    return 0;
}
