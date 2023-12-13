#include <iostream>
#include <set>
#include "../../include/Factory.h"
#include "../../include/DTIdioma.h"
#include "../../include/ControladorUsuario.h"


using namespace std;

void cu_EliminarSuscripciones()
{
    factory *fab = factory::getInstancia();
    IUsuario *iusuario = fab->getIUsuario();


    list<DTEstudiante*> estudiantes = iusuario->listarEstudiantes();
    list<DTProfesor*> profesores = iusuario->listarProfesores();

    list<DTEstudiante*>::iterator ite;
    list<DTProfesor*>::iterator itp;

    set<string> usuarios;
    cout << "---LISTA DE USUARIOS EN EL SISTEMA---\n";
    for(ite = estudiantes.begin(); ite != estudiantes.end(); ite++){
        cout << "  -" << (*ite)->getNickname() << endl;
        usuarios.insert((*ite)->getNickname());
        delete (*ite);
    }
    for(itp = profesores.begin(); itp != profesores.end(); itp++){
        cout << "  -" << (*itp)->getNickname() << endl;
        usuarios.insert((*itp)->getNickname());
        delete (*itp);
    }
    estudiantes.clear();
    profesores.clear();

    if(usuarios.size()==0){
        cout << "En este momento no hay usuarios para eliminar sus suscripciones, registre alguno primero.\n\n";
    }else{
        string nickname;
        cout << "Ingrese el nickname del usuario que quiere desuscribirse a un idioma: ";
        getline(cin, nickname);

        while (!iusuario->verificarExistenciaDeUsuario(nickname)) {
            cout << "Usuario no existe en el sistema, ingrese un nickname válido: ";
            getline(cin, nickname);
        }

        if (iusuario->listarIdiomasSuscrito(nickname).size() == 0) {
            cout << "El usuario no está suscrito a ningún idioma.\n\n";
        } else {
            cout << "Lista de idiomas a los que está suscrito el usuario: \n";
            list<DTIdioma> idiomas = iusuario->listarIdiomasSuscrito(nickname);//nueva operacion
            set<string> nomIdiomas;
            for (list<DTIdioma>::iterator it = idiomas.begin(); it != idiomas.end(); it++)
            {
                    cout << " -" << *it;
                    nomIdiomas.insert((*it).getNombre());
            }
            string nombreIdioma;
            cout << "Ingrese el nombre del idioma a desuscribir, o FIN para terminar: ";
            getline(cin, nombreIdioma);
            while ((nombreIdioma != "FIN" && nombreIdioma != "Fin" && nombreIdioma != "fin") && (nomIdiomas.size() != 0))
            {
                while (nomIdiomas.count(nombreIdioma) == 0)
                {
                    cout << "Nombre invalido. Ingrese el nombre de un idioma existente en la lista anterior: ";
                    getline(cin, nombreIdioma);
                }
                iusuario->desuscribirseDeIdioma(nombreIdioma);
                cout << "---- Suscripción eliminada ----\n";
                nomIdiomas.erase(nombreIdioma);
                if(nomIdiomas.size() == 0){
                    cout << "\n---- Ya se ha desuscrito de todos los idiomas ----\n\n";
                }else{
                    cout << "Ingrese el nombre del idioma a desuscribir, o FIN para terminar: ";
                    getline(cin, nombreIdioma);
                }
            }
        }
    }
}