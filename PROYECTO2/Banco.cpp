#include "Banco.h"
#include <stdio.h>

Banco::Banco() {
    clientes = new ListaDoble<Cliente>();
}

void Banco::agregar_cliente(Cliente cliente) {
    if (buscar_cliente(cliente.get_dni())) {
        printf("Error: Cliente ya existe\n");
        return;
    }
    clientes->insertar_cola(cliente);
}

Cliente* Banco::buscar_cliente(std::string dni) {
    Cliente* resultado = nullptr;
    clientes->filtrar(
        [dni](Cliente c) { return c.get_dni() == dni; },
        [&resultado](Cliente c) { resultado = new Cliente(c); }
    );
    return resultado;
}

void Banco::consultar_cuentas_cliente(std::string dni, std::string nombre) {
    printf("Cuentas para DNI=%s o Nombre=%s:\n", dni.c_str(), nombre.c_str());
    clientes->filtrar(
        [dni, nombre](Cliente c) { return c.get_dni() == dni || c.get_nombre() == nombre; },
        [](Cliente c) {
            std::cout << c.to_string() << "\nCuentas:\n";
            c.get_cuentas()->recorrer([](Cuenta cuenta) { std::cout << cuenta.to_string() << std::endl; });
        }
    );
}

void Banco::consultar_movimientos_rango(std::string dni, Fecha inicio, Fecha fin) {
    if (inicio > fin) {
        printf("Error: Rango de fechas inválido\n");
        return;
    }
    Cliente* cliente = buscar_cliente(dni);
    if (!cliente) {
        printf("Error: Cliente no encontrado\n");
        return;
    }
    printf("Movimientos para DNI=%s entre %s y %s:\n", dni.c_str(), inicio.to_string().c_str(), fin.to_string().c_str());
    cliente->get_cuentas()->recorrer([inicio, fin](Cuenta cuenta) { cuenta.consultar_movimientos_rango(inicio, fin); });
    delete cliente;
}

void Banco::calcular_intereses_cuentas(Fecha actual) {
    clientes->recorrer([actual](Cliente c) {
        c.get_cuentas()->recorrer([actual](Cuenta cuenta) {
            if (cuenta.get_tipo() == "Ahorros") {
                cuenta.calcular_intereses_mensuales(actual, 1);
            }
        });
    });
}

void Banco::guardar_datos_binario(std::string archivo) {
    FILE* file = fopen(archivo.c_str(), "wb");
    if (!file) {
        printf("Error: No se pudo abrir el archivo\n");
        return;
    }
    int num_clientes = 0;
    clientes->recorrer([&num_clientes](Cliente) { num_clientes++; });
    fwrite(&num_clientes, sizeof(int), 1, file);
    clientes->recorrer([file](Cliente c) { c.guardar_binario(file); });
    fclose(file);
}

void Banco::cargar_datos_binario(std::string archivo) {
    FILE* file = fopen(archivo.c_str(), "rb");
    if (!file) {
        printf("Error: No se pudo abrir el archivo\n");
        return;
    }
    int num_clientes;
    fread(&num_clientes, sizeof(int), 1, file);
    clientes = new ListaDoble<Cliente>();
    for (int i = 0; i < num_clientes; i++) {
        Cliente cliente;
        cliente.cargar_binario(file);
        clientes->insertar_cola(cliente);
    }
    fclose(file);
}