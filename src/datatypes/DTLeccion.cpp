#include "../../include/DTLeccion.h"

//Constructor por defecto
 DTLeccion::DTLeccion() {
    this->id = 0;
    this->tema = "";
    this->objetivo = "";
    list<DTEjercicio> dataEjercicio;
    this->dataEjercicio = dataEjercicio;
}
 
//Constructor por parametros
DTLeccion::DTLeccion(int id, string tema, string objetivo, list<DTEjercicio> dataEjercicio) {
    this->id = id;
    this->tema = tema;
    this->objetivo = objetivo;
    this->dataEjercicio = dataEjercicio;    
}

//Getters
 int DTLeccion::getId() const{
    return this->id;
} 

 string DTLeccion::getTema() const{
    return this->tema;
} 

 string DTLeccion::getObjetivo() const{
    return this->objetivo;
} 

 list<DTEjercicio> DTLeccion::getDataEjercicio() const{
    return this->dataEjercicio;
} 

 void DTLeccion::toStringConsultaCurso() const { 
    cout << " -Leccion: " + to_string(this->getId()) << endl;
    cout << "  Tema: " + this->getTema() << endl;
    cout << "  Objetivo: " + this->getObjetivo() << endl;
    for(list<DTEjercicio>::const_iterator it = this->dataEjercicio.begin(); it != this->dataEjercicio.end(); ++it)
        it->toStringConsultaCurso();
} 

//Sobrecarga de operadores
 ostream& operator<<(ostream& os,const DTLeccion& leccion) {
    os << "Numero leccion: " + to_string(leccion.getId()) << endl;
    os << "Tema: " + leccion.getTema() << endl;
    os << "Objetivo: " + leccion.getObjetivo() << endl;
    return os;
} 