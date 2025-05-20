#include "Movimiento.h"

Movimiento::Movimiento() {
    monto = 0;
    saldo_post_movimiento = 0;
}

Movimiento::Movimiento(std::string _tipo, double _monto, Fecha _fecha, double _saldo_post) {
    if (_tipo != "Depósito" && _tipo != "Retiro" && _tipo != "Interés") {
        printf("Error: Tipo de movimiento inválido\n");
        return;
    }
    if (_monto <= 0) {
        printf("Error: Monto debe ser mayor a 0\n");
        return;
    }
    tipo = _tipo;
    monto = _monto;
    fecha = _fecha;
    saldo_post_movimiento = _saldo_post;
}

std::string Movimiento::get_tipo() { return tipo; }
double Movimiento::get_monto() { return monto; }
Fecha Movimiento::get_fecha() { return fecha; }
double Movimiento::get_saldo_post_movimiento() { return saldo_post_movimiento; }

void Movimiento::set_tipo(std::string _tipo) { tipo = _tipo; }
void Movimiento::set_monto(double _monto) { monto = _monto; }
void Movimiento::set_fecha(Fecha _fecha) { fecha = _fecha; }
void Movimiento::set_saldo_post_movimiento(double _saldo) { saldo_post_movimiento = _saldo; }

std::string Movimiento::to_string() {
    return "Movimiento: Tipo=" + tipo + ", Monto=" + std::to_string(monto) +
           ", Fecha=" + fecha.to_string() + ", Saldo posterior=" + std::to_string(saldo_post_movimiento);
}

void Movimiento::guardar_binario(FILE* archivo) {
    fwrite(tipo.c_str(), sizeof(char), tipo.length() + 1, archivo);
    fwrite(&monto, sizeof(double), 1, archivo);
    fwrite(&fecha, sizeof(Fecha), 1, archivo);
    fwrite(&saldo_post_movimiento, sizeof(double), 1, archivo);
}

void Movimiento::cargar_binario(FILE* archivo) {
    char buffer[50];
    fread(buffer, sizeof(char), 50, archivo);
    tipo = std::string(buffer);
    fread(&monto, sizeof(double), 1, archivo);
    fread(&fecha, sizeof(Fecha), 1, archivo);
    fread(&saldo_post_movimiento, sizeof(double), 1, archivo);
}