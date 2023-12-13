#include "../../include/Profesor.h"
#include "../../include/Usuario.h"

Profesor::Profesor(string nickname, string contrasenia, string nombre, string descripcion, string instituto, list<Idioma*> idiomas):Usuario(nickname, contrasenia, nombre, descripcion) {
    this->instituto = instituto;
    this->idiomasEspecializa = idiomas;
} 


string Profesor::getInstituto(){
    return this->instituto;
}

list<Idioma*> Profesor::getIdiomasEspecializa(){
    return this->idiomasEspecializa;   
}

void Profesor::setInstituto(string instituto){
    this->instituto = instituto;
}
void Profesor::setIdiomaEspecializa(Idioma * i){
    this->idiomasEspecializa.push_back(i);
}

void Profesor::setCursoCreado(Curso * curso){
    this->cursosCreados.push_back(curso);
}
list<string> Profesor::getIdiomas()
{
    list<string> idiomas;
    for (list<Idioma *>::iterator it = this->idiomasEspecializa.begin(); it != this->idiomasEspecializa.end(); ++it)
        idiomas.push_back((*it)->getIdioma());

    return idiomas;
} 

DTProfesor* Profesor::getDataProfesor()
{

    list<string> idiomas;
    for (list<Idioma*>::iterator it = this->idiomasEspecializa.begin(); it != this->idiomasEspecializa.end(); it++){
        idiomas.push_back((*it)->getDTIdioma().getNombre());
    }    
    DTProfesor *prof = new DTProfesor(this->getNickname(), this->getContrasenia(), this->getNombre(), this->getDescripcion(), this->getNotificaciones(), this->instituto, idiomas);
    return prof;


}

DTUsuario* Profesor::getDataUsuario(){
    return this->getDataProfesor();
}

void Profesor::borrarCurso(Curso* c){
    this->cursosCreados.remove(c);
} 


list<Curso*> Profesor::getCursosPropuestosHabilitados(){
    list<Curso*> res;

    for(auto it = this->cursosCreados.begin(); it != this->cursosCreados.end(); it++){
        if((*it)->getHabilitado()){
            res.push_back((*it));
        }
    }
    return res;
}

list<DTEstadisticaCurso> Profesor::getPromediosCursos(){
    list<DTEstadisticaCurso> res;
    list<Curso*> cursosPropHab = this->getCursosPropuestosHabilitados();
    for(auto it = cursosPropHab.begin(); it != cursosPropHab.end(); it++){
        res.push_back((*it)->getPromedio());
    }
    return res;
} 
Profesor::~Profesor(){
   this->idiomasEspecializa.clear();
    this->cursosCreados.clear();
}