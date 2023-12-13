#include "../../include/DTInscripcion.h" 
 
//Constructores
DTInscripcion::DTInscripcion(){
    this->aprobado = false;
    DTFecha f;
    this->fecha = f;
}

DTInscripcion::DTInscripcion(bool ap, DTFecha f){
    this->aprobado = ap;
    this->fecha = f;
}

//Getters
 bool DTInscripcion::getAprobado() const{
    return this->aprobado;
} 

DTFecha DTInscripcion::getFecha() const{
    return this->fecha;
} 

//sobrecarga

ostream& operator<<(ostream& os,const DTInscripcion& inscripcion){
    string aprobado;
    if(inscripcion.getAprobado())
        aprobado = "aprobado";
    else
        aprobado = "no aprobado";

    os << " Fecha de inscripcion: " << inscripcion.getFecha() << endl;
    os << " Estado de aprobacion: " + aprobado << endl;
    return os;
}