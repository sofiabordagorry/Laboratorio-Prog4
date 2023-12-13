#ifndef _DTPROFESOR_H
#define _DTPROFESOR_H

#include <iostream>
#include <list>
#include "DTUsuario.h"
#include "DTIdioma.h"
#include "Idioma.h"
using namespace std;

class DTProfesor: public DTUsuario {
    private:
        string instituto;
        list<string> idiomas;
    public:
        //Constructores
        DTProfesor();
        DTProfesor(string nickname, string contrasenia, string nombre, string descripcion, list<DTNotificacion> notificaciones, string instituto, list<string> idiomas);
        //Getters
        string getInstituto() const;
        list<string> getIdiomas() const;
        void toStringUsuario();
};

ostream& operator<<(ostream&, const DTProfesor&);

#endif
