/***********************************************************************
 UFA - ESPE
 * Module:  Credito.h
 * Author:  Joan Cobe�a, Edison Verdesoto
 * Modified: jueves, 7 de diciembre de 2023
 * Purpose: Declaracion de clase Credito
 ***********************************************************************/

#ifndef CREDITO_H_INCLUDED
#define CREDITO_H_INCLUDED

#include "Fecha.h"

class Credito{
    public:
        Credito(){};
        Credito(int num_cuotas, double _monto, Fecha, double _tasa_interes);
        int get_n_cuotas_pagar();
        int get_cuotas_pagadas();
        double get_monto();
        double get_saldo();
        double get_valor_cuota();
        void set_n_cuotas_pagar(int);
        void set_cuotas_pagadas(int);
        void set_monto(double);
        void set_saldo(double);
        void set_valor_cuota(double);
        void depositar(double monto);
        bool retirar(double monto);
        void guardar_binario(FILE* archivo);
        void cargar_binario(FILE* archivo);
        int get_meses_gracia();
        int get_intervalo_pagos_mes();
        Fecha get_fecha_realizado();
        void set_meses_gracia(int);
        void set_intervalo_pagos_mes(int);
        double get_tasa_interes();
        void set_tasa_interes(double);
        char* to_string();
    protected:

    private:
        int n_cuotas_pagar;
        int cuotas_pagadas;
        double monto;
        double tasa_interes;
        double saldo;
        double valor_cuota;
        int meses_gracia;
        int intervalo_pagos_mes;
        Fecha fecha_realizado;
};



#endif // CREDITO_H_INCLUDED
