#ifndef AHORRO_H
#define AHORRO_H
#include "Cuenta.h"

class Ahorro : public Cuenta {
private:
    double tasaInteres;
public:
    Ahorro();
    Ahorro(std::string _dni, std::string _nombre, int _numeroCuenta, double _saldo, std::string _fechaApertura, double _tasaInteres);
    void mostrar() const override;
    void guardarEnArchivoBinario(std::ofstream& archivo) const override;
    void guardarEnArchivoTexto(std::ofstream& archivo) const override;
    void cargarDesdeArchivoBinario(std::ifstream& archivo) override;
};

#endif