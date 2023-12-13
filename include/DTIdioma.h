#ifndef DTIDIOMA
#define DTIDIOMA
#include <iostream>

using namespace std;

class DTIdioma {
    private:
        string idioma;
    public:
        // Constructores
        DTIdioma();
        DTIdioma(string idioma);
        // Getters
        string getNombre() const;
};

ostream& operator<<(ostream& os, const DTIdioma& idioma);
    

#endif