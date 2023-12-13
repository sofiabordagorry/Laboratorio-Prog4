#include "../../include/Factory.h"
#include <set>

using namespace std;

void cu_eliminarCurso(){
    factory *fab = factory::getInstancia(); // llamo a la instancia de la fabrica
    ICurso *icurso = fab->getICurso();      // llamo a la interfaz de curso

    list<DTCurso> c = icurso->listarCursos();
    if (c.size() == 0) {
        cout << "No hay nigun curso para eliminar.\n\n";
    } else {
        cout << "Cursos del sistema: \n";
        for (list<DTCurso>::iterator it = c.begin(); it != c.end(); it++){ // muestro cada nombre
            cout << " -" + it->getNombre() + "\n";
        }
        string nombre;
        cout << "Ingrese el nombre del curso que desea eliminar: ";
        bool esta = true;
        while(esta) {
            getline(cin, nombre);
            list<DTCurso>::iterator it = c.begin();
            while( it != c.end() && it->getNombre() != nombre) //verifico el nombre
                it++;

            if(it == c.end()) //no esta el nombre
                cout << "Nombre incorrecto, ingrese nuevamente: ";
            else 
                esta = false;
        }

        for(list<DTCurso>::iterator it = c.begin(); it != c.end(); ++it)
            delete (*it).getDataProfesor();
            
        c.clear();

        icurso->eliminarCurso(nombre);
        cout << "\n---- El curso " + nombre + " ha sido eliminado ----\n\n";
    }
}
