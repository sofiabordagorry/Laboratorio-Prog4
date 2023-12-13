#include "../../include/Estudiante.h"
#include "../../include/Usuario.h"
#include "../../include/ControladorCurso.h"

//Constructor por defecto
Estudiante::Estudiante():Usuario() {
    this->paisDeRecidencia = "";
    DTFecha f;
    this->fechaDeNacimiento = f;
} 

//Constructor por parametros
 Estudiante::Estudiante(string paisDeResidencia, DTFecha fechaDeNacimiento, string nickname, string contrasenia, string nombre, string descripcion):Usuario(nickname, contrasenia, nombre, descripcion) {
    this->paisDeRecidencia = paisDeResidencia;
    this->fechaDeNacimiento = fechaDeNacimiento;
} 

//Getters
string Estudiante::getPaisDeResidencia() {
    return this->paisDeRecidencia;
}

DTFecha Estudiante::getFechaDeNacimiento() {
    return this->fechaDeNacimiento;
}

list<Inscripcion*> Estudiante::getInscripciones() {
    return this->inscripciones;
}

//Setters
 void Estudiante::setPaisDeResidencia(string paisDeResidencia) {
    this->paisDeRecidencia = paisDeRecidencia;
}

void Estudiante::setFechaDeNacimiento(DTFecha fechaDeNacimiento) {
    this->fechaDeNacimiento = fechaDeNacimiento;
}

void Estudiante::setInscripcion(Inscripcion* inscripcion) {
    this->inscripciones.push_back(inscripcion);
} 

//Devuelvo set de DTCurso de los cursos no aprobados
list<DTCurso> Estudiante::getCursosNoAprobados() {
    list<DTCurso> cursosNoAprobados;
    for(auto& inscripcion: this->inscripciones) 
        if (inscripcion->getAprobado() == false)
            cursosNoAprobados.push_back(inscripcion->getDataCurso());
    
    return cursosNoAprobados;
}

list<DTEjercicio> Estudiante::buscarInscripcion(string nombreCurso) {
    list<DTEjercicio> ejericiciosNoAprobados;
    list<Inscripcion*>::iterator it = this->inscripciones.begin();
    while(it != this->inscripciones.end() && !(*it)->buscarCurso(nombreCurso, ejericiciosNoAprobados, (*it))) 
        it++;
     
    if(it != this->inscripciones.end()) {
        ControladorCurso* cc = ControladorCurso::getInstancia();
        cc->guardarInscripcion((*it));
    }

    return ejericiciosNoAprobados;
}

DTEstudiante* Estudiante::getDataEstudiante() {
    DTEstudiante* dataEstudiante = new DTEstudiante(this->getNickname(),this->getContrasenia(), this->getNombre(), this->getDescripcion(), this->getNotificaciones(), this->getPaisDeResidencia(), this->getFechaDeNacimiento());
    return dataEstudiante;
} 

list<DTEstadisticaCurso> Estudiante::getEstadisticaCurso() {
    list<DTEstadisticaCurso> estadisticaEstudiante;
    for(auto& inscripcion: this->inscripciones) 
        estadisticaEstudiante.push_back(inscripcion->getPromedioCurso());
    
    return estadisticaEstudiante;
} 

void Estudiante::elimInscripcion(Inscripcion* inscripcion) {
    this->inscripciones.remove(inscripcion);
} 

DTUsuario* Estudiante::getDataUsuario() {
    return this->getDataEstudiante();
}

//Destructor
Estudiante::~Estudiante() {
    this->inscripciones.clear();
} 
