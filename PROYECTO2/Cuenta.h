#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED

#include "Movimiento.h"
#include "Fecha.h"
#include "ListaDoble.h"
#include <string>
#include <functional>

class Cuenta {
public:
    Cuenta();
    Cuenta(int id, std::string tipo, double saldo_inicial, Fecha fecha, double tasa_interes);
    int get_id_cuenta();
    std::string get_tipo();
    double get_saldo();
    Fecha get_fecha_apertura();
    double get_tasa_interes();
    ListaDoble<Movimiento>* get_movimientos();
    void set_id_cuenta(int);
    void set_tipo(std::string);
    void set_saldo(double);
    void set_fecha_apertura(Fecha);
    void set_tasa_interes(double);
    void depositar(double monto, Fecha fecha);
    bool retirar(double monto, Fecha fecha);
    double consultar_saldo();
    void consultar_movimientos_rango(Fecha inicio, Fecha fin);
    void calcular_intereses_mensuales(Fecha actual, int meses);
    std::string to_string();
    void guardar_binario(FILE* archivo);
    void cargar_binario(FILE* archivo);
private:
    int id_cuenta;
    std::string tipo;
    double saldo;
    Fecha fecha_apertura;
    double tasa_interes;
    ListaDoble<Movimiento>* movimientos;
};

#endif