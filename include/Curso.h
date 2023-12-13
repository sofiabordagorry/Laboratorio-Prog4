// Declaracion de la clase Curso

#ifndef _CURSO_H
#define _CURSO_H

#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include "DTEjercicio.h"
#include "TipoDificultad.h"
#include "DTEstadisticaCurso.h"
#include "DTParEstudianteCurso.h"


using namespace std;


class Profesor;
class Inscripcion;
class Idioma;
class DTCurso;
class Leccion;

class Curso {
	private:
		string nombre;
		string descripcion;
		tipoDificultad dificultad;
		bool habilitado;
		list<Inscripcion*> inscripciones;
		map<int,Leccion*> lecciones;
		list<Curso*> previas;
		Idioma * idioma;
		Profesor * profesor;
		int cantLecciones;
	public:
     	//Constructores
		Curso();
		Curso(string, string, int, bool, Profesor*, Idioma*, list<Curso*>);
		//Getters
		string getNombre();
		string getDescripcion();
		tipoDificultad getDificultad();
		bool getHabilitado();
		list<Inscripcion*> getInscrpciones();
		map<int,Leccion*> getLecciones();
		list<Curso*> getPrevias();
		//Setters
		void setNombre(string);
		void setDescripcion(string);
		void setDificultad(tipoDificultad);
		void setHabilitado(bool);
		void setInscripciones(Inscripcion*);
		void setLecciones(Leccion*);
		void setPrevias(Curso*);
		//Otras operaciones
		DTCurso getDataCurso();
		int getCantLecciones();
		void getLeccion(Inscripcion*, list<DTEjercicio>&);
		void agregarLeccion(string, string);
		void agregarEjercicioCompletar(int, string, string, string);
		void agregarEjercicioTraducir(int, string, string, string);
		int getCantEjercicios();
		DTEstadisticaCurso getPromedio();
		int getCantInsACurso();
		int getEjAprobadosCurso();
		void verificarUltimaLeccion(int);
		void cursosHabilitadosParaEstudiante(string nickname, list<DTCurso>&);
		//Destructor
		~Curso(); 
};

#include "Idioma.h"
#include "Profesor.h"
#include "Inscripcion.h"
#include "DTCurso.h"
#include "Leccion.h"

#endif
 