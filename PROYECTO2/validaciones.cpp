#include "Validaciones.h"

int ingresar_enteros(const char* msj) {
    char* datos = new char[10];
    char c;
    int i = 0;
    printf("%s\n", msj);
    while ((c = getch()) != 13) {
        if (c == 8 || i < 9) {
            if ((c >= '0' && c <= '9') || c == 8) {
                if (c == 8) {
                    i = borrar(datos, i);
                } else {
                    printf("%c", c);
                    datos[i++] = c;
                }
            }
        }
    }
    datos[i] = '\0';
    int result = atoi(datos);
    delete[] datos;
    if (result == 0 && datos[0] != '0') {
        printf("Error: Entrada numérica inválida\n");
        return 0;
    }
    return result;
}

double ingresar_reales(const char* msj) {
    char* datos = new char[12];
    char c;
    int i = 0;
    bool hay_punto = false;
    int posicion_punto;
    printf("%s\n", msj);
    while ((c = getch()) != 13) {
        if (c == 8 || i < 11) {
            if ((c >= '0' && c <= '9') || (c == '.' && !hay_punto) || c == 8 || c == '-') {
                if (!((c == '.') && i == 0)) {
                    if (!((c == '-') && i != 0)) {
                        if (c == 8) {
                            i = borrar(datos, i);
                            if ((i + 1) == posicion_punto) {
                                hay_punto = false;
                            }
                        } else {
                            printf("%c", c);
                            datos[i++] = c;
                            if (c == '.') {
                                posicion_punto = i;
                                hay_punto = true;
                            }
                        }
                    }
                }
            }
        }
    }
    datos[i] = '\0';
    double result = atof(datos);
    delete[] datos;
    if (result == 0 && datos[0] != '0' && datos[0] != '.') {
        printf("Error: Entrada numérica inválida\n");
        return 0;
    }
    return result;
}

std::string ingresar_alfabetico(const char* msj) {
    char datos[50];
    char c;
    int i = 0;
    printf("%s\n", msj);
    while ((c = getch()) != 13 && i < 49) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == 32 || c == 8) {
            if (c == 8) {
                i = borrar(datos, i);
            } else {
                printf("%c", c);
                datos[i++] = c;
            }
        }
    }
    datos[i] = '\0';
    std::string result = std::string(datos);
    if (result.empty()) {
        printf("Error: Entrada alfabética vacía\n");
        return "";
    }
    return result;
}

int borrar(char* datos, int& i) {
    if (i > 0) {
        printf("\b \b");
        i--;
        datos[i] = '\0';
        return i;
    }
    return 0;
}