#ifndef _DTPARESTUDIANTECURSO_H
#define _DTPARESTUDIANTECURSO_H
#include <iostream>
#include "DTInscripcion.h"
using namespace std;

class DTParEstudianteCurso{
    private:
        string nombreCurso;
        string nickname;
        DTInscripcion inscripcion;
    public:
        // Constructores
        DTParEstudianteCurso();
        DTParEstudianteCurso(string nombreC, string nickname, DTInscripcion i);

        // Getters
        string getNombreCurso() const;
        string getNickname() const;
        DTInscripcion getDTInscripcion() const;
};

ostream& operator<<(ostream& os,const DTParEstudianteCurso& ec);

#endif