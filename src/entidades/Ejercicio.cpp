#include <iostream>
#include <set>
#include <list>
#include "../../include/Ejercicio.h"

using namespace std;

Ejercicio::Ejercicio() {
    this->id = -1;
    this->frase = "";
    this->descripcion = "";
    list<Inscripcion*> inscripciones;
    this->inscripciones = inscripciones;
}

Ejercicio::Ejercicio(int id, string frase, string descripcion) {
    this->id = id;
    this->frase = frase;
    this->descripcion = descripcion;
    list<Inscripcion*> inscripciones;
    this->inscripciones = inscripciones;
} 
 
int Ejercicio::getId() {
    return this->id;
}


string Ejercicio::getFrase() {
    return this->frase;
}

 string Ejercicio::getDescripcion() {
     return this->descripcion;
}
 
void Ejercicio::setId(int id) {
    this->id = id;
}

void Ejercicio::setFrase(string frase) {
    this->frase = frase;
} 

void Ejercicio::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
} 

void Ejercicio::setInscripcion(Inscripcion* i) {
    this->inscripciones.push_back(i);
}
 

 
void Ejercicio::getEjercicioNoAprobado(list<DTEjercicio>& ej, Inscripcion* i) {
    list<Inscripcion*>::iterator it = this->inscripciones.begin();
    while(it != this->inscripciones.end() && (*it) != i)
        it++;

    if(it == this->inscripciones.end())
        ej.push_back(this->getDataEjercicio());
} 
 
//destructor
Ejercicio::~Ejercicio(){
    for(list<Inscripcion*>::iterator it = this->inscripciones.begin(); it != this->inscripciones.end(); it++){
        (*it)->elimEjercicio(this);
    }
    this->inscripciones.clear();
    //borra el ejercicio
}