#include "../../include/ControladorCurso.h"
#include "../../include/DTIdioma.h"
#include "../../include/ControladorUsuario.h"
#include <chrono>
#include <list>

ControladorCurso* ControladorCurso::instancia = NULL;
 
ControladorCurso::ControladorCurso() {
    
    this->leccionActual = NULL;
    this->inscripcionAsociadaACurso = NULL;
    this->curso = NULL;
    this->nombreCurso = "";
    list<DTEjercicio> ejerciciosNoAprobados;
    this->ejerciciosNoAprobados = ejerciciosNoAprobados;
    map<string, Curso*> cursos;
    this->cursos = cursos;
    map<string, Idioma*> idiomas;
    this->idiomas = idiomas;
}

void ControladorCurso::releaseInstancia()
{
    if (instancia != NULL)
    {
        delete instancia;
        instancia = NULL;
    };
}
 
ControladorCurso* ControladorCurso::getInstancia() {
    if (instancia == NULL)
        instancia = new ControladorCurso();
    
    return instancia;
}
 
 
map<string, Curso*> ControladorCurso::getCursos(){
    return this->cursos;
}
 
  
map<string, Idioma*> ControladorCurso::getIdiomas(){
    return this->idiomas;
} 

 
string ControladorCurso::getNombreCurso() {
    return this->curso->getNombre();
}


list<DTCurso> ControladorCurso::listarCursos() {
    list<DTCurso> cursosDelSistema;
    map<string, Curso*> coleccionCursos = this->getCursos();
    map<string, Curso*>::iterator it;

    for(it = coleccionCursos.begin(); it != coleccionCursos.end(); ++it) {
        cursosDelSistema.push_back(it->second->getDataCurso());
    } 

    return cursosDelSistema;
}
 

list<DTIdioma> ControladorCurso::listarIdiomas() {
    list<DTIdioma> res;
    map<string, Idioma*> idiomas = this->getIdiomas();
    
    for(map<string, Idioma*>::iterator it = this->idiomas.begin(); it != this->idiomas.end();it++){
        res.push_back(it->second->getDTIdioma());
    }
    return res;
}


Inscripcion* ControladorCurso::getInscripcion(){
    return this->inscripcionAsociadaACurso;
}

Leccion* ControladorCurso::getLeccion() {
    return this->leccionActual;
}

Curso* ControladorCurso::getCurso() {
    return this->curso;
}

bool ControladorCurso::registrarIdioma(DTIdioma idioma) {
    if (this->idiomas.find(idioma.getNombre()) != this->idiomas.end()) {
        return false;
    } else {
        Idioma * nIdioma = new Idioma(idioma.getNombre());
        this->idiomas.insert({idioma.getNombre(), nIdioma});
        return true;
    }
} 

list<DTEjercicio> ControladorCurso::getEjNoAprobados() {
    return this->ejerciciosNoAprobados;
}

void ControladorCurso::guardarInscripcion(Inscripcion* ins) {
    this->inscripcionAsociadaACurso = ins;
}

void ControladorCurso::guardarLeccion(Leccion* l) {
    this->leccionActual = l;
}


void ControladorCurso::guardarCurso(Curso* c) {
    this->curso = c;
}

void ControladorCurso::guardarEjNoAprobados(list<DTEjercicio> ejNoAprobados) {
    this->ejerciciosNoAprobados = ejNoAprobados;
}

DTEjercicio ControladorCurso::seleccionarEjercicio(int idEj) {
    Leccion* l = this->leccionActual;
    return l->buscarEjercicio(idEj);
} 

bool ControladorCurso::realizarEjercicioPalabras(int idEj, string palabra) {
    Inscripcion* i = this->getInscripcion();
    Leccion* l = this->getLeccion();
    Curso* c = this->getCurso();
    list<DTEjercicio> noAprobados = this->getEjNoAprobados();
    bool respuesta = l->buscarEjercicio(idEj, palabra, i);
    int idLeccion = l->getID();

    if(respuesta) {
        int cant = noAprobados.size();
        if(cant == 1)
            c->verificarUltimaLeccion(idLeccion);
        Ejercicio* e = l->getEjercicio(idEj);
        i->setEjercicioAprobado(e);
    }

    return respuesta;
} 

bool ControladorCurso::realizarEjercicioTraduccion(int idEj, string fraseTraduccion) {
    Inscripcion* i = this->getInscripcion();
    Leccion* l = this->getLeccion();
    Curso* c = this->getCurso();
    list<DTEjercicio> noAprobados = this->ejerciciosNoAprobados;
    bool respuesta = l->buscarEjercicio(idEj, fraseTraduccion, i);
    int idLeccion = l->getID();

    if(respuesta) {
        int cant = noAprobados.size();
        if(cant == 1)
            c->verificarUltimaLeccion(idLeccion);
        Ejercicio* e = l->getEjercicio(idEj);
        i->setEjercicioAprobado(e);
    }

    return respuesta;
}


void ControladorCurso::desuscribirseAIdioma(string idioma, IObserver* o) {
    Idioma* i = this->idiomas.find(idioma)->second;
    i->eliminarSuscripciones(o);
}

 list<DTCurso> ControladorCurso::listarCursosHabilitados(){
    list<DTCurso> res;
    map<string, Curso*>::iterator it;
    for(it = this->cursos.begin(); it != this->cursos.end();it++){
        if((*it).second->getHabilitado()){
            res.push_back((*it).second->getDataCurso());
        }
    }
    return res;
} 

list<DTCurso> ControladorCurso::listarCursosNoHabilitados(){
    list<DTCurso> res;
    map<string, Curso*>::iterator it;
    for(it = this->cursos.begin(); it != this->cursos.end();it++){
        if(!(*it).second->getHabilitado()){
            res.push_back((*it).second->getDataCurso());
        }
    }
    return res;
} 

 bool ControladorCurso::habilitarCurso(string curso){
    Curso * cHab = this->cursos.find(curso)->second;
    map<int, Leccion*> lecciones = cHab->getLecciones();
    map<int, Leccion*>::iterator itL;
    bool habilitable = true && (lecciones.size() > 0);
    for(itL = lecciones.begin(); itL != lecciones.end(); itL++){
        list<Ejercicio*> ejercicios = itL->second->getEjercicios();
            habilitable = habilitable && (ejercicios.size() > 0);
    }
    if(habilitable){
        cHab->setHabilitado(true);
        return true;//se pudo habilitar
    }else{
        return false;//habia alguna leccion que no tiene ejercicios
    }
} 

DTEstadisticaCurso ControladorCurso::mostrarPromedioCurso(string nombreCurso){
    Curso * c = this->cursos.find(nombreCurso)->second;
    return c->getPromedio();
}
 
list<DTIdioma> ControladorCurso::getIdiomasNoSuscrito(IObserver* u){
    list<DTIdioma> idiomasNoSuscrito;
    map<string, Idioma*>::iterator it;
    for(it = this->idiomas.begin(); it !=  this->idiomas.end(); it++){ 
        if(!it->second->verificarSuscripcion(u)){
            idiomasNoSuscrito.push_back((it->second->getDTIdioma()));
        }
    }
    return idiomasNoSuscrito;
}

list<DTIdioma> ControladorCurso::getIdiomasSuscrito(IObserver * u){
    list<DTIdioma> idiomasSuscrito;
    map<string, Idioma*>::iterator it;
    for(it = this->idiomas.begin(); it !=  this->idiomas.end(); it++){ 
        if(it->second->verificarSuscripcion(u)){
            idiomasSuscrito.push_back((it->second->getDTIdioma()));
        }
    }
    return idiomasSuscrito;
}

void ControladorCurso::crearSuscripcionAIdioma(string idioma, IObserver* u){
        Idioma * i = this->idiomas.find(idioma)->second;//Asumo que el idioma "idioma" existe
        i->suscribirse(u);  
}

void ControladorCurso::eliminarCurso(string nombre){
    map<string, Curso*> cursos = this->getCursos();
    Curso* c = cursos.find(nombre)->second;
    this->cursos.erase(nombre);
    delete c;
}

list<DTCurso> ControladorCurso::listarCursosHabilitadosEstudiante(string nickname) {
    list<DTCurso> cursosHabilitados;
    for(map<string, Curso*>::iterator it = this->cursos.begin(); it != this->cursos.end(); it++)
        it->second->cursosHabilitadosParaEstudiante(nickname, cursosHabilitados);
    return cursosHabilitados;
}

void ControladorCurso::inscribirseACurso(string nickname, string nomCurso) {
    auto ahora = chrono::system_clock::now();
    time_t tiempo_ahora = chrono::system_clock::to_time_t(ahora);
    tm* fecha = localtime(&tiempo_ahora);
    int dia = fecha->tm_mday;
    int mes = fecha->tm_mon + 1;
    int anio = fecha->tm_year + 1900;

    DTFecha fechaInscripcion(dia, mes, anio);
    Curso* cursoInscripcion = this->cursos.find(nomCurso)->second;
    ControladorUsuario* cu = ControladorUsuario::getInstancia();
    map<string, Estudiante*> estudiantes = cu->getEstudiantes();
    Estudiante* estudianteInscripto = estudiantes.find(nickname)->second;
    Inscripcion* inscripcionCurso = new Inscripcion(fechaInscripcion, false, cursoInscripcion, estudianteInscripto);
    estudianteInscripto->setInscripcion(inscripcionCurso);
    cursoInscripcion->setInscripciones(inscripcionCurso);
} 

DTCurso ControladorCurso::consultarCurso(string nombre){
    map<string, Curso*> cursos = this->getCursos();
    return cursos.find(nombre)->second->getDataCurso();
} 

void ControladorCurso::crearCurso(string profesor, string idioma, string nombre, string descripcion, int dificultad, set<string> previas)
{
    ControladorUsuario *cu = ControladorUsuario::getInstancia();
    map<string,Profesor *> profesores = cu->getProfesores();
    Profesor *prof = nullptr;
    prof = profesores.find(profesor)->second;
    map<string, Idioma *> idiomas = this->getIdiomas();
    Idioma *idiom = nullptr;

    idiom = idiomas.find(idioma)->second;

    map<string, Curso *> cursos = this->getCursos();
    list<Curso *> prevs;
    for (map<string, Curso *>::iterator it = cursos.begin(); it != cursos.end(); it++)
    {
        if (previas.count(it->first) != 0)
        {
            cursos.find(it->first);
            prevs.push_back(it->second);
        }
    };
    Curso *curso = new Curso(nombre, descripcion, dificultad, false, prof, idiom, prevs);
    prof->setCursoCreado(curso);
    idiom->agregarCurso(curso);
    this->cursos.insert({nombre, curso});
}; 

int ControladorCurso::crearLeccion(string nombreCurso,string tema,string objetivo){
    Curso* curso= this->cursos.find(nombreCurso)->second;
    curso->agregarLeccion(tema, objetivo);
    return curso->getCantLecciones();
};

void ControladorCurso::crearEjercicioTraducir(string nombreCurso, int id, string frase, string descripcion, string traduccion){
    Curso* curso=this->cursos.find(nombreCurso)->second;
    curso->agregarEjercicioTraducir(id, frase, descripcion, traduccion);
};

void ControladorCurso::crearEjercicioCompletar(string nombreCurso, int id, string frase, string descripcion,string palabras){
    Curso* curso=this->cursos.find(nombreCurso)->second;
    curso->agregarEjercicioCompletar(id, frase, descripcion, palabras);
};

void ControladorCurso::setCurso(Curso* c){
    this->cursos.insert({c->getNombre(), c});
}

void ControladorCurso::liberarCurso() {
    map<string, Curso*>::iterator itc;
    for(itc = this->cursos.begin(); itc != this->cursos.end(); itc++){
        delete itc->second;
    }
    this->cursos.clear();
    map<string, Idioma*>::iterator iti;
    for(iti = this->idiomas.begin(); iti != this->idiomas.end(); iti++){
        delete iti->second;
    }
    this->idiomas.clear();
}

ControladorCurso::~ControladorCurso(){
    
}