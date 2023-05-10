#include<iostream>
#include<cmath>
using namespace std;
class Circulo{
        double radio;
    public:
        Circulo(double radio){
            this->radio=radio;
        }
        friend void calcularArea(Circulo& objeto){
            cout<<"El area del circulo es: "<<M_PI*pow(objeto.radio,2)<<endl;
        }
};
int main(){
    double rad;
    cout<<"Ingrese el radio del circulo: ";
    cin>>rad;
    Circulo circulo1(rad);
    calcularArea(circulo1);
    return 0;
}