#include <iostream>
#include "../../include/Factory.h"

void cu_consultarIdiomas() {
    factory *fab = factory::getInstancia(); 
    ICurso *icurso = fab->getICurso();

    list<DTIdioma> idiomas = icurso->listarIdiomas();

    if(idiomas.size() == 0){
        cout << "En este momento no hay ningun idioma para consultar, intentelo mas tarde.\n";
    } else{
        cout << "Idiomas actualmente registrados en el sistema:\n";
        for (list<DTIdioma>::iterator it = idiomas.begin(); it != idiomas.end(); it++)
        {
            cout << " -";
            cout << it->getNombre() << "\n"; 
        }
    }
    cout << "\n";
}