 #include "../../include/DTEjercicio.h"

DTEjercicio::DTEjercicio()
{
    this->id = 0;
    this->frase = '\0';
    this->descripcion = '\0';
};

DTEjercicio::DTEjercicio(int id, string frase, string descripcion, string solucion, string tipo)
{
    this->id = id;
    this->frase = frase;
    this->descripcion = descripcion;
    this->solucion = solucion;
    this->tipo = tipo;
};

int DTEjercicio::getId() const
{
    return this->id;
};

string DTEjercicio::getFrase() const
{
    return this->frase;
};

string DTEjercicio::getDescripcion() const
{
    return this->descripcion;
};

string DTEjercicio::getSolucion() const {
    return this->solucion;
}

string DTEjercicio::getTipo() const {
    return this->tipo;
}

void DTEjercicio::toStringConsultaCurso() const{
    cout << " --Ejercicio: " + to_string(this->getId()) << endl;
    cout << "   Problema: " + this->getFrase() << endl;
    cout << "   Descripcion: " + this->getDescripcion() << endl;
    cout << "   Tipo de ejercicio: De " + this->getTipo() << endl;
}

ostream& operator<<(ostream& os, const DTEjercicio& e){
    os << "------------------------------------------" << endl;
    os << " -Ejercicio: " + to_string(e.getId()) << endl;
    os << "  Problema: " + e.getFrase() << endl;
    os << "  Descripcion: " + e.getDescripcion() << endl;
    os << "  Tipo de ejercicio: De " + e.getTipo() << endl;
    os << "------------------------------------------" << endl;

    return os;
}
 