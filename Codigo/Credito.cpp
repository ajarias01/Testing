/***********************************************************************
 UFA - ESPE
 * Module:  Credito.cpp
 * Author:  Joan Cobe�a, Edison Verdesoto
 * Modified: jueves, 7 de diciembre de 2023
 * Purpose: Implementacion de clase Credito
 ***********************************************************************/

#include "Credito.h"

Credito::Credito(int num_cuotas, double _monto, Fecha _fecha_realizado, double _tasa_interes){
    n_cuotas_pagar = num_cuotas;
    monto = _monto;
    meses_gracia = 1;
    intervalo_pagos_mes = 1;
    fecha_realizado = _fecha_realizado;
    tasa_interes = _tasa_interes;
}

int Credito::get_n_cuotas_pagar(){
    return n_cuotas_pagar;
}

int Credito::get_cuotas_pagadas(){
    return cuotas_pagadas;
}

double Credito::get_monto(){
    return monto;
}

double Credito::get_saldo(){
    return saldo;
}

double Credito::get_valor_cuota(){
    return valor_cuota;
}

void Credito::set_n_cuotas_pagar(int nuevo_n_cuotas_pagar){
    n_cuotas_pagar = nuevo_n_cuotas_pagar;
}

void Credito::set_cuotas_pagadas(int nuevo_cuotas_pagadas){
    cuotas_pagadas = nuevo_cuotas_pagadas;
}

void Credito::set_monto(double nuevo_monto){
    monto = nuevo_monto;
}

void Credito::set_saldo(double nuevo_saldo){
    saldo = nuevo_saldo;
}

void Credito::set_valor_cuota(double nuevo_valor_cuota){
    valor_cuota = nuevo_valor_cuota;
}

int Credito::get_meses_gracia(){
    return meses_gracia;
}

int Credito::get_intervalo_pagos_mes(){
    return intervalo_pagos_mes;
}

Fecha Credito::get_fecha_realizado(){
    return fecha_realizado;
}

double Credito::get_tasa_interes(){
    return tasa_interes;
}

void Credito::set_tasa_interes(double nueva_tasa){
    tasa_interes = nueva_tasa;
}

char* Credito::to_string(){

}
void Credito::depositar(double monto){
    saldo += monto;
}

bool Credito::retirar(double monto){
    if(saldo >= monto){
        saldo -= monto;
        return true;
    }
    return false;
}

void Credito::guardar_binario(FILE* archivo){
    fwrite(this, sizeof(Credito), 1, archivo);
}

void Credito::cargar_binario(FILE* archivo){
    fread(this, sizeof(Credito), 1, archivo);
}
