#include "Cuenta.h"
#include <cmath>

Cuenta::Cuenta() {
    id_cuenta = 0;
    tipo = "";
    saldo = 0;
    tasa_interes = 0;
    movimientos = new ListaDoble<Movimiento>();
}

Cuenta::Cuenta(int id, std::string _tipo, double saldo_inicial, Fecha fecha, double _tasa_interes) {
    if (id <= 0) {
        printf("Error: ID de cuenta inválido\n");
        return;
    }
    if (_tipo != "Ahorros" && _tipo != "Corriente") {
        printf("Error: Tipo de cuenta inválido\n");
        return;
    }
    if (saldo_inicial < 0) {
        printf("Error: Saldo inicial no puede ser negativo\n");
        return;
    }
    if (_tasa_interes < 0 || _tasa_interes > 100) {
        printf("Error: Tasa de interés inválida\n");
        return;
    }
    id_cuenta = id;
    tipo = _tipo;
    saldo = saldo_inicial;
    fecha_apertura = fecha;
    tasa_interes = _tasa_interes;
    movimientos = new ListaDoble<Movimiento>();
}

int Cuenta::get_id_cuenta() { return id_cuenta; }
std::string Cuenta::get_tipo() { return tipo; }
double Cuenta::get_saldo() { return saldo; }
Fecha Cuenta::get_fecha_apertura() { return fecha_apertura; }
double Cuenta::get_tasa_interes() { return tasa_interes; }
ListaDoble<Movimiento>* Cuenta::get_movimientos() { return movimientos; }

void Cuenta::set_id_cuenta(int id) { id_cuenta = id; }
void Cuenta::set_tipo(std::string _tipo) { tipo = _tipo; }
void Cuenta::set_saldo(double _saldo) { saldo = _saldo; }
void Cuenta::set_fecha_apertura(Fecha fecha) { fecha_apertura = fecha; }
void Cuenta::set_tasa_interes(double _tasa) { tasa_interes = _tasa; }

void Cuenta::depositar(double monto, Fecha fecha) {
    if (monto <= 0) {
        printf("Error: Monto de depósito debe ser mayor a 0\n");
        return;
    }
    if (!fecha.es_dia_habil()) {
        printf("Error: Depósito no permitido en día no hábil\n");
        return;
    }
    saldo += monto;
    Movimiento movimiento("Depósito", monto, fecha, saldo);
    movimientos->insertar_cola(movimiento);
}

bool Cuenta::retirar(double monto, Fecha fecha) {
    if (monto <= 0) {
        printf("Error: Monto de retiro debe ser mayor a 0\n");
        return false;
    }
    if (saldo < monto) {
        printf("Error: Saldo insuficiente\n");
        return false;
    }
    if (!fecha.es_dia_habil()) {
        printf("Error: Retiro no permitido en día no hábil\n");
        return false;
    }
    saldo -= monto;
    Movimiento movimiento("Retiro", monto, fecha, saldo);
    movimientos->insertar_cola(movimiento);
    return true;
}

double Cuenta::consultar_saldo() {
    return saldo;
}

void Cuenta::consultar_movimientos_rango(Fecha inicio, Fecha fin) {
    if (inicio > fin) {
        printf("Error: Rango de fechas inválido\n");
        return;
    }
    printf("Movimientos de la cuenta %d entre %s y %s:\n", id_cuenta, inicio.to_string().c_str(), fin.to_string().c_str());
    movimientos->filtrar(
        [inicio, fin](const Movimiento& m) { return m.get_fecha() >= inicio && m.get_fecha() <= fin; },
        [](const Movimiento& m) { std::cout << m.to_string() << std::endl; }
    );
}
void Cuenta::calcular_intereses_mensuales(Fecha actual, int meses) {
    if (tipo != "Ahorros" || meses <= 0) return;
    double interes = saldo * (tasa_interes / (100.0 * 12)); // Interés mensual
    saldo += interes;
    Movimiento movimiento("Interés", interes, actual, saldo);
    movimientos->insertar_cola(movimiento);
    if (meses > 1) {
        Fecha nueva_fecha = actual;
        nueva_fecha.set_mes(actual.get_mes() + 1);
        calcular_intereses_mensuales(nueva_fecha, meses - 1); // Recursión
    }
}

std::string Cuenta::to_string() {
    std::string result = "Cuenta: ID=" + std::to_string(id_cuenta) + ", Tipo=" + tipo +
                         ", Saldo=" + std::to_string(saldo) + ", Fecha Apertura=" + fecha_apertura.to_string();
    return result;
}

void Cuenta::guardar_binario(FILE* archivo) {
    fwrite(&id_cuenta, sizeof(int), 1, archivo);
    fwrite(tipo.c_str(), sizeof(char), tipo.length() + 1, archivo);
    fwrite(&saldo, sizeof(double), 1, archivo);
    fwrite(&fecha_apertura, sizeof(Fecha), 1, archivo);
    fwrite(&tasa_interes, sizeof(double), 1, archivo);
    int num_movimientos = 0;
    movimientos->recorrer([&num_movimientos](Movimiento) { num_movimientos++; });
    fwrite(&num_movimientos, sizeof(int), 1, archivo);
    movimientos->recorrer([archivo](Movimiento m) { m.guardar_binario(archivo); });
}

void Cuenta::cargar_binario(FILE* archivo) {
    char buffer[50];
    fread(&id_cuenta, sizeof(int), 1, archivo);
    fread(buffer, sizeof(char), 50, archivo);
    tipo = std::string(buffer);
    fread(&saldo, sizeof(double), 1, archivo);
    fread(&fecha_apertura, sizeof(Fecha), 1, archivo);
    fread(&tasa_interes, sizeof(double), 1, archivo);
    int num_movimientos;
    fread(&num_movimientos, sizeof(int), 1, archivo);
    movimientos = new ListaDoble<Movimiento>();
    for (int i = 0; i < num_movimientos; i++) {
        Movimiento movimiento;
        movimiento.cargar_binario(archivo);
        movimientos->insertar_cola(movimiento);
    }
}