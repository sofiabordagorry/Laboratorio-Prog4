#ifndef _USUARIO_H
#define _USUARIO_H

#include <iostream>
#include <list>
#include "DTNotificacion.h"
#include "IObserver.h"
#include "DTUsuario.h"
using namespace std;

class Usuario : public IObserver{
    private:
        string nickname;
        string contrasenia;
        string nombre;
        string descripcion;
        list<DTNotificacion> correo;
    public:
        //Constructores
        Usuario();
        Usuario(string nickname,string contrasenia,string nombre,string descripcion);
        //Setters
        void setNickname(string);
        void setContrasenia(string);
        void setNombre(string);
        void setDescripcion(string);
        //Getters
        string getNickname();
        string getContrasenia();
        string getNombre();
        string getDescripcion();
        list<DTNotificacion> getNotificaciones();
        //Otras operaciones
        virtual DTUsuario* getDataUsuario() = 0;
        void vaciarNotificaciones();
        void notificar(DTNotificacion);
        //Destructor
        virtual ~Usuario();
};

#endif