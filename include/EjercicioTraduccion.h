#ifndef EJERCICIO_TRADUCCION_H
#define EJERCICIO_TRADUCCION_H

#include <iostream>
#include "Ejercicio.h"
//#include "Inscripcion.h"
using namespace std;

class EjercicioTraduccion : public Ejercicio {
private:
    string traduccion;
    string tipo;
public:
    // Constructores
    EjercicioTraduccion();
    EjercicioTraduccion(int id, string frase, string descripcion, string traduccion);
    // Destructor
    ~EjercicioTraduccion();
    // Getters
    string getTraduccion();
    // Setters
    void setTraduccion(string);
    // Verifica la respuesta de alguien que realizó el ejercicio
    bool verificarRespuesta(Inscripcion*, string traduccion);
    DTEjercicio getDataEjercicio();
    string getTipo();
};

#endif
