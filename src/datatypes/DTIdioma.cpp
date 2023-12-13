#include "../../include/DTIdioma.h"

DTIdioma::DTIdioma(){
    this->idioma = '\0';
}
DTIdioma::DTIdioma(string idioma){
    this->idioma = idioma;
}

string DTIdioma::getNombre() const{
    return this->idioma;
}


ostream& operator<<(ostream& os,const DTIdioma& idioma) {
    os << "Idioma: " + idioma.getNombre() << endl;
    return os;
}