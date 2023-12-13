// Declaración del DTFecha

#ifndef _DTFECHA_H
#define _DTFECHA_H

#include <iostream>
using namespace std;

class DTFecha {
    private:
        int dia, mes, anio;
    public: 
        //Constructores
        DTFecha();
        DTFecha(int, int, int);
        DTFecha(const DTFecha&);
        //Getters
        int getDia() const;
        int getMes() const;
        int getAnio() const;
        //Sobrecarga de operadores de == y !=
        bool operator==(DTFecha&);
        bool operator!=(DTFecha&);
};

//Sobrecarga del operador de <<
ostream& operator<<(ostream&, const DTFecha&);

#endif