#ifndef _CONTROLADORCURSO_H
#define _CONTROLADORCURSO_H

#include "ICurso.h"
//#include "DTEstadisticaCurso.h"
#include <iostream>
#include "DTCurso.h"
#include <map>
#include <set>
#include <list>

using namespace std;

class ControladorCurso: public ICurso{
	private:
		ControladorCurso();
		static ControladorCurso* instancia; //Singleton

		map<string, Curso*> cursos;
		map<string, Idioma*> idiomas;
		Leccion* leccionActual;
		Inscripcion* inscripcionAsociadaACurso;
		Curso* curso;
		list<DTEjercicio> ejerciciosNoAprobados;
		string nombreCurso;
		~ControladorCurso();
	public:
		static ControladorCurso* getInstancia();
    	static void releaseInstancia();

		map<string, Curso*> getCursos();
		map<string, Idioma*> getIdiomas();

		string getNombreCurso();
		list<DTCurso> listarCursos();
		list<DTIdioma> listarIdiomas();
		Inscripcion* getInscripcion();
		Leccion* getLeccion();
		Curso* getCurso();
		list<DTEjercicio> getEjNoAprobados();
		void guardarInscripcion(Inscripcion*);
		void guardarLeccion(Leccion*);
		void guardarCurso(Curso*);
		void guardarEjNoAprobados(list<DTEjercicio>);
		DTEjercicio seleccionarEjercicio(int);
		bool realizarEjercicioTraduccion(int, string); 
		bool realizarEjercicioPalabras(int, string);
		void desuscribirseAIdioma(string idioma, IObserver* u);
		list<DTCurso> listarCursosHabilitados();
		list<DTCurso> listarCursosNoHabilitados();
		DTEstadisticaCurso mostrarPromedioCurso(string);
		list<DTIdioma> getIdiomasNoSuscrito(IObserver* u);
		list<DTIdioma> getIdiomasSuscrito(IObserver * u);
		void crearSuscripcionAIdioma(string idioma, IObserver* u);
		void eliminarCurso(string);
		list<DTCurso> listarCursosHabilitadosEstudiante(string nickname);
		void inscribirseACurso(string nickname, string nomCurso);
		DTCurso consultarCurso(string nombre);
		void crearCurso(string profesor, string idioma, string nombre, string descripcion, int dificultad, set<string> previas);
		int crearLeccion(string nombreCurso,string tema,string objetivo);
        void crearEjercicioTraducir(string nombre,int id,string frase,string descripcion,string traduccion);
		void crearEjercicioCompletar(string nombre,int id,string frase,string descripcion,string palabras);
		bool habilitarCurso(string);
		bool registrarIdioma(DTIdioma idioma);
		void setCurso(Curso*);
		void liberarCurso();
};

#endif
