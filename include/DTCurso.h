// Declaración del DTCurso

#ifndef _DTCURSO_H
#define _DTCURSO_H

#include <iostream>
#include <set>
#include <list>
#include "DTIdioma.h"
#include "DTLeccion.h"
#include "DTParEstudianteCurso.h"
#include "TipoDificultad.h"
#include <vector>

using namespace std;

class DTProfesor;

class DTCurso {
    private:
        string nombre;
        string descripcion;
        tipoDificultad dificultad;
        bool habilitado;
        vector<DTLeccion> dataLeccion;
        DTProfesor* dataProfesor;
        list<DTParEstudianteCurso> dataParEstudianteCurso;
        DTIdioma dataIdioma;
    public:
        //Constructores
        DTCurso();
        DTCurso(string, string, tipoDificultad, bool, vector<DTLeccion>, DTProfesor*, list<DTParEstudianteCurso>, DTIdioma);
        //Getters
        string getNombre() const;
        string getDescripcion() const;
        tipoDificultad getTipoDificultad() const;
        bool getHabilitado() const;
        DTIdioma getDataIdioma() const;
        vector<DTLeccion> getDataLeccion() const;
        DTProfesor* getDataProfesor() const;
        list<DTParEstudianteCurso> getDTParEstudianteCurso() const;
        void toStringInscribirseCurso() const;
        void toStringConsultaCurso() const;
};

ostream& operator<<(ostream&,const DTCurso&);

#include "DTProfesor.h"

#endif
