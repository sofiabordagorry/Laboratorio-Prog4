// Declaración de la Interfaz Usuario

#ifndef _IUSUARIO_H
#define _IUSUARIO_H

#include <iostream>
#include <map>
#include <set>
#include <list>
#include "DTCurso.h"
#include "DTEstudiante.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Usuario.h"
//#include "DTEstadisticaCurso.h"

using namespace std;

class IUsuario {
    public: 
      IUsuario() {}; //Constructor
      virtual ~IUsuario(){}; //Destructor
    
      virtual DTUsuario* consultarUsuario(string nickname) = 0;
      virtual list<DTEstadisticaCurso> mostrarPromediosCursosEstudiante(string nickname) = 0;
      virtual list<DTIdioma> listarIdiomasProfesor(string nickname) = 0;
      virtual list<DTProfesor*> listarProfesores() = 0;
      virtual list<DTEstudiante*> listarEstudiantes() = 0;
      virtual list<DTEstadisticaCurso> mostrarPromediosCursosProfesor(string nickname) = 0;
      virtual list<DTCurso> listarCursosNoAprobados(string nicknameEst) = 0;
      virtual list<DTEjercicio> listarEjerciciosNoAprobados(string nomCurso) = 0;
      virtual bool registrarEstudiante(DTEstudiante estudiante) = 0;
      virtual bool registrarProfesor(DTProfesor profesor) = 0;
      virtual list<DTNotificacion> listarNotificaciones(string nickname) = 0;
      virtual void eliminarNotificaciones(string nickname) = 0;
      virtual list<DTIdioma> listarIdiomasNoSuscrito(string nickname) = 0;
      virtual list<DTIdioma> listarIdiomasSuscrito(string nickname) = 0;
      virtual void suscribirseAIdioma(string idioma) = 0;
      virtual bool verificarExistenciaDeUsuario(string nickname) = 0;
      virtual void desuscribirseDeIdioma(string idioma) = 0;
      // liberar memoria
      virtual void liberarUsuario() = 0;

};

#endif
