#ifndef _DTNOTIFICACION_H
#define _DTNOTIFICACION_H

#include <iostream>
using namespace std;

class DTNotificacion {
    private:
        string idioma;
        string curso;
    public:
        //constructores
        DTNotificacion();
        DTNotificacion(string, string);
        //getters
        string getIdioma() const;
        string getCurso() const;
};

ostream& operator<<(ostream& os,const DTNotificacion& notificacion);

#endif
