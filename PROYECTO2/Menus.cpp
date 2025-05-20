#include "Menus.h"

void visibilidad_cursor(bool visible) {
    HANDLE manejo_consola = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 1;
    info.bVisible = visible;
    SetConsoleCursorInfo(manejo_consola, &info);
}

void mover_cursor(int x, int y) {
    HANDLE manejo_consola = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(manejo_consola, pos);
}

int desplegar_menu(const char** opciones, int nopciones) {
    const short int ANCHO_BOTON = 35;
    visibilidad_cursor(false);
    char tecla;
    HANDLE manejo_consola = GetStdHandle(STD_OUTPUT_HANDLE);
    short int cursor_x = 0, cursor_y = 1, color_act = 0, opcion = 1;
    int colores[2] = {15, 191};

    void imprimir_opciones() {
        void imprimir_boton(const char* opcion) {
            short int caracteres_en_opcion = 0;
            while (opcion[caracteres_en_opcion] != '\0') {
                caracteres_en_opcion++;
            }
            int espacios_faltantes = ANCHO_BOTON - caracteres_en_opcion;
            for (short int i = 0; i < ANCHO_BOTON; i++) {
                printf("%c", ' ');
            }
            printf("\n");
            for (short int i = 0; i < espacios_faltantes / 2; i++) {
                printf("%c", ' ');
            }
            printf("%s", opcion);
            if (espacios_faltantes % 2 == 0) {
                for (short int i = 0; i < espacios_faltantes / 2; i++) {
                    printf("%c", ' ');
                }
            } else {
                for (short int i = 0; i < (espacios_faltantes / 2) + 1; i++) {
                    printf("%c", ' ');
                }
            }
            printf("\n");
            for (short int i = 0; i < ANCHO_BOTON; i++) {
                printf("%c", ' ');
            }
        }

        for (int i = 0; i < nopciones; i++) {
            color_act = (i * 3) + 1 == cursor_y ? 1 : 0;
            mover_cursor(cursor_x, (i * 3));
            SetConsoleTextAttribute(manejo_consola, colores[color_act]);
            imprimir_boton(opciones[i]);
        }
        SetConsoleTextAttribute(manejo_consola, colores[0]);
    };

    imprimir_opciones();
    while ((tecla = getch()) != 13) {
        if (tecla == 72 && opcion > 1) cursor_y -= 3;
        else if (tecla == 80 && opcion < nopciones) cursor_y += 3;
        imprimir_opciones();
        mover_cursor(cursor_x, cursor_y);
        opcion = ((cursor_y - 1) / 3) + 1;
    }
    return opcion;
}

void desplegar_menu_principal(Banco& banco) {
    const int NUM_OPCIONES = 7;
    const char* OPCIONES[NUM_OPCIONES] = {
        "Abrir cuenta",
        "Realizar depósito",
        "Realizar retiro",
        "Consultar movimientos por fecha",
        "Consultar cuentas por DNI/nombre",
        "Calcular intereses mensuales",
        "Guardar/Cargar datos"
    };

    int opcion;
    do {
        system("cls");
        opcion = desplegar_menu(OPCIONES, NUM_OPCIONES);
        switch (opcion) {
            case 1: abrir_cuenta(banco); break;
            case 2: realizar_deposito(banco); break;
            case 3: realizar_retiro(banco); break;
            case 4: consultar_movimientos(banco); break;
            case 5: consultar_cuentas(banco); break;
            case 6: calcular_intereses(banco); break;
            case 7: guardar_datos(banco); cargar_datos(banco); break;
        }
    } while (opcion != NUM_OPCIONES + 1);
}

void abrir_cuenta(Banco& banco) {
    system("cls");
    visibilidad_cursor(true);
    std::string dni = ingresar_alfabetico("Ingrese el DNI del cliente");
    if (dni.empty()) return;
    std::string nombre = ingresar_alfabetico("Ingrese el nombre del cliente");
    if (nombre.empty()) return;
    std::string direccion = ingresar_alfabetico("Ingrese la dirección del cliente");
    std::string telefono = ingresar_alfabetico("Ingrese el teléfono del cliente");
    std::string email = ingresar_alfabetico("Ingrese el email del cliente");
    int anio = ingresar_enteros("Ingrese el año de nacimiento");
    int mes = ingresar_enteros("Ingrese el mes de nacimiento");
    int dia = ingresar_enteros("Ingrese el día de nacimiento");
    Fecha fecha_nacimiento(anio, mes, dia);
    std::string estado_civil = ingresar_alfabetico("Ingrese el estado civil");
    std::string nif = ingresar_alfabetico("Ingrese el número de identificación fiscal");
    int id_cuenta = ingresar_enteros("Ingrese el ID de la cuenta");
    std::string tipo = ingresar_alfabetico("Ingrese el tipo de cuenta (Ahorros/Corriente)");
    double saldo_inicial = ingresar_reales("Ingrese el saldo inicial");
    double tasa_interes = tipo == "Ahorros" ? ingresar_reales("Ingrese la tasa de interés anual (%)") : 0;
    Fecha fecha_apertura;
    Cliente cliente(dni, nombre, direccion, telefono, email, fecha_nacimiento, estado_civil, nif);
    Cuenta cuenta(id_cuenta, tipo, saldo_inicial, fecha_apertura, tasa_interes);
    Cliente* cliente_existente = banco.buscar_cliente(dni);
    if (cliente_existente) {
        cliente_existente->agregar_cuenta(cuenta);
        delete cliente_existente;
    } else {
        cliente.agregar_cuenta(cuenta);
        banco.agregar_cliente(cliente);
    }
    printf("Cuenta creada exitosamente.\n");
    system("pause");
}

