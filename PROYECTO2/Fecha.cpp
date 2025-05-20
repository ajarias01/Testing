#include "Fecha.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>

Fecha::Fecha() {
    std::time_t tiempo_actual = std::time(nullptr);
    std::tm tm_actual = *std::localtime(&tiempo_actual);
    std::mktime(&tm_actual);
    dia = tm_actual.tm_mday;
    mes = tm_actual.tm_mon + 1;
    anuario = tm_actual.tm_year + 1900;
    hora = tm_actual.tm_hour;
    minutos = tm_actual.tm_min;
    segundos = tm_actual.tm_sec;
}

Fecha::Fecha(int _anuario, int _mes, int _dia) {
    anuario = _anuario;
    set_mes(_mes);
    set_dia(_dia);
    hora = 0;
    minutos = 0;
    segundos = 1;
}

Fecha::Fecha(int _anuario, int _mes, int _dia, int _hora, int _minutos, int _segundos) {
    anuario = _anuario;
    mes = _mes;
    dia = _dia;
    hora = _hora;
    minutos = _minutos;
    segundos = _segundos;
}

int Fecha::get_anuario() { return anuario; }
void Fecha::set_anuario(int nuevo_anuario) { anuario = nuevo_anuario; }
int Fecha::get_mes() { return mes; }

void Fecha::set_mes(int nuevo_mes) {
    int meses_pasados = (nuevo_mes > 12) ? 12 : 0;
    mes = nuevo_mes - meses_pasados;
    if (meses_pasados > 0) set_anuario(anuario + 1);
}

int Fecha::get_dia() { return dia; }

void Fecha::set_dia(int nuevo_dia) {
    int ndias_mes_pasado = 0;
    if (nuevo_dia > 28) {
        if (mes == 2) {
            if (anuario % 4 != 0) {
                ndias_mes_pasado = 28;
            } else {
                ndias_mes_pasado = (nuevo_dia > 29) ? 29 : 0;
            }
        } else if (((mes < 8) && mes % 2 != 0) || (mes >= 8 && mes % 2 == 0)) {
            ndias_mes_pasado = (nuevo_dia > 31) ? 31 : 0;
        } else {
            ndias_mes_pasado = (nuevo_dia > 30) ? 30 : 0;
        }
    }
    dia = nuevo_dia - ndias_mes_pasado;
    if (ndias_mes_pasado > 0) set_mes(mes + 1);
}

int Fecha::get_hora() { return hora; }
void Fecha::set_hora(int nueva_hora) { hora = nueva_hora; }
int Fecha::get_minutos() { return minutos; }
void Fecha::set_minutos(int nuevo_minutos) { minutos = nuevo_minutos; }
int Fecha::get_segundos() { return segundos; }
void Fecha::set_segundos(int nuevo_segundos) { segundos = nuevo_segundos; }

std::string Fecha::to_string() {
    std::tm tm_fecha = {};
    tm_fecha.tm_mday = dia;
    tm_fecha.tm_mon = mes - 1;
    tm_fecha.tm_year = anuario - 1900;
    std::mktime(&tm_fecha);
    std::ostringstream oss;
    oss << std::put_time(&tm_fecha, "%Y-%m-%d");
    return oss.str();
}

std::string Fecha::to_string_documento() {
    std::tm tm_fecha = {};
    tm_fecha.tm_mday = dia;
    tm_fecha.tm_mon = mes - 1;
    tm_fecha.tm_year = anuario - 1900;
    tm_fecha.tm_hour = hora;
    tm_fecha.tm_min = minutos;
    tm_fecha.tm_sec = segundos;
    std::mktime(&tm_fecha);
    std::ostringstream oss;
    oss << std::put_time(&tm_fecha, "%Y-%m-%dT_%H-%M-%SZ");
    return oss.str();
}

std::time_t Fecha::string_to_fecha(const std::string& dateTime) {
    std::tm tm = {};
    std::istringstream ss(dateTime);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) {
        printf("Error: Formato de fecha inválido\n");
        return 0;
    }
    return std::mktime(&tm);
}

void Fecha::imprimir() {
    printf("%02d/%02d/%04d", dia, mes, anuario);
}

bool Fecha::es_dia_habil() {
    return !(es_finde() || es_feriado());
}

bool Fecha::es_feriado() {
    if (mes == 1 && dia == 1) return true;
    if (mes == 2 && (dia == 12 || dia == 13)) return true;
    if (mes == 3 && dia == 29) return true;
    if (mes == 5 && (dia == 1 || dia == 24)) return true;
    if (mes == 8 && dia == 10) return true;
    if (mes == 9 && dia == 26) return true;
    if (mes == 10 && dia == 9) return true;
    if (mes == 11 && (dia == 2 || dia == 3)) return true;
    if (mes == 12 && (dia == 24 || dia == 25 || dia == 31)) return true;
    return false;
}

bool Fecha::es_finde() {
    std::tm tm_fecha = {};
    tm_fecha.tm_mday = dia;
    tm_fecha.tm_mon = mes - 1;
    tm_fecha.tm_year = anuario - 1900;
    std::mktime(&tm_fecha);
    int dia_semana = tm_fecha.tm_wday;
    return (dia_semana == 0 || dia_semana == 6);
}

bool Fecha::operator<(const Fecha& other) {
    if (anuario < other.anuario) return true;
    if (anuario == other.anuario) {
        if (mes < other.mes) return true;
        if (mes == other.mes) {
            if (dia < other.dia) return true;
            if (dia == other.dia) {
                if (hora < other.hora) return true;
                if (hora == other.hora) {
                    if (minutos < other.minutos) return true;
                    if (minutos == other.minutos) {
                        return segundos < other.segundos;
                    }
                }
            }
        }
    }
    return false;
}

bool Fecha::operator>(const Fecha& other) {
    return !(*this < other || *this == other);
}

bool Fecha::operator==(const Fecha& other) {
    return anuario == other.anuario && mes == other.mes && dia == other.dia &&
           hora == other.hora && minutos == other.minutos && segundos == other.segundos;
}