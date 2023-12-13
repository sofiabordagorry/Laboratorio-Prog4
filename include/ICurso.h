#ifndef _ICURSO_H
#define _ICURSO_H 

#include <iostream>
#include <map>
#include <set>
#include <list>
#include "DTIdioma.h"
#include "Idioma.h"
#include "DTCurso.h" 
#include "DTEjercicio.h"
#include "DTEstadisticaCurso.h"
#include "Inscripcion.h"
#include "Leccion.h"
#include "Curso.h"
#include "Ejercicio.h"

using namespace std;

class ICurso {
    public:
        // Constructor
        ICurso() {};
        // Destructor
        virtual ~ICurso() {};
        // operaciones
        virtual string getNombreCurso() = 0;
        virtual list<DTCurso> listarCursos() = 0;
        virtual list<DTIdioma> listarIdiomas() = 0;
        virtual bool registrarIdioma(DTIdioma idioma) = 0;
        virtual DTEjercicio seleccionarEjercicio(int idEj) = 0;
        virtual bool realizarEjercicioTraduccion(int idEj, string fraseTraduccion) = 0;
        virtual bool realizarEjercicioPalabras(int idEj, string frasePalabras) = 0;
        virtual void desuscribirseAIdioma(string idioma, IObserver* o) = 0;
        virtual list<DTCurso> listarCursosHabilitados() = 0;
        virtual list<DTCurso> listarCursosNoHabilitados() = 0;
        virtual DTEstadisticaCurso mostrarPromedioCurso(string nombreCurso) = 0;
        virtual list<DTIdioma> getIdiomasNoSuscrito(IObserver* u) = 0;
        virtual list<DTIdioma> getIdiomasSuscrito(IObserver * u) = 0;
        virtual void crearSuscripcionAIdioma(string idioma, IObserver* u) = 0;
        virtual void eliminarCurso(string) = 0;
        virtual list<DTCurso> listarCursosHabilitadosEstudiante(string nickname) = 0;
        virtual void inscribirseACurso(string nickname, string nomCurso) = 0;
        virtual DTCurso consultarCurso (string nombre) = 0;
        virtual bool habilitarCurso(string c) = 0;
        virtual void crearCurso(string profesor, string idioma, string nombre, string descripcion, int dificultad, set<string> previas) = 0;
        virtual int crearLeccion(string nombreCurso,string tema,string objetivo) = 0;
        virtual void crearEjercicioTraducir(string nombreCurso, int id, string frase, string descripcion, string traduccion) = 0;
        virtual void crearEjercicioCompletar(string nombreCurso,int id,string frase, string descripcion,string palabras) = 0;
        virtual void setCurso(Curso* c) = 0;
        //liberar memoria
        virtual void liberarCurso() = 0;
};

#endif
