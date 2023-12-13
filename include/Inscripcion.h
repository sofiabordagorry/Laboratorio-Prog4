// Declaración de la clase Inscripcion

#ifndef _INSCRIPCION_H
#define _INSCRIPCION_H

#include <iostream>
#include <set>
#include <list>
#include "DTFecha.h"
#include "DTInscripcion.h"
#include "DTEstadisticaCurso.h"
#include "DTCurso.h"
#include "DTEjercicio.h"

using namespace std;

//class Ejercicio;
class Estudiante;
class Curso;
class Ejercicio;

class Inscripcion {
     private:
        DTFecha fecha;
        bool aprobado;
        Curso* curso;
        Estudiante* estudiante;
        list<Ejercicio*> ejerciciosAprobados;
    public: 
        //Constructores
        Inscripcion();
        Inscripcion(DTFecha, bool, Curso*, Estudiante*);
        //Getters
        DTFecha getFecha();
        bool getAprobado();
        Curso* getCurso();
        Estudiante* getEstudiante();
        list<Ejercicio*> getEjerciciosAprobados();
        // //Setters
        void setFecha(DTFecha);
        void setAprobado(bool);
        void setCurso(Curso*);
        void setEstudiante(Estudiante*);
        void setEjercicioAprobado(Ejercicio* );
        // //Otras operaciones
        void verificarAprobacion(string nickname, bool& estaEst);
        void verificarInscripcion(string nickname, bool& noEstaEst);
        DTCurso getDataCurso();
        DTEstadisticaCurso getPromedioCurso();
        bool buscarCurso(string nomCurso, list<DTEjercicio>&, Inscripcion*);
        // DTLeccion getLeccionActual();
        int cantEjAprobados();
        void elimEjercicio(Ejercicio*); 
        DTInscripcion getDataInscripcion();
        //Destructors
        ~Inscripcion();     
};

#include "Ejercicio.h"
#include "Estudiante.h"
#include "Curso.h"

#endif
