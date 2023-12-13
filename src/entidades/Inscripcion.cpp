#include "../../include/Inscripcion.h"
#include "../../include/ControladorCurso.h"

//Constructor por defecto
Inscripcion::Inscripcion() {
    DTFecha fecha;
    this->fecha = fecha;
    this->aprobado = false;
    this->curso = NULL;
    this->estudiante = NULL;
    list<Ejercicio*> ejerciciosAprobados;
    this->ejerciciosAprobados = ejerciciosAprobados;
}

//Constructor por parametros
Inscripcion::Inscripcion(DTFecha fecha, bool aprobado, Curso* curso, Estudiante* estudiante) {
    this->fecha = fecha;
    this->aprobado = aprobado;
    this->curso = curso;
    this->estudiante = estudiante;
    list<Ejercicio*> ejerciciosAprobados;
    this->ejerciciosAprobados = ejerciciosAprobados;
} 

//Getters
DTFecha Inscripcion::getFecha() {
    return this->fecha;
}

bool Inscripcion::getAprobado() {
    return this->aprobado;
}

Curso* Inscripcion::getCurso() {
    return this->curso;
}

Estudiante* Inscripcion::getEstudiante() {
    return this->estudiante;
} 


list<Ejercicio*> Inscripcion::getEjerciciosAprobados() {
    return this->ejerciciosAprobados;
}

//Setters
void Inscripcion::setFecha(DTFecha fecha) {
    this->fecha = fecha;
}

void Inscripcion::setAprobado(bool aprobado) {
    this->aprobado = aprobado;
}

void Inscripcion::setCurso(Curso* curso) {
    this->curso = curso;
}

void Inscripcion::setEstudiante(Estudiante* estudiante) {
    this->estudiante = estudiante;
}

void Inscripcion::setEjercicioAprobado(Ejercicio* ejercicioAprobado) {
    this->ejerciciosAprobados.push_back(ejercicioAprobado);
} 

//Otras opreaciones
void Inscripcion::verificarAprobacion(string nickname, bool& estaEst) {
    string nicknameInscripto = this->estudiante->getNickname();
    if(nickname == nicknameInscripto)      
        estaEst = true;
}

void Inscripcion::verificarInscripcion(string nickname, bool& noEstaEst) {
    string nicknameInscripto = this->estudiante->getNickname();
    if(nickname == nicknameInscripto)      
        noEstaEst = false;
}

DTCurso Inscripcion::getDataCurso() {
    return this->curso->getDataCurso();
}

int Inscripcion::cantEjAprobados() {
    return this->ejerciciosAprobados.size();
}

DTEstadisticaCurso Inscripcion:: getPromedioCurso() {
    string nomCurso = this->curso->getNombre();
    float cantEjCurso = this->curso->getCantEjercicios();
    DTEstadisticaCurso promedioCurso(this->cantEjAprobados()/cantEjCurso, nomCurso);
    return promedioCurso;
}

bool Inscripcion::buscarCurso(string nomCurso, list<DTEjercicio>& ejNoAprobados, Inscripcion* j) {
    string nomC = this->curso->getNombre();
    if(nomC == nomCurso) {
        ControladorCurso* cc = ControladorCurso::getInstancia();
        cc->guardarCurso(this->curso);
        this->curso->getLeccion(j, ejNoAprobados);
        return true;
    } else 
        return false;
}

void Inscripcion::elimEjercicio(Ejercicio* ejercicio) {
    this->ejerciciosAprobados.remove(ejercicio);
} 

DTInscripcion Inscripcion::getDataInscripcion(){
    DTInscripcion DTi(this->aprobado, this->fecha);
    return DTi;
}

Inscripcion::~Inscripcion() {
    this->estudiante->elimInscripcion(this);
} 



