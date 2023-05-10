#include <iostream>
#include <string>
using namespace std;

class Banco {
private:
    static double tasaDeInteres;    //Creacion de atributo estatico

public:
    //Creacion de métodos estaticos 
    static void setTasaDeInteres(double nuevaTasa) {
        tasaDeInteres = nuevaTasa;
    }

    static double getTasaDeInteres() {
        return tasaDeInteres;
    }
};

double Banco::tasaDeInteres = 0;

class CuentaBancaria {
private:
    double saldo;

public:
    CuentaBancaria(double saldoInicial = 0) : saldo(saldoInicial) {}

    void depositar(double cantidad) {
        saldo += cantidad;
    }

    void retirar(double cantidad) {
        if (saldo >= cantidad) {
            saldo -= cantidad;
        } else {
            cout << "Saldo insuficiente" << endl;
        }
    }

    double calcularInteresGanado() const {
        return saldo * Banco::getTasaDeInteres();
    }

    double obtenerSaldo() const {
        return saldo;
    }
};

int main() {
    Banco::setTasaDeInteres(0.05);  // Tasa de interes del 5%

    // Cracion de la cuenta bancaria y realizar operaciones
    CuentaBancaria cuenta(1000);
    cuenta.depositar(500);
    cuenta.retirar(200);

    // Calculo del interes ganado por la cuenta
    double interesGanado = cuenta.calcularInteresGanado();

    cout << "Saldo actual: S/" << cuenta.obtenerSaldo() << endl;
    cout << "Interés ganado: S/" << interesGanado << endl;

    return 0;
}
