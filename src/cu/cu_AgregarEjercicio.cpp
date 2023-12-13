
#include "../../include/Factory.h"
#include <exception>
#include <cctype>

void cu_AgregarEjercicio() {

    factory *fab = factory::getInstancia(); // llamo a la instancia de la fabrica
    ICurso *icurso = fab->getICurso();      // llamo a la interfaz de curso

    // LISTAR CURSOS NO HABILITADOS
    list<DTCurso> noHabilitados;
    set<string> nombresNoHabilitados;
    noHabilitados = icurso->listarCursosNoHabilitados();
    if(noHabilitados.size()==0){
        cout << "En este momento no hay cursos sin habilitar. \nCree un nuevo curso para poder agregarle ejercicios.\n\n";
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

        cout << "Ingrese el nombre del curso al que le quiere agregar un ejercicio: ";
        string cursoSel;
        DTCurso curso;
        getline(cin, cursoSel);

        while (nombresNoHabilitados.count(cursoSel) == 0)
        {
            cout << "El nombre ingresado no corresponde a ningún curso. Intente de nuevo: ";
            getline(cin, cursoSel);
        }

        // LISTAR LECCIONES DEFINIDAS
        list<DTCurso>::iterator it = noHabilitados.begin();
        while(it != noHabilitados.end() && it->getNombre() != cursoSel)
            it++;
        
        curso = *it;

        vector<DTLeccion> lecciones = curso.getDataLeccion();
        set<int> IdLecciones;

        if(lecciones.size() == 0){
            cout << "En este momento no hay lecciones en este curso, puede ingresar una leccion o probar con otro curso.\n\n ";
        } else {

            for (vector<DTLeccion>::iterator it = lecciones.begin(); it != lecciones.end(); it++) // Los pongo en un set de int
            {
                IdLecciones.insert(it->getId());
            }

        
            cout << "Esta es la lista de lecciones que se encuentran definidas en el curso:\n";

            for (vector<DTLeccion>::iterator it = lecciones.begin(); it != lecciones.end(); it++)
            {
                cout << " -id:" +  to_string(it->getId()) << " -" << it->getTema() << endl;;
            }
            
            string leccion = "0";
            bool es = true;
            
            while(IdLecciones.count(stoi(leccion)) == 0){
                cout << "Ingrese el id que se encuentra junto a la que le quiere agregar el ejercicio: ";
                do{
                    es = true;
                    getline(cin, leccion);
                    for (char c : leccion) {
                        if (!isdigit(c)) {
                            es = false;
                        }
                    }
                    
                    if(!es){
                        cout << "Ingrese el id que se encuentra junto a la que le quiere agregar el ejercicio: ";
                    }

                }while(!es);
            }

            int intleccion = stoi(leccion);

            while (IdLecciones.count(intleccion) == 0)
            {
                cout << "El id ingresado no corresponde a ninguna lección. Intente de nuevo: ";
                getline(cin, leccion);
            }

            // ELIJO ENTRE EJERCICIO DE COMPLETAR Y EJERCICIO DE TRADUCCION
            string agregar;

                // ELIJO ENTRE EJERCICIO DE COMPLETAR Y EJERCICIO DE TRADUCCION
                cout << "Si desea agregar un ejercicio de completar ingrese 1, si desea agregar un ejercicio de traducción ingrese 0: ";
                string k;
                getline(cin, k);

                while(true){
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
                        icurso->crearEjercicioTraducir(cursoSel, intleccion, frase, descripcion, traduccion);
                        break;
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
                        cout << "Ingrese las palabras correctas del ejercicio. Escriba las palabras separandolas con coma y espacio entre cada una (ejemplo: palabras, faltantes) ";
                        getline(cin, palabras);
                        icurso->crearEjercicioCompletar(cursoSel, intleccion, frase, descripcion, palabras);
                        break;
                    }
                    else
                    {
                        cout << "El número ingresado no corresponde a un comando. Intente de nuevo: ";
                        getline(cin, k);
                    }
                }
        }
    }
    for(list<DTCurso>::iterator itera = noHabilitados.begin(); itera != noHabilitados.end(); itera++){
        delete itera->getDataProfesor();
    }
    noHabilitados.clear();
};
