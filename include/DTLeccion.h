// Declaración del DTFecha

#ifndef _DTLECCION_H
#define _DTLECCION_H

#include <iostream>
#include <list>
#include "DTEjercicio.h"
using namespace std;

class DTLeccion {
    private:
        int id;
        string tema;
        string objetivo;
        list<DTEjercicio> dataEjercicio;
    public:
        //Constructores
        DTLeccion();
        DTLeccion(int, string, string, list<DTEjercicio>);
        //Getters
        int getId() const;
        string getTema() const;
        string getObjetivo() const;
        list<DTEjercicio> getDataEjercicio() const;
        void toStringConsultaCurso() const;
};

ostream& operator<<(ostream& os,const DTLeccion& leccion);

#endif