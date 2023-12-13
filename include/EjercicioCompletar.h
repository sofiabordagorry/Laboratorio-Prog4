#ifndef EJERCICIO_COMPLETAR_H
#define EJERCICIO_COMPLETAR_H

#include <iostream>
#include "Ejercicio.h"
//#include "Inscripcion.h"
using namespace std;

class EjercicioCompletar : public Ejercicio {
private:
    string palabras;
    string tipo;
public:
    // Constructores
    EjercicioCompletar();
    EjercicioCompletar(int id, string frase, string descripcion, string palabras);
    // Destructor
    ~EjercicioCompletar();
    // Getters
    string getPalabras();
    // Setters
    void setPalabras(string palabras);
    // Verifica la respuesta de alguien que realizó el ejercicio
    bool verificarRespuesta(Inscripcion*, string palabras);
    DTEjercicio getDataEjercicio();
    string getTipo();
};



#endif
