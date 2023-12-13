#include "../../include/ControladorUsuario.h"
#include "../../include/Factory.h"
#include "../../include/ControladorCurso.h"
#include <map>
#include <set>

#include <iostream>
using namespace std;

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario::ControladorUsuario(){
        map<string, Estudiante *> estudiantes;
        map<string, Profesor *> profesores;
        this->estudiantes = estudiantes;
        this->profesores = profesores;
}

ControladorUsuario* ControladorUsuario::getInstancia(){
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    
    return instancia;
}

void ControladorUsuario::releaseInstancia()
{
    if (instancia != NULL)
    {
        delete instancia;
        instancia = NULL;
    };
}

map<string, Estudiante*> ControladorUsuario::getEstudiantes(){
    return this->estudiantes;
}
 
map<string, Profesor*> ControladorUsuario::getProfesores(){
    return this->profesores;
}
  
list<DTIdioma> ControladorUsuario::listarIdiomasProfesor(string nickname){
  map <string, Profesor*> coleccionProfesor= this->getProfesores();
  Profesor* profe=coleccionProfesor.find(nickname)->second;
  list <Idioma*> idiomasProfe= profe->getIdiomasEspecializa();
  list <DTIdioma> dtidiomasProfe;
  
  for (list<Idioma*>:: iterator it= idiomasProfe.begin(); it!= idiomasProfe.end(); ++it){
    dtidiomasProfe.push_back((*it)->getDTIdioma());
  }
  return dtidiomasProfe;
};
 

list<DTProfesor*> ControladorUsuario::listarProfesores(){
    list<DTProfesor*> profesoresDelSistema;
    map<string, Profesor *> coleccionProfesor = this->getProfesores();
    map<string, Profesor *>::iterator it;

    for (it = coleccionProfesor.begin(); it != coleccionProfesor.end(); ++it)
    {
        profesoresDelSistema.push_back(it->second->getDataProfesor());
    }

    return profesoresDelSistema;
}

 
list<DTEstudiante*>  ControladorUsuario::listarEstudiantes(){
    list<DTEstudiante*> res;
    map<string, Estudiante*> est =this->estudiantes;
    map<string, Estudiante*>::iterator it;
    for(it = est.begin(); it != est.end(); it++){
        res.push_back(it->second->getDataEstudiante());
    }
    return res;
}
 

 
list<DTNotificacion> ControladorUsuario::listarNotificaciones(string nickname){
    Usuario * u;
    if(this->estudiantes.count(nickname) != 0){
        u = this->estudiantes.find(nickname)->second;
    }else{
        u = this->profesores.find(nickname)->second;
    }
    return u->getNotificaciones();
}
 

list<DTIdioma> ControladorUsuario::listarIdiomasNoSuscrito(string nickname){
    ControladorCurso* cc = ControladorCurso::getInstancia();
    // factory* fac = factory::getInstancia();
    Usuario * u;
    if(this->estudiantes.count(nickname) != 0){
        u = this->estudiantes.find(nickname)->second;
    }else{
        u = this->profesores.find(nickname)->second;
    }
    // ICurso* icurso = fac->getICurso();
    guardarUsuario(u);
    return cc->getIdiomasNoSuscrito(u);
}

list<DTIdioma> ControladorUsuario::listarIdiomasSuscrito(string nickname){
    ControladorCurso* cc = ControladorCurso::getInstancia();
    // factory* fac = factory::getInstancia();
    Usuario * u;
    if(this->estudiantes.count(nickname) != 0){
        u = this->estudiantes.find(nickname)->second;
    }else{
        u = this->profesores.find(nickname)->second;
    }
    // ICurso* icurso = fac->getICurso();
    guardarUsuario(u);
    return cc->getIdiomasSuscrito(u);
}


 
bool ControladorUsuario::registrarEstudiante(DTEstudiante est){
    bool u;
    if (this->estudiantes.find(est.getNickname()) != this->estudiantes.end()) {
        u = true;
    } else {
        u = false;
    }
    if (u == true) {
        if (this->profesores.find(est.getNickname()) != this->profesores.end() && u == false) {
            u = true;
        } else {
            u = false;
        }
    }

    if (u == false) {
        Estudiante* e = new Estudiante(est.getPaisDeResidencia(), est.getFechaDeNacimiento(), est.getNickname(), est.getContrasenia(), est.getNombre(), est.getDescripcion());
        this->estudiantes.insert({est.getNickname(), e});
        return true;
    } else {
        return false;
    }
}
 
 
bool ControladorUsuario::registrarProfesor(DTProfesor prof){
    bool u;
    if (this->estudiantes.find(prof.getNickname()) != this->estudiantes.end()) {
        u = true;
    } else {
        u = false;
    }
    if (u == true) {
        if (this->profesores.find(prof.getNickname()) != this->profesores.end() && u == false) {
            u = true;
        } else {
            u = false;
        }
    }

    if (u == false) {
        ControladorCurso* cc = ControladorCurso::getInstancia();
        map<string, Idioma*> idiomas = cc->getIdiomas();
        list<Idioma*> idiomasProfe;
        list<string> idiomasProf = prof.getIdiomas();
        list<string>::iterator it;
        for(it = idiomasProf.begin(); it != idiomasProf.end(); it ++){
            idiomasProfe.push_back(idiomas.find((*it))->second);
        }
        
        Profesor * p = new Profesor(prof.getNickname(), prof.getContrasenia(), prof.getNombre(), prof.getDescripcion(), prof.getInstituto(), idiomasProfe);
        this->profesores.insert({prof.getNickname(), p});
        return true;
    } else {
        return false;
    }
}

