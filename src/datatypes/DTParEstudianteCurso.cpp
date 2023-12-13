#include "../../include/DTParEstudianteCurso.h"

DTParEstudianteCurso::DTParEstudianteCurso(){
    this->nickname = '\0';
    this->nombreCurso = '\0';
    DTInscripcion i;
    this->inscripcion = i;    
}

DTParEstudianteCurso::DTParEstudianteCurso(string nombreC, string nickname, DTInscripcion i){
    this->nombreCurso = nombreC;
    this->nickname = nickname;
    this->inscripcion = i;
}

 string DTParEstudianteCurso::getNombreCurso() const{
    return this->nombreCurso;
} 
 string DTParEstudianteCurso::getNickname() const{
    return this->nickname;
} 

 DTInscripcion DTParEstudianteCurso::getDTInscripcion() const{
    return this->inscripcion;
} 

 ostream& operator<<(ostream& os,const DTParEstudianteCurso& ec){
    os << " Nickname: " + ec.getNickname() + ", Curso: " + ec.getNombreCurso() + "\n";
    os << ec.getDTInscripcion();
    return os;
} 