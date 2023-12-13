#include "../../include/EjercicioTraduccion.h"

// Constructor por defecto
 EjercicioTraduccion::EjercicioTraduccion():Ejercicio()
{
    this->traduccion = '\0';
    this->tipo = "Traduccion";
} 

// //Constructor por parámetro
EjercicioTraduccion::EjercicioTraduccion(int id, string frase, string descripcion, string traduccion):Ejercicio(id, frase, descripcion)
{
    this->traduccion = traduccion;
    this->tipo = "Traduccion";
}

// Getters
string EjercicioTraduccion::getTraduccion()
{
     return this->traduccion;
}
 
// // Setters
 void EjercicioTraduccion::setTraduccion(string traduccion)
 {
     this->traduccion = traduccion;
 }

// verifica si la respuesta es correcta o no
bool EjercicioTraduccion::verificarRespuesta(Inscripcion* i, string traduccion)
{
     if(traduccion == this->traduccion) {
         this->setInscripcion(i);
         return true;
     } else 
         return false;
}

string EjercicioTraduccion::getTipo() {
    return this->tipo;
}

DTEjercicio EjercicioTraduccion::getDataEjercicio(){
    DTEjercicio ej(this->getId(), this->getFrase(), this->getDescripcion(), this->getTraduccion(), this->getTipo());
    return ej;
}

// Destructor
EjercicioTraduccion::~EjercicioTraduccion() {}