void ControladorUsuario::eliminarNotificaciones(string nickname){
    Usuario * u;
    if(this->estudiantes.count(nickname) != 0){
        u = this->estudiantes.find(nickname)->second;
    }else{
        u = this->profesores.find(nickname)->second;
    }
    u->vaciarNotificaciones();
}


void ControladorUsuario::suscribirseAIdioma(string idioma){
    Usuario * u = getUsuario();
    ControladorCurso * cc = ControladorCurso::getInstancia();
    cc->crearSuscripcionAIdioma(idioma, u);
} 


list<DTEstadisticaCurso> ControladorUsuario::mostrarPromediosCursosEstudiante(string nickname){
    Estudiante* e = this->estudiantes.find(nickname)->second;
    return e->getEstadisticaCurso();
}

  
list<DTEstadisticaCurso> ControladorUsuario::mostrarPromediosCursosProfesor(string nickname){
    Profesor * p = this->profesores.find(nickname)->second;
    return p->getPromediosCursos();
}
 
 
void ControladorUsuario::guardarUsuario(Usuario* usuario){
    this->u = usuario;
}

 
void ControladorUsuario::guardarEstudiante(Estudiante* estudiante){
    this->est = estudiante; 
}


Usuario* ControladorUsuario::getUsuario(){
    return this->u;
}


Estudiante* ControladorUsuario::getEstudianteCurso(){
    return this->est;
}
list<DTCurso> ControladorUsuario::listarCursosNoAprobados(string nicknameEst) {
    map<string, Estudiante*> estudiantes = this->getEstudiantes();
    Estudiante* estudiante = estudiantes.find(nicknameEst)->second;
    this->guardarEstudiante(estudiante);
    list<DTCurso> cursosNoAprobados = estudiante->getCursosNoAprobados();
    return cursosNoAprobados;
}

list<DTEjercicio> ControladorUsuario::listarEjerciciosNoAprobados(string nomCurso) { 
    Estudiante* estudiante = this->getEstudianteCurso();
    list<DTEjercicio> ejerciciosNoAprobados = estudiante->buscarInscripcion(nomCurso);
    ControladorCurso* cc = ControladorCurso::getInstancia();
    cc->guardarEjNoAprobados(ejerciciosNoAprobados);
    return ejerciciosNoAprobados;
}
 

DTUsuario* ControladorUsuario::consultarUsuario(string nickname) {
    map<string, Estudiante*> estudiantes = this->getEstudiantes();
    map<string, Profesor*> profesores = this->getProfesores();
    DTUsuario* usuario;
    if(estudiantes.find(nickname) != estudiantes.end()) {
        Estudiante * e = estudiantes.find(nickname)->second;
        usuario = e->getDataUsuario();
    } else {
        Profesor* profIngresado = profesores.find(nickname)->second;
        list<string> id;
        list<Idioma*>::iterator it;
        list<Idioma*> idiomasQueEsUnCrack = profIngresado->getIdiomasEspecializa();
        for(it = idiomasQueEsUnCrack.begin(); it != idiomasQueEsUnCrack.end(); it++)
            id.push_back((*it)->getIdioma());
            
        usuario = new DTProfesor(profIngresado->getNickname(), profIngresado->getContrasenia(), profIngresado->getNombre(), profIngresado->getDescripcion(), profIngresado->getNotificaciones(),profIngresado->getInstituto(), id);
    }
    return usuario;
    
}

bool ControladorUsuario::verificarExistenciaDeUsuario(string nickname){
    return ((this->estudiantes.count(nickname) != 0) || (this->profesores.count(nickname) != 0));
}

void ControladorUsuario::desuscribirseDeIdioma(string idioma){
    ControladorCurso * cc = ControladorCurso::getInstancia();
    Usuario * usu = getUsuario();
    cc->desuscribirseAIdioma(idioma, usu);
}

void ControladorUsuario::liberarUsuario(){
    map<string, Estudiante *>::iterator itE;
    map<string, Profesor *>::iterator itP;
    
    for(itE = this->estudiantes.begin(); itE != this->estudiantes.end(); itE++)
        delete itE->second;        

    this->estudiantes.clear();
    
    for(itP= this->profesores.begin(); itP != this->profesores.end(); itP++)
        delete itP->second;

    this->profesores.clear();
}


