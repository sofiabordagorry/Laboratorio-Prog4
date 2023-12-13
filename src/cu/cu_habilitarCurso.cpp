#include "../../include/Factory.h"
#include <iostream>
using namespace std;

void cu_HabilitarCurso(){
    factory * fab = factory::getInstancia();
    ICurso * icurso = fab->getICurso();

    list<DTCurso> cursosNoHab = icurso->listarCursosNoHabilitados();//Nueva operacion de ICurso;

    if(cursosNoHab.size() == 0){
        cout << "En este momento no hay ningun curso no habilitado, intentelo mas tarde.\n";
    } else {

        cout << "Lista de cursos no habilitados:\n";
        list<DTCurso>::iterator it;
        for(it = cursosNoHab.begin(); it != cursosNoHab.end();it++){
            cout << " -" + it->getNombre() << endl;
        }
        cout << "Seleccione uno de los nombres de la lista: ";
        string nombreCurso;
        getline(cin, nombreCurso);
        while(true) {
            list<DTCurso>::iterator iter = cursosNoHab.begin();
            while(iter != cursosNoHab.end() && iter->getNombre() != nombreCurso)
                iter++;
            
            if(iter != cursosNoHab.end()) 
                break;
            else {
                cout << "El nombre del curso no es valido, intente de nuevo: ";
                getline(cin, nombreCurso);
            }
        }

        for(list<DTCurso>::iterator it = cursosNoHab.begin(); it != cursosNoHab.end(); ++it)
            delete (*it).getDataProfesor();
            
        cursosNoHab.clear();

        bool habilitado = icurso->habilitarCurso(nombreCurso);//Nueva operacion de icurso
        if(!habilitado){
            cout << "El curso seleccionado no se puede habilitar ya que o no tiene lecciones o alguna de las lecciones no tiene un ejercicio\n";
        }else{
            cout << "\n ---- Se ha habilitado el curso correctamente ----\n\n";
        }
    }
}