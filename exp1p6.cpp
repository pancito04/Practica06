#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Estudiante{
        string nombre, codEstudiante;
        double PromFinal;
    public:
        Estudiante(string nombre, string codEstudiante, double PromFinal){
            this->nombre=nombre;
            this->codEstudiante=codEstudiante;
            this->PromFinal=PromFinal;
        }
        string getNombre(){
            return nombre;
        }
        string getCodEstudiante(){
            return codEstudiante;
        }
        double getPromNotas(){
            return PromFinal;
        }
};

int main(){
    int opc;
    double nota;
    vector<Estudiante*>clase;
    Estudiante estudiante1("Luis Torres", "2022250761", 16.3);
    Estudiante estudiante2("Edgardo Rivero", "2022938491", 15.9);
    Estudiante estudiante3("Fernando Rifado", "2022345612", 13.5);
    clase.push_back(& estudiante1);
    clase.push_back(& estudiante2);
    clase.push_back(& estudiante3);
    vector<string>menu={"Que desea?","1. Ver todos los estudiantes.","2. Mostrar los estudiantes que tengan una nota superior a la ingresada", "3. Salir"};
    for (int i=0; i<menu.size();i++)
    {
        cout<<menu[i]<<endl;       
    }
    cin>>opc;
    switch(opc){
        case 1:
            cout<<"Imprimir todos los alumnos: "<<endl;
            for (int i=0; i<=clase.size(); i++){
                cout<<i+1<<". "<<clase[i]->getNombre()<<endl;
                cout<<"  Codigo: "<<clase[i]->getCodEstudiante()<<endl;
                cout<<"  NOTA FINAL: "<<clase[i]->getPromNotas()<<endl;
            }
            break;
        case 2:
            cout<<"Imprimir a los alumnos con nota superior a ";
            cin>>nota;
            for (int i=0; i<=clase.size();i++){
                if (clase[i]->getPromNotas()>nota){
                    cout<<"    El alumno: "<<clase[i]->getNombre()<<" con nota final de "<<clase[i]->getPromNotas()<<endl;
                }
            }
            break;
        case 3:
            cout<<"Fin del programa";
            break;
    }
}