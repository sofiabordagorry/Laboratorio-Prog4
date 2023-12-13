#include "../../include/DTNotificacion.h" 
 
 //constructores
DTNotificacion::DTNotificacion(){
    this->idioma = '\0';
    this->curso = '\0';
}

DTNotificacion::DTNotificacion(string i, string c){
    this->idioma = i;
    this->curso = c;
} 

//getters
string DTNotificacion::getIdioma() const{
    return this->idioma;
}

string DTNotificacion::getCurso() const{
    return this->curso;
}

//sobrecarga

ostream& operator<<(ostream& os,const DTNotificacion& notificacion){
    os << " -Idioma notificado: " + notificacion.getIdioma() << endl;
    os << " -Curso nuevo: " + notificacion.getCurso() << endl;
    os << "\n";
    return os;
}