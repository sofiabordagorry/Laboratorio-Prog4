// Declaración del DTEstudiante

#ifndef _DTESTUDIANTE_H
#define _DTESTUDIANTE_H

#include <iostream>
#include <set>
#include <list>
#include "DTUsuario.h"
#include "DTFecha.h"

using namespace std;

class DTEstudiante: public DTUsuario {
    private:
    	string paisDeResidencia;
    	DTFecha fechaDeNacimiento; 
    public:
        //Constructores
        DTEstudiante();
        DTEstudiante(string nickname, string password, string nombre, string descripcion, list<DTNotificacion> notificaciones, string pais, DTFecha fechaDeNacimiento);
        //Getters
        string getPaisDeResidencia() const;
        DTFecha getFechaDeNacimiento() const;
        void toStringUsuario();
};

#endif
