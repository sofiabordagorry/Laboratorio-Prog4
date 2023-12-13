//Declaracion de la clase 

#ifndef _ESTUDIANTE_H
#define _ESTUDIANTE_H

#include <iostream>
#include <set>
#include <list>
#include "Inscripcion.h" 
#include "Usuario.h"
#include "DTInscripcion.h"
#include "DTEstudiante.h"
#include "DTFecha.h"

using namespace std;

class Estudiante: public Usuario {
    private:
        string paisDeRecidencia;
        DTFecha fechaDeNacimiento;
        list<Inscripcion*> inscripciones;
    public:
        //Constructores
        Estudiante();
        Estudiante(string, DTFecha, string, string, string, string);
        //Getters
        string getPaisDeResidencia();
        DTFecha getFechaDeNacimiento();
        list<Inscripcion*> getInscripciones();
        //Setters
        void setPaisDeResidencia(string);
        void setFechaDeNacimiento(DTFecha);
        void setInscripcion(Inscripcion*);
        //Otras opreaciones
        list<DTCurso> getCursosNoAprobados();
        list<DTEjercicio> buscarInscripcion(string nomCurso);
        DTEstudiante* getDataEstudiante();
        //list<DTCurso> getCursosInscripciones();
        list<DTEstadisticaCurso> getEstadisticaCurso();
        DTUsuario* getDataUsuario();
        void elimInscripcion(Inscripcion*);
        //Destructor
        ~Estudiante();
};

#endif
