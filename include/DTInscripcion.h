// Declaracion del DTInscripcion

#ifndef _DTINSCRIPCION_H
#define _DTINSCRIPCION_H

#include <iostream>
#include "DTFecha.h"

using namespace std;

class DTInscripcion {
    private:
		  DTFecha fecha;
		  bool aprobado; 
    public:
        //Constructores
        DTInscripcion();
        DTInscripcion(bool, DTFecha);
        //Getters
        bool getAprobado() const;
        DTFecha getFecha() const;
};

ostream& operator<<(ostream& os, const DTInscripcion& incripcion);

#endif
