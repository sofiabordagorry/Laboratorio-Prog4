#ifndef _DTUSUARIO_H
#define _DTUSUARIO_H

#include <iostream>
#include <list>
#include "DTNotificacion.h"
using namespace std;


class DTUsuario {
    private:
        string nickname;
        string contrasenia;
        string nombre;
        string descripcion;
        list<DTNotificacion> notificaciones;
    public:
        //Constructores
        DTUsuario();
        DTUsuario(string nickname, string contrasenia, string nombre, string descripcion, list<DTNotificacion> notificaciones);
        //Getters
        string getNickname() const;
        string getContrasenia() const;
        string getNombre() const;
        string getDescripcion() const;
        list<DTNotificacion> getNotificaciones() const;
        virtual void toStringUsuario() = 0;
};

#endif
