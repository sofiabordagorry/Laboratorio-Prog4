# include <iostream>
using namespace std;

#include "../../include/Factory.h"
#include "../../include/IUsuario.h"

void cu_suscribirseANotificaciones(){
    factory * fab = factory::getInstancia();
    IUsuario * iusuario = fab->getIUsuario();

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

    if(usuarios.size() == 0) 
        cout << "En este momento no hay usuarios para suscribirse, registre alguno primero.\n\n";
    else {
        string nickname;
        cout << "Ingrese el nickname del usuario al que desea suscribir a idiomas: ";
        bool usuValido;
        do{
            getline(cin, nickname);
            usuValido = (usuarios.count(nickname) != 0);
            if(!usuValido){
                cout << "Ha ingresado un nickname invalido, por favor intente nuevamente: ";
            }
        }while(!usuValido);
        cout << "A continuacion se listan los idiomas a los cuales no esta suscrito el usuario: " << nickname << "\n";
        list<DTIdioma> idiomasNoSus = iusuario->listarIdiomasNoSuscrito(nickname);

        if(idiomasNoSus.size() == 0) 
            cout << "No hay idiomas para suscribirse en el sistema, agregue un idioma o pruebe con otro usuario.\n\n";
        else {
            set<string> nomIdiomas;
            list<DTIdioma>::iterator it;
            for(it = idiomasNoSus.begin(); it != idiomasNoSus.end();it++){
                cout << " -" + it->getNombre() << endl;
                nomIdiomas.insert(it->getNombre());
            }
            string op;
            do {
                string idioma;
                cout << "Ingrese el nombre del idioma al cual desea suscribirse: ";
                getline(cin, idioma);
                if(nomIdiomas.count(idioma) != 0){
                    iusuario->suscribirseAIdioma(idioma);
                    nomIdiomas.erase(idioma);
                    cout << "Se ha suscrito correctamente\n";
                    cout << "Si desea suscribirse a otro idioma seleccione 1, en otro caso presione otra tecla: ";
                    getline(cin, op);
                } else {
                    cout << "El idioma que ingreso no existe o ya se encuentra suscripto a el.\n";
                    cout << "Si desea intentar nuevamente ingrese 1, en otro caso presione otra tecla: ";
                    getline(cin, op);
                }
            } while (op == "1");
        }
    }
}