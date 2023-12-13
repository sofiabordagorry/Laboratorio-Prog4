#include <iostream>
#include "../../include/DTIdioma.h"
#include "../../include/ControladorCurso.h"
#include "../../include/Factory.h"

using namespace std;

void cu_AltaDeIdioma() {
    factory* fab = factory::getInstancia();
    ICurso* iCurso = fab->getICurso();

    string idioma;

    cout << "Inserte el nombre del idioma a registrar: ";
    getline(cin,idioma);

    DTIdioma dtidioma(idioma);
    bool t = iCurso->registrarIdioma(dtidioma);
    if (t) {
        cout << "\n ---- Idioma registrado con exito ---- \n\n";
    } else {
        cout << "\n ---- Idioma ya existe en el sistema ---- \n\n";
    }
}