#include "../../include/DTUsuario.h"

DTUsuario::DTUsuario(){
    this->nickname = '\0';
    this->contrasenia = '\0';
    this->nombre = '\0';
    this->descripcion = '\0';
    list<DTNotificacion> notificaciones;
    this->notificaciones = notificaciones;
}

DTUsuario::DTUsuario(string nickname, string contrasenia, string nombre, string descripcion, list<DTNotificacion> notificaciones){
    this->nickname = nickname;
    this->contrasenia = contrasenia;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->notificaciones = notificaciones;
}

string DTUsuario::getNickname() const{
    return this->nickname;
}

string DTUsuario::getContrasenia() const{
    return this->contrasenia;
}
string DTUsuario::getNombre() const{
    return this->nombre;
}
string DTUsuario::getDescripcion() const{
    return this->descripcion;
}
list<DTNotificacion> DTUsuario::getNotificaciones() const{
    return this->notificaciones;
} 

