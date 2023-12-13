#ifndef _DTESTADISTICACURSO_H
#define _DTESTADISTICACURSO_H 

#include <iostream>

using namespace std;

class DTEstadisticaCurso{
    private:
        float promedio;
        string nombreCurso;
    public:
        //constructores
        DTEstadisticaCurso();
        DTEstadisticaCurso(float, string);
        //getters
        float getPromedio() const;
        string getNombreCurso() const;
};

//sobrecarga
ostream& operator<<(ostream& os,const DTEstadisticaCurso& est);

#endif
