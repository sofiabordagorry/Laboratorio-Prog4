#ifndef _DTEJERCICIO_H
#define _DTEJERCICIO_H
#include <iostream>

using namespace std;

class DTEjercicio {
    private:
        int id;
        string frase;
        string descripcion;
        string tipo;
        string solucion;
    public:
        // Constructores
        DTEjercicio();
        DTEjercicio(int id, string frase, string descripcion, string solucion, string tipo);
        // Getters
        int getId() const;
        string getFrase() const;
        string getDescripcion() const;
        string getTipo() const;
        string getSolucion() const;
        void toStringConsultaCurso()const;
};

ostream& operator<<(ostream&,const DTEjercicio&);

#endif
