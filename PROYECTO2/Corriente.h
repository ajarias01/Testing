#ifndef CORRIENTE_H
#define CORRIENTE_H
#include "Cuenta.h"

class Corriente : public Cuenta {
private:
    double limiteSobregiro;
public:
    Corriente();
    Corriente(std::string _dni, std::string _nombre, int _numeroCuenta, double _saldo, std::string _fechaApertura, double _limiteSobregiro);
    void mostrar() const override;
    void guardarEnArchivoBinario(std::ofstream& archivo) const override;
    void guardarEnArchivoTexto(std::ofstream& archivo) const override;
    void cargarDesdeArchivoBinario(std::ifstream& archivo) override;
};

#endif