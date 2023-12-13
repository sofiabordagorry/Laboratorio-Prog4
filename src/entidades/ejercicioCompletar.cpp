#include "../../include/EjercicioCompletar.h"

// Constructor por defecto
EjercicioCompletar::EjercicioCompletar():Ejercicio()
{
    this->palabras = '\0';
    this->tipo = "Completar";
}

// // Constructor por parámetro
EjercicioCompletar::EjercicioCompletar(int id, string frase, string descripcion, string palabras):Ejercicio(id, frase, descripcion)
{
    this->palabras = palabras;
    this->tipo = "Completar";
}

// Getters
string EjercicioCompletar::getPalabras()
{
    return this->palabras;
}

// Setters
void EjercicioCompletar::setPalabras(string palabras)
{
    this->palabras = palabras;
}

//verifica si la respuesta es correcta o no
bool EjercicioCompletar::verificarRespuesta(Inscripcion* i, string palabras)
{
    if (this->palabras == palabras) {
        this->setInscripcion(i);
        return true;
    } else 
        return false;
}

DTEjercicio EjercicioCompletar::getDataEjercicio() {
    DTEjercicio dataEj(this->getId(), this->getFrase(), this->getDescripcion(), this->palabras, this->tipo);
    return dataEj;
}

string EjercicioCompletar::getTipo() {
    return this->tipo;
}

// Destructor
EjercicioCompletar::~EjercicioCompletar() {}
