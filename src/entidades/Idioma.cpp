#include <iostream>
#include "../../include/Idioma.h"
#include "../../include/DTNotificacion.h"

using namespace std;

Idioma::Idioma()
{
    this->idioma = "";
    list<Curso*> cursos;
    this->cursos = cursos;
} 

Idioma::Idioma(string idioma)
{
    this->idioma = idioma;
    list<Curso*> cursos;
    this->cursos = cursos;
} 

Idioma::~Idioma() {

}

string Idioma::getIdioma() {
    return this->idioma;
}

void Idioma::setIdioma(string idioma) {
    this->idioma = idioma;
} 

DTIdioma Idioma::getDTIdioma() {
    DTIdioma idioma(this->idioma);
    return idioma;
} 

 void Idioma::agregarCurso(Curso* curso) {
    this->cursos.push_back(curso);
    DTNotificacion n(this->idioma, curso->getNombre());
    for(auto it = this->observers.begin(); it != this->observers.end();it++){
        (*it)->notificar(n);
    }
} 

void Idioma::eliminarSuscripciones(IObserver* o) {
    this->observers.remove(o);
}

void Idioma::borrarCurso(Curso* c) {
    this->cursos.remove(c);
} 

//DESCOMENTADA PARA SUSCRIBIRSE A IDIOMAS
bool Idioma::verificarSuscripcion(IObserver* u) {
    list<IObserver*>::iterator it;
    bool estaSus = false;
    for(it = this->observers.begin(); it != this->observers.end(); it++){
        estaSus = (estaSus || (u == (*it)));
    }
    return estaSus;

}

void Idioma::suscribirse(IObserver* o) {
    this->observers.push_back(o);
}

