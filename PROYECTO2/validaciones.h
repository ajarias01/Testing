#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>

int ingresar_enteros(const char* msj);
double ingresar_reales(const char* msj);
std::string ingresar_alfabetico(const char* msj);
int borrar(char* datos, int& i);

#endif