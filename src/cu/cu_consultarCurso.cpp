#include "../../include/Factory.h"

void cu_consultarCurso() {
    factory *fab = factory::getInstancia(); 
    ICurso *icurso = fab->getICurso();

    list<DTCurso> nomCursos = icurso->listarCursos();

    if(nomCursos.size() == 0){
        cout << "En este momento no hay ningun curso para consultar, cree algun curso para poder consultarlo.\n";
    } else {
        cout << "Lista de todos los cursos del sistema: \n";
        for(list<DTCurso>::iterator it = nomCursos.begin(); it != nomCursos.end(); ++it)
            cout << " -" + it->getNombre() << "\n";

        cout << "Elija el nombre del curso que quiere consultar: ";
        string nomCurso;
        getline(cin, nomCurso);
        while(true) {
            list<DTCurso>::iterator it = nomCursos.begin();

            while(it != nomCursos.end() && it->getNombre() != nomCurso)
                it++;

            if(it != nomCursos.end())
                break;
            else { 
                cout << "El nombre ingresado no existe, intente de nuevo: ";
                getline(cin, nomCurso);
            }
            
        }
        cout << "\nInformacion del curso " + nomCurso + ": ";
        DTCurso cursoConsultado = icurso->consultarCurso(nomCurso);
        cursoConsultado.toStringConsultaCurso();
        delete cursoConsultado.getDataProfesor();

        for(list<DTCurso>::iterator it = nomCursos.begin(); it != nomCursos.end(); ++it)
            delete (*it).getDataProfesor();

        nomCurso.clear();
        
    }
}