void realizar_deposito(Banco& banco) {
    system("cls");
    visibilidad_cursor(true);
    std::string dni = ingresar_alfabetico("Ingrese el DNI del cliente");
    if (dni.empty()) return;
    int id_cuenta = ingresar_enteros("Ingrese el ID de la cuenta");
    double monto = ingresar_reales("Ingrese el monto a depositar");
    Fecha fecha;
    Cliente* cliente = banco.buscar_cliente(dni);
    if (!cliente) {
        printf("Error: Cliente no encontrado\n");
        system("pause");
        return;
    }
    Cuenta* cuenta = cliente->buscar_cuenta(id_cuenta);
    if (!cuenta) {
        printf("Error: Cuenta no encontrada\n");
        delete cliente;
        system("pause");
        return;
    }
    cuenta->depositar(monto, fecha);
    printf("Depósito realizado exitosamente.\n");
    delete cuenta;
    delete cliente;
    system("pause");
}

void realizar_retiro(Banco& banco) {
    system("cls");
    visibilidad_cursor(true);
    std::string dni = ingresar_alfabetico("Ingrese el DNI del cliente");
    if (dni.empty()) return;
    int id_cuenta = ingresar_enteros("Ingrese el ID de la cuenta");
    double monto = ingresar_reales("Ingrese el monto a retirar");
    Fecha fecha;
    Cliente* cliente = banco.buscar_cliente(dni);
    if (!cliente) {
        printf("Error: Cliente no encontrado\n");
        system("pause");
        return;
    }
    Cuenta* cuenta = cliente->buscar_cuenta(id_cuenta);
    if (!cuenta) {
        printf("Error: Cuenta no encontrada\n");
        delete cliente;
        system("pause");
        return;
    }
    if (cuenta->retirar(monto, fecha)) {
        printf("Retiro realizado exitosamente.\n");
    }
    delete cuenta;
    delete cliente;
    system("pause");
}

void consultar_movimientos(Banco& banco) {
    system("cls");
    visibilidad_cursor(true);
    std::string dni = ingresar_alfabetico("Ingrese el DNI del cliente");
    if (dni.empty()) return;
    std::string fecha_inicio_str = ingresar_alfabetico("Ingrese la fecha inicial (YYYY-MM-DD)");
    std::string fecha_fin_str = ingresar_alfabetico("Ingrese la fecha final (YYYY-MM-DD)");
    Fecha inicio, fin;
    std::time_t t_inicio = inicio.string_to_fecha(fecha_inicio_str);
    std::time_t t_fin = fin.string_to_fecha(fecha_fin_str);
    if (t_inicio == 0 || t_fin == 0) return;
    std::tm* tm_inicio = std::localtime(&t_inicio);
    std::tm* tm_fin = std::localtime(&t_fin);
    inicio = Fecha(tm_inicio->tm_year + 1900, tm_inicio->tm_mon + 1, tm_inicio->tm_mday);
    fin = Fecha(tm_fin->tm_year + 1900, tm_fin->tm_mon + 1, tm_fin->tm_mday);
    banco.consultar_movimientos_rango(dni, inicio, fin);
    system("pause");
}

void consultar_cuentas(Banco& banco) {
    system("cls");
    visibilidad_cursor(true);
    std::string dni = ingresar_alfabetico("Ingrese el DNI del cliente (o deje vacío)");
    std::string nombre = ingresar_alfabetico("Ingrese el nombre del cliente (o deje vacío)");
    banco.consultar_cuentas_cliente(dni, nombre);
    system("pause");
}

void calcular_intereses(Banco& banco) {
    system("cls");
    visibilidad_cursor(true);
    Fecha actual;
    banco.calcular_intereses_cuentas(actual);
    printf("Intereses mensuales calculados para todas las cuentas de ahorros.\n");
    system("pause");
}

void guardar_datos(Banco& banco) {
    system("cls");
    visibilidad_cursor(true);
    std::string archivo = ingresar_alfabetico("Ingrese el nombre del archivo para guardar");
    banco.guardar_datos_binario(archivo);
    printf("Datos guardados exitosamente.\n");
    system("pause");
}

void cargar_datos(Banco& banco) {
    system("cls");
    visibilidad_cursor(true);
    std::string archivo = ingresar_alfabetico("Ingrese el nombre del archivo para cargar");
    banco.cargar_datos_binario(archivo);
    printf("Datos cargados exitosamente.\n");
    system("pause");
}