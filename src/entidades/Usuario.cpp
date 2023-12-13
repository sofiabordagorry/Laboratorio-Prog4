#include "../../include/Usuario.h"

Usuario::Usuario(){
    this->nickname = "\0";
    this->contrasenia = "\0";
    this->nombre = "\0";
    this->descripcion = "\0";
    list<DTNotificacion> correo;
    this->correo = correo;
}

Usuario::Usuario(string nickname,string contrasenia,string nombre,string descripcion){
    this->nickname = nickname;
    this->contrasenia = contrasenia;
    this->nombre = nombre;
    this->descripcion = descripcion;
    list<DTNotificacion> correo;
    this->correo = correo;
}
//Setters
void Usuario::setNickname(string nickname){
    this->nickname = nickname;
}
void Usuario::setContrasenia(string contrasenia){
    this->contrasenia = contrasenia;
}
void Usuario::setNombre(string nombre){
    this->nombre = nombre;
}
void Usuario::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}
//Getters
string Usuario::getNickname(){
    return this->nickname;
} 

string Usuario::getContrasenia(){
    return this->contrasenia;
}

string Usuario::getNombre(){
    return this->nombre;
} 
string Usuario::getDescripcion(){
    return this->descripcion;
}

list<DTNotificacion> Usuario::getNotificaciones(){
    return this->correo;
} 

//Otras operaciones
void Usuario::vaciarNotificaciones(){
    this->correo.clear();
}
void Usuario::notificar(DTNotificacion noti){
    this->correo.push_back(noti);
}
//Destructor
Usuario::~Usuario(){

}