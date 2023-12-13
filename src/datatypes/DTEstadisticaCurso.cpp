#include "../../include/DTEstadisticaCurso.h"


//constructores
DTEstadisticaCurso::DTEstadisticaCurso(){
    this->promedio = 0;
    this->nombreCurso = "";
}

DTEstadisticaCurso::DTEstadisticaCurso(float p, string nc){
    this->promedio = p;
    this->nombreCurso = nc;
}

//getters
float DTEstadisticaCurso::getPromedio() const{
    return this->promedio;
}

string DTEstadisticaCurso::getNombreCurso() const{
    return this->nombreCurso;
}

//sobrecarga
ostream& operator<<(ostream& os,const DTEstadisticaCurso& est){
    os << " Nombre del curso: " + est.getNombreCurso() << endl;
    os << " Promedio: " << to_string(est.getPromedio()) << endl;
    return os;
} 