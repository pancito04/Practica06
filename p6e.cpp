#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Alumno{
        string nombre;
        int edad;
        double promedio;
};
class Grupo{
        vector<Alumno>alumnos;
        int cantidad;
};