#include "../../include/DTFecha.h"

//Constructor por defecto
DTFecha::DTFecha() {
    this->dia = 0;
    this->mes = 0;
    this->anio = 0;
}

//Constructor por parametros
DTFecha::DTFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

//Constructor por copia
DTFecha::DTFecha(const DTFecha& fecha) {
    this->dia = fecha.dia;
    this->mes = fecha.mes;
    this->anio = fecha.anio;
}

//Getters
int DTFecha::getDia() const{
    return this->dia;
}

int DTFecha::getMes() const{
    return this->mes;
}

int DTFecha::getAnio() const{
    return this->anio;
}

//Sobrecarga de operadores;
 bool DTFecha::operator==(DTFecha& fecha) {
    return this->dia == fecha.getDia() && this->mes == fecha.getMes() && this->anio == fecha.getAnio();
} 

 bool DTFecha::operator!=(DTFecha& fecha) {
    return this->dia != fecha.getDia() || this->mes != fecha.getMes() || this->anio != fecha.getAnio(); 
} 

ostream& operator<<(ostream& os,const DTFecha& fecha) {
    os << to_string(fecha.getDia()) + "/" + to_string(fecha.getMes()) + "/" + to_string(fecha.getAnio());
    return os;
}
