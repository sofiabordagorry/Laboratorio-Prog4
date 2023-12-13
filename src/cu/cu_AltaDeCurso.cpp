#include "../../include/Factory.h"
#include "../../include/TipoDificultad.h"
#include <iostream>
#include <exception>
#include <list>

using namespace std;

void cu_AltaDeCurso()
{

    factory *fab = factory::getInstancia();  // llamo a la instancia de la fabrica
    ICurso *icurso = fab->getICurso();       // llamo a la interfaz de curso
    IUsuario *iusuario = fab->getIUsuario(); // llamo a la interfaz de usuario

    // LISTAR PROFESORES
    list<DTProfesor*> dtprofesores = iusuario->listarProfesores();
    set<string> profesores;
    if(dtprofesores.size() == 0){
        cout << "En este momento no hay profesores disponibles para crear un curso\n\n";
    }else{
        cout << "Esta es la lista de profesores:\n";

        for (list<DTProfesor*>::iterator it = dtprofesores.begin(); it != dtprofesores.end(); it++) // Los pongo en un set de strings
        {
            profesores.insert((*it)->getNickname());
            cout << " -" + (*it)->getNickname() << endl;
            delete (*it);
        }

        dtprofesores.clear();
        
        string prof;
        cout << "Ingrese el nombre del que será profesor en este curso: ";
        getline(cin, prof);

        while ((profesores.count(prof) == 0)){ //verifico profesor valido
        
            cout << "El nombre ingresado no corresponde a ningún profesor, intente de nuevo: ";
                
            cin.ignore();
            getline(cin, prof);
        }
        // LISTAR IDIOMAS PROFESOR
        list<DTIdioma> dtidiomas = iusuario->listarIdiomasProfesor(prof);
        set<string> nombreIdiomas;

        cout << "Esta es la lista de idiomas que puede enseñar este profesor:\n";

        for (list<DTIdioma>::iterator it = dtidiomas.begin(); it != dtidiomas.end(); it++) // Los pongo en un set de string
        {
            nombreIdiomas.insert(it->getNombre());
            cout << " -" + it->getNombre() << endl;
        }


        string idiomaIng;
        cout << "Ingrese el idioma de este curso: ";
        getline(cin, idiomaIng);
        while (nombreIdiomas.count(idiomaIng) == 0)
        {
            cout << "El nombre ingresado no corresponde a ningún idioma del profesor. Intente de nuevo: ";
            getline(cin, idiomaIng);
        }

        // LISTAR CURSOS HABILITADOS SI REQUIERE PREVIAS

        cout << "Si el curso tiene previas ingrese 1, si no presione cualquier tecla: ";
        string previasQ;
        getline(cin, previasQ);

        set<string> previas;
        
        if (previasQ == "1")
        {
            list<DTCurso> Habilitados;
            set<string> nombresHabilitados;
            Habilitados = icurso->listarCursosHabilitados();

            string nu = "1";
            if(Habilitados.size() == 0){
            cout << "En este momento no hay ningun curso habilitado para poner como previa.\n Si desea continuar sin ponerle previas ingrese '1' si no otra tecla: "; 
            
            cin >> nu;
            
            }
            if(nu == "1"){

                cout << "Esta es la lista de cursos que se encuentran habilitados:\n";

                for (list<DTCurso>::iterator it = Habilitados.begin(); it != Habilitados.end(); it++) // Los pongo en un set de strings
                {
                    nombresHabilitados.insert(it->getNombre());
                    cout << " -" + it->getNombre() << endl; 
                }

                cout << "Ingrese el nombre del curso que quiere que sea previa del nuevo curso: ";
                string cursoSel;
                getline(cin, cursoSel);

                while (previasQ == "1")
                {
                    while (nombresHabilitados.count(cursoSel) == 0)
                    {
                        cout << "El nombre ingresado no corresponde a ningún curso. Intente de nuevo: ";
                        getline(cin, cursoSel);
                    };

                    previas.insert(cursoSel);
                    cout << "Si desea agregar otro curso ingrese 1, de lo contrario ingrese cualqiuer otra tecla: ";
                    getline(cin, previasQ);
                }
            }
        }


        // CREAR CURSO CON  LOS DATOS QUE ME DEN

        string nombre, descripcion;
        int dif;
        int diffi = -1;
        cout << "Ingrese dificultad del curso a crear, sus opciones son: \nPara Principiante ponga 0, Medio ponga 1 o Avanzado ponga 2: ";
        cin >> dif;

        while (diffi == -1){
            if ( dif == 0 || dif == 1 || dif == 2)
                diffi = dif;
            else
            {
                cout << "El numero ingresado no corresponde a ninguna dificultad, ingrese de nuevo: ";
                cin >> dif;

            }
        }
        cout << "Ingrese nombre del curso a crear: ";
        cin.ignore();
        getline(cin, nombre);

        cout << "Ingrese descripcion del curso a crear: ";
        //cin.ignore();
        getline(cin, descripcion);
        
        icurso->crearCurso(prof, idiomaIng, nombre, descripcion, dif, previas);

        cout << "Si desea agregar lecciones ingrese 1, si no ingrese cualquier otra tecla: ";
        string agregarl;
        getline(cin, agregarl);
        
        while (agregarl=="1"){
            cout << "Ingrese el tema de la leccion: ";
            
            string tema, objetivo;
            //cin.ignore();
            getline(cin, tema);

            cout << "Ingrese el objetivo de la leccion: ";

            //cin.ignore();
            getline(cin, objetivo);
            int id = icurso->crearLeccion(nombre, tema, objetivo);

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
                        icurso->crearEjercicioTraducir(nombre, id, frase, descripcion, traduccion);
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
                        icurso->crearEjercicioCompletar(nombre, id, frase, descripcion, palabras);
                    }
                    else
                    {
                        cout << "El número ingresado no corresponde a un comando. Intente de nuevo";
                    }
                cout << "Si desea agregar otro ejercicio ingrese 1. Para salir ingrese cualquier otra tecla: ";
                getline(cin, agregar);
            }
            cout << "Si desea agregar otra leccion ingrese 1. Para salir ingrese cualquier otra tecla: ";
            getline(cin, agregarl);
        }
    }
}
