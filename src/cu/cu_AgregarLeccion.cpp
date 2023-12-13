#include "../../include/Factory.h"
#include <exception>

void cu_AgregarLeccion() {

    factory *fab = factory::getInstancia(); // llamo a la instancia de la fabrica
    ICurso *icurso = fab->getICurso();      // llamo a la interfaz de curso

    // LISTAR CURSOS NO HABILITADOS

    list<DTCurso> noHabilitados;
    set<string> nombresNoHabilitados;
    noHabilitados = icurso->listarCursosNoHabilitados();

    if(noHabilitados.size()==0){
        cout << "En este momento no hay cursos sin habilitar. \nCree un nuevo curso para poder agregarle lecciones.\n\n";
    }else{

        for (list<DTCurso>::iterator it = noHabilitados.begin(); it != noHabilitados.end(); it++) // Los pongo en un set de strings
        {
            nombresNoHabilitados.insert(it->getNombre());
        }

        cout << "Esta es la lista de cursos que no se encuentran habilitados: \n";
        for (set<string>::iterator it = nombresNoHabilitados.begin(); it != nombresNoHabilitados.end(); it++) // Recorro el set de strings
        {
            cout << " -" << *it << endl;
        }

        cout << "Ingrese el nombre del curso al que le quiere agregar una lección: ";
        string cursoSel;
        DTCurso curso;
        getline(cin, cursoSel);

        while (nombresNoHabilitados.count(cursoSel) == 0)
        {
            cout << "El nombre ingresado no corresponde a ningún curso. Intente de nuevo: ";
            getline(cin, cursoSel);
        }

        

        // RECIBO EL CURSO Y LO BUSCO EN EL SET DE CURSOS DEL CONTROLADOR
            string tema, objetivo;
            cout << "Ingrese el tema: ";
            getline(cin, tema);
            cout << "Ingrese el objetivo de la leccion: ";
            getline(cin, objetivo);

            // CREO LECCION
            int id = icurso->crearLeccion(cursoSel, tema, objetivo);
            cout << "Si desea agregar ejercicios a la lección ingrese 1. Para salir ingrese cualquier otra tecla: ";
            string agregar;
            getline(cin, agregar);

            while (agregar == "1")
            {
                // ELIJO ENTRE EJERCICIO DE COMPLETAR Y EJERCICIO DE TRADUCCION
                cout << "Si desea agregar un ejercicio de completar ingrese 1, si desea agregar un ejercicio de traducción ingrese 0. Para salir ingrese cualquier otra tecla: ";
                string k;
                getline(cin, k);
                    if (k == "0")
                    {
                        string frase;
                        string descripcion;
                        string traduccion;
                        cout << "Ingrese el problema: ";
                        getline(cin, frase);
                        cout << "Ingrese la descripcion: ";
                        getline(cin, descripcion);
                        cout << "Ingrese la traduccion correcta del ejercicio: ";
                        getline(cin, traduccion);
                        icurso->crearEjercicioTraducir(cursoSel, id, frase, descripcion, traduccion);
                    }
                    else if (k == "1")
                    {
                        string frase;
                        string descripcion;
                        string palabras;
                        cout << "Ingrese el problema: ";
                        getline(cin, frase);
                        cout << "Ingrese la descripción: ";
                        getline(cin, descripcion);
                        cout << "Ingrese las palabras correctas del ejercicio. Escriba las palabras separandolas con coma y espacio entre cada una (ejemplo: palabras, faltantes): ";
                        getline(cin, palabras);
                        icurso->crearEjercicioCompletar(cursoSel, id, frase, descripcion, palabras);
                    }
                    else
                    {
                        cout << "El número ingresado no corresponde a un comando. Intente de nuevo";
                    }
                cout << "Si desea agregar otro ejercicio ingrese 1. Para salir ingrese cualquier otra tecla: ";
                getline(cin >> ws, agregar);
            }
    }

         for(list<DTCurso>::iterator itera = noHabilitados.begin(); itera != noHabilitados.end(); itera++){
            delete itera->getDataProfesor();
        }
        noHabilitados.clear();
}
