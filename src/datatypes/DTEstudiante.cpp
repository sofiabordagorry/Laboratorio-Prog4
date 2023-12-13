#include "../../include/DTEstudiante.h"

DTEstudiante::DTEstudiante(){
    DTFecha fecha = DTFecha(); 
    this->fechaDeNacimiento = fecha;
    this->paisDeResidencia = "\0";
} 

 DTEstudiante::DTEstudiante(string nickname, string password, string nombre, string descripcion, list<DTNotificacion> notificaciones, string pais, DTFecha fechaDeNacimiento):DTUsuario(nickname, password, nombre, descripcion, notificaciones){
    this->paisDeResidencia = pais;
    this->fechaDeNacimiento = fechaDeNacimiento;
} 

string DTEstudiante::getPaisDeResidencia() const{
    return this->paisDeResidencia;
}

DTFecha DTEstudiante::getFechaDeNacimiento() const{
    return this->fechaDeNacimiento;
}

void DTEstudiante::toStringUsuario() {
    cout << "\n------------------------------------------" << endl;
    cout << " Nickname: " + this->getNickname() << endl;
    cout << " Nombre: " + this->getNombre() << endl;
    cout << " Contrasenia: " + this->getContrasenia() << endl;
    cout << " Descripcion: " + this->getDescripcion() << endl;
    cout << " Pais de residencia: " + this->getPaisDeResidencia() << endl;
    cout << " Fecha de nacimiento: " << this->getFechaDeNacimiento() << endl;
    cout << "------------------------------------------\n" << endl;

    delete this;
}