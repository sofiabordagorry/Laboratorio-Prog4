#ifndef _CONTROLADORUSUARIO_H
#define _CONTROLADORUSUAIRO_H

#include "IUsuario.h"
#include "Estudiante.h"
#include "Profesor.h"
#include <iostream>
#include <set>
#include <list>
#include <map>
using namespace std;

class ControladorUsuario: public IUsuario{
    private:
    ControladorUsuario();
    static ControladorUsuario* instancia;

    map<string, Estudiante *> estudiantes;
    map<string, Profesor *> profesores;
    Usuario * u;
    Estudiante* est;
    ~ControladorUsuario(){};
    public:
        static ControladorUsuario* getInstancia();
        static void releaseInstancia();

        map<string, Estudiante*> getEstudiantes();
        map<string, Profesor*> getProfesores();

        DTUsuario* consultarUsuario(string nickname);
        list<DTProfesor*> listarProfesores();
        list<DTEstudiante*> listarEstudiantes();
        list<DTCurso> listarCursosNoAprobados(string nickname);
        list<DTEjercicio> listarEjerciciosNoAprobados(string nomCurso);
        list<DTNotificacion> listarNotificaciones(string nickname);
        list<DTIdioma> listarIdiomasNoSuscrito(string nickname);
        list<DTIdioma> listarIdiomasSuscrito(string nickname);
        bool registrarEstudiante(DTEstudiante est);
        bool registrarProfesor(DTProfesor prof);
        void eliminarNotificaciones(string nickname);
        void suscribirseAIdioma(string idioma);
        list<DTEstadisticaCurso> mostrarPromediosCursosEstudiante(string nickname);
        list<DTEstadisticaCurso> mostrarPromediosCursosProfesor(string nickname);
        Estudiante * getEstudianteCurso();
        void guardarUsuario(Usuario*);
        void guardarEstudiante(Estudiante*);
        Usuario* getUsuario();
        list<DTIdioma> listarIdiomasProfesor(string nickname);
        bool verificarExistenciaDeUsuario(string nickname);
        void desuscribirseDeIdioma(string idioma);

        void liberarUsuario();
};

#endif
 