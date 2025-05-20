#include "Corriente.h"
#include <iostream>

Corriente::Corriente() : Cuenta(), limiteSobregiro(0.0) {
    tipoCuenta = "Corriente";
}

Corriente::Corriente(std::string _dni, std::string _nombre, int _numeroCuenta, double _saldo, std::string _fechaApertura, double _limiteSobregiro)
    : Cuenta(_dni, _nombre, _numeroCuenta, _saldo, _fechaApertura, "Corriente"), limiteSobregiro(_limiteSobregiro) {}

void Corriente::mostrar() const {
    std::cout << "Cuenta Corriente - DNI: " << dni << ", Nombre: " << nombre << ", Numero de Cuenta: " << numeroCuenta
              << ", Saldo: " << saldo << ", Fecha Apertura: " << fechaApertura << ", Limite Sobregiro: " << limiteSobregiro << std::endl;
}

void Corriente::guardarEnArchivoBinario(std::ofstream& archivo) const {
    size_t dniSize = dni.size();
    archivo.write((char*)&dniSize, sizeof(dniSize));
    archivo.write(dni.c_str(), dniSize);
    size_t nombreSize = nombre.size();
    archivo.write((char*)&nombreSize, sizeof(nombreSize));
    archivo.write(nombre.c_str(), nombreSize);
    archivo.write((char*)&numeroCuenta, sizeof(numeroCuenta));
    archivo.write((char*)&saldo, sizeof(saldo));
    size_t fechaSize = fechaApertura.size();
    archivo.write((char*)&fechaSize, sizeof(fechaSize));
    archivo.write(fechaApertura.c_str(), fechaSize);
    size_t tipoSize = tipoCuenta.size();
    archivo.write((char*)&tipoSize, sizeof(tipoSize));
    archivo.write(tipoCuenta.c_str(), tipoSize);
    archivo.write((char*)&limiteSobregiro, sizeof(limiteSobregiro));
}

void Corriente::guardarEnArchivoTexto(std::ofstream& archivo) const {
    archivo << "Corriente," << dni << "," << nombre << "," << numeroCuenta << "," << saldo << "," << fechaApertura << "," << limiteSobregiro << "\n";
}

void Corriente::cargarDesdeArchivoBinario(std::ifstream& archivo) {
    size_t dniSize;
    archivo.read((char*)&dniSize, sizeof(dniSize));
    char* buffer = new char[dniSize + 1];
    archivo.read(buffer, dniSize);
    buffer[dniSize] = '\0';
    dni = buffer;
    delete[] buffer;

    size_t nombreSize;
    archivo.read((char*)&nombreSize, sizeof(nombreSize));
    buffer = new char[nombreSize + 1];
    archivo.read(buffer, nombreSize);
    buffer[nombreSize] = '\0';
    nombre = buffer;
    delete[] buffer;

    archivo.read((char*)&numeroCuenta, sizeof(numeroCuenta));
    archivo.read((char*)&saldo, sizeof(saldo));

    size_t fechaSize;
    archivo.read((char*)&fechaSize, sizeof(fechaSize));
    buffer = new char[fechaSize + 1];
    archivo.read(buffer, fechaSize);
    buffer[fechaSize] = '\0';
    fechaApertura = buffer;
    delete[] buffer;

    size_t tipoSize;
    archivo.read((char*)&tipoSize, sizeof(tipoSize));
    buffer = new char[tipoSize + 1];
    archivo.read(buffer, tipoSize);
    buffer[tipoSize] = '\0';
    tipoCuenta = buffer;
    delete[] buffer;

    archivo.read((char*)&limiteSobregiro, sizeof(limiteSobregiro));
}