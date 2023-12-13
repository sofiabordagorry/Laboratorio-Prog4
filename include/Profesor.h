#ifndef _PROFESOR_H
#define _PROFESOR_H

#include "Usuario.h"
#include "Idioma.h"
#include "Curso.h"

#include "DTUsuario.h"
#include <iostream>
#include <list>

using namespace std;

class DTProfesor;

class Profesor : public Usuario{
    private:
        string instituto;
        list<Idioma *> idiomasEspecializa;
        list<Curso *> cursosCreados;
    public:
        //Constructores
        Profesor();
        Profesor(string nickname,string contrasenia,string nombre,string descripcion,string instituto, list<Idioma*> idiomas);
        //Setters
        void setInstituto(string instituto);
        void setIdiomaEspecializa(Idioma *);
        void setCursoCreado(Curso *);
        //Getters
        string getInstituto();
        list <Idioma *> getIdiomasEspecializa();
        //list <Curso *> getCursosCreados();
        //OtrasOperaciones
        DTUsuario* getDataUsuario();
        list<string> getIdiomas();
        void borrarCurso(Curso*);
        list<Curso *> getCursosPropuestosHabilitados();
        list<DTEstadisticaCurso> getPromediosCursos();
        DTProfesor* getDataProfesor();
        void notificar();
        //Destructor
        ~Profesor();
};

#include "DTProfesor.h"

#endif
