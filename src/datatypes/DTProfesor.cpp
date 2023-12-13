#include "../../include/DTProfesor.h"

DTProfesor::DTProfesor(){
    this->instituto = '\0';
    list<string> idiomas;
    this->idiomas = idiomas;
} 
DTProfesor::DTProfesor(string nickname, string contrasenia, string nombre, string descripcion, list<DTNotificacion> notificaciones, string instituto, list<string> idiomas): DTUsuario(nickname,contrasenia, nombre, descripcion, notificaciones){
    this->instituto = instituto;
    this->idiomas = idiomas;
} 
string DTProfesor::getInstituto() const{
    return this->instituto;
} 
list<string> DTProfesor::getIdiomas() const{
    return this->idiomas;
} 

void DTProfesor::toStringUsuario(){
    cout << "\n------------------------------------------" << endl;
    cout << " Nickname: " + this->getNickname() << endl;
    cout << " Contrasenia: " + this->getContrasenia() << endl;
    cout << " Nombre: " + this->getNombre() << endl;
    cout << " Descripcion: " + this->getDescripcion() << endl;
    cout << " Instituto: " + this->getInstituto() << endl;
    cout << " Idiomas: " << endl;
    list<string>::iterator it;
    list<string> idiomas = this->getIdiomas();
    for(it = idiomas.begin(); it != idiomas.end(); it++){
        cout << " -" << (*it) << endl;
    }
    cout << "------------------------------------------\n" << endl;
    delete this;

}
