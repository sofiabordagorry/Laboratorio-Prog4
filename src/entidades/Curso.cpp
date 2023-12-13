#include "../../include/Curso.h"	
#include "../../include/ControladorCurso.h"
    
//Constructores
Curso::Curso(){
    this->dificultad = Principiante;
    this->habilitado = false;
    this->idioma = NULL;
    this->profesor = NULL;
    this->nombre = "";
    this->descripcion = "";
    list<Inscripcion*> i;
    this->inscripciones = i;
    map <int, Leccion*> l;
    this->lecciones = l;
    list<Curso*> c;
    this->previas = c;
    this->cantLecciones=0;
} 

Curso::Curso(string n, string d, int td, bool h, Profesor* p, Idioma* id, list<Curso*> prev){
    if(td==0)
        this->dificultad = Principiante;
    if(td==1)
        this->dificultad = Medio;
    if(td==2)
        this->dificultad = Avanzado;
    this->habilitado = h;
    this->idioma = id;
    this->profesor = p;
    this->nombre = n;
    this->descripcion = d;
    list<Inscripcion*> i;
    this->inscripciones = i;
    map<int, Leccion*> lecciones;
    this->lecciones = lecciones;
    this->previas = prev;
    this->cantLecciones=0;
    
} 

//Getters
string Curso::getNombre(){
    return this->nombre;
}

string Curso::getDescripcion(){
    return this->descripcion;
}

tipoDificultad Curso::getDificultad(){
    return this->dificultad;
}

bool Curso::getHabilitado(){
    return this->habilitado;
}

list<Inscripcion*> Curso::getInscrpciones(){
    return this->inscripciones;
}

map<int, Leccion*> Curso::getLecciones(){
    return this->lecciones;
}

list<Curso*> Curso::getPrevias(){
    return this->previas;
}

//Setters
void Curso::setNombre(string n){
    this->nombre = n;
}
void Curso::setDescripcion(string d){
    this->descripcion = d;
}
void Curso::setDificultad(tipoDificultad tp){
    this->dificultad = tp;
}
void Curso::setHabilitado(bool h){
    this->habilitado = h;
}
void Curso::setInscripciones(Inscripcion* i){
    this->inscripciones.push_back(i);
}
void Curso::setLecciones(Leccion* l){
    this->cantLecciones=this->cantLecciones+1;
    this->lecciones.insert({this->cantLecciones,l});
}
void Curso::setPrevias(Curso* c){
    this->previas.push_back(c);
} 
//Otras operaciones
DTCurso Curso::getDataCurso(){
    vector<DTLeccion> dataLeccion;
    for(map<int, Leccion*>::iterator it = this->lecciones.begin(); it != this->lecciones.end(); ++it) {
        dataLeccion.push_back((*it).second->getDataLeccion());
    }
    DTProfesor* p;
    p = this->profesor->getDataProfesor();
    list<DTParEstudianteCurso> ec;
    for(list<Inscripcion*>::iterator it = this->inscripciones.begin(); it != this->inscripciones.end(); ++it) {
        DTParEstudianteCurso estCurso(this->getNombre(), (*it)->getEstudiante()->getNombre(), (*it)->getDataInscripcion());
        ec.push_back(estCurso);
    }
    DTIdioma i;
    i = this->idioma->getDTIdioma();
    DTCurso curso(this->nombre, this->descripcion, this->dificultad, this->habilitado, dataLeccion, p, ec, i);
    return curso;
}

int Curso::getCantLecciones(){
    return this->cantLecciones;
}

void Curso::getLeccion(Inscripcion* i, list<DTEjercicio>& ej){
   //ControladorCurso* cc = ControladorCurso::getInstancia();
    map<int, Leccion*>::iterator it = this->lecciones.begin(); //primera leccion
    while(it != this->lecciones.end() && ej.size() == 0){ //no se encontro la leccion actual
        it->second->getEjerciciosNoAprobados(ej, i);
        it++;
    }
}
void Curso::agregarLeccion(string tema, string objetivo){
     map<int, Leccion*>::iterator it;
  
    this->cantLecciones=this->cantLecciones + 1;
    Leccion * lec = new Leccion(this->cantLecciones, tema, objetivo);
    this->lecciones.insert({this->cantLecciones,lec});
  
}    

 void Curso::agregarEjercicioCompletar(int l, string f, string d,  string p){
 
    Leccion * lecc = this->lecciones.find(l)->second;
    lecc->agregarEjercicioCompletar(f,d,p);

} 

 void Curso::agregarEjercicioTraducir(int l, string f, string d, string t){

    Leccion * lecc = this->lecciones.find(l)->second;
    lecc->agregarEjercicioTraducir(f,d,t);
} 

int Curso::getCantEjercicios(){
    map<int,Leccion*>::iterator it;
    int cantej = 0;
    for(it = this->lecciones.begin(); it != this->lecciones.end(); it++){
        cantej += (*it).second->getCantEjLecc();
    }
    return cantej;
}

DTEstadisticaCurso Curso::getPromedio(){
    string nomCurso = this->nombre;
    float cantEjCurso = this->getCantEjercicios();
    float cantInsCurso = this->getCantInsACurso();
    float cantEjAprobadosInsACurso = this->getEjAprobadosCurso();
    float promCurso =  cantEjAprobadosInsACurso/(cantEjCurso * cantInsCurso);
    DTEstadisticaCurso res = DTEstadisticaCurso(promCurso, nomCurso);
    return res;
}
int Curso::getCantInsACurso(){
    return this->inscripciones.size();
}

int Curso::getEjAprobadosCurso(){
    int res = 0;
    for(auto it = this->inscripciones.begin(); it != this->inscripciones.end(); it++){
        res = res + (*it)->cantEjAprobados();
    }
    return res;
}

void Curso::verificarUltimaLeccion(int idLeccion){
    int ultimaLeccion = this->lecciones.size();
    ControladorCurso* cc = ControladorCurso::getInstancia();
    Inscripcion* inscripcionAprobada = cc->getInscripcion();
    if (ultimaLeccion == idLeccion)
        inscripcionAprobada->setAprobado(true);
}



void Curso::cursosHabilitadosParaEstudiante(string nickname, list<DTCurso>& cursosHabiltados) { 
    if(this->habilitado) {
        bool noEstaEst = true;

        //Verifico si el estudiante esat inscripto en el curso
        for(list<Inscripcion*>::iterator it = this->inscripciones.begin(); it != this->inscripciones.end() && noEstaEst; it++) 
            (*it)->verificarInscripcion(nickname, noEstaEst);//Si el estudiante esta noEstaEst cambia a false

        //Si no esta el estudiante verifico las previas
        if(noEstaEst) {
            bool previasAprobadas = true;
            bool aprobado;
            bool estaEst = false;
            list<Curso*>::iterator itCurso = this->previas.begin();

            //Itero los cursos mientras cada curso este aprobado y no haya llegado al final de las previas
            while(itCurso != this->previas.end() && previasAprobadas) {
                list<Inscripcion*>::iterator itInscripcion = (*itCurso)->inscripciones.begin();
                
                //Verifico que en cada inscripcion al curso este el estudiante inscripto y tenga aprobado el curso
                while(itInscripcion != (*itCurso)->inscripciones.end() && !estaEst) {
                    (*itInscripcion)->verificarAprobacion(nickname, estaEst);
                    if(estaEst) {
                        aprobado = (*itInscripcion)->getAprobado();
                        previasAprobadas = previasAprobadas && aprobado;
                    }
                    itInscripcion++;
                }

                if(!estaEst)
                    previasAprobadas = false;
                itCurso++;
            }

            //Si tiene las previas aprobadas agrego a los cursos habilitados 
            if(previasAprobadas)
                cursosHabiltados.push_back((this)->getDataCurso());
        }
    }
} 


Curso::~Curso(){
    //elimino las lecciones

    map<int, Leccion*>::iterator it;
    for(it = this->lecciones.begin(); it != this->lecciones.end(); it++){
        delete it->second;
    }
    
    this->lecciones.clear();

    //elimino las inscripciones
    list<Inscripcion*>::iterator ins;
    for(ins = this->inscripciones.begin(); ins != this->inscripciones.end(); ins++){
        delete (*ins);
    }
    this->inscripciones.clear();

    this->previas.clear();

    //desvinculo las previas

    this->idioma->borrarCurso(this);
    this->profesor->borrarCurso(this);
    //borrar el curso
} 

