#ifndef _EJERCICIO_H
#define _EJERCICIO_H

#include <iostream>
#include <set>
#include <list>

#include "DTInscripcion.h"
#include "DTEjercicio.h"

using namespace std;

class Inscripcion;

class Ejercicio{
    private:
        int id;
        string frase;
        string descripcion;
        list<Inscripcion*> inscripciones;
    public:
        // Constructores
        Ejercicio();
        Ejercicio(int id, string frase, string descripcion);
        // Getters
        int getId();
        string getFrase();
        string getDescripcion();
        // Obtener el tipo de ejercicio
        virtual string getTipo() = 0;
        // Setters
        void setId(int);
        void setFrase(string);
        void setDescripcion(string);
        void setInscripcion(Inscripcion*);
        // Devuelve un ejercicio no aprobado
        void getEjercicioNoAprobado(list<DTEjercicio>&, Inscripcion*);
        // Devuelve los datos del ejercicio como un DTEjercicio
        virtual DTEjercicio getDataEjercicio() = 0;
        // Verifica si la respuesta ingresada por el usuario es correcta
        virtual bool verificarRespuesta(Inscripcion*, string) = 0;
        //destructor
        virtual ~Ejercicio();
};

#include "Inscripcion.h"

#endif
