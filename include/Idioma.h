#ifndef _IDIOMA_H
#define _IDIOMA_H

#include <iostream>
#include <list>

#include "DTIdioma.h"
#include "IObserver.h"

using namespace std;

class Curso;

class Idioma{
    private:
        string idioma;
        list<Curso*> cursos;
        list<IObserver*> observers;
    public:
        // Constructores
        Idioma();
        Idioma(string idioma);
        // Destructor
        ~Idioma();
        // Getters
        string getIdioma();
        // Setters
        void setIdioma(string idioma);
        // Devuelve el datatype del idioma
        DTIdioma getDTIdioma();
        void borrarCurso(Curso*);
        // Agrega un curso del idioma
        void agregarCurso(Curso* curso);
        // Verifica la suscripción del usuario u al idioma
        bool verificarSuscripcion(IObserver* u);
        // Elimina una suscripción
        void eliminarSuscripciones(IObserver* o);
        // Suscribe al usuario u al idioma
        void suscribirse(IObserver* u);
};

#include "Curso.h"

#endif
