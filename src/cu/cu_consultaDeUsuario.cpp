#include "../../include/Factory.h"
#include <set>

void cu_consultaDeUsuario() {
    factory* fab = factory::getInstancia();
    IUsuario* iusuario = fab->getIUsuario();

    //Listo los nicknames del sistema
    list<DTEstudiante*> estudiantes = iusuario->listarEstudiantes();
    list<DTProfesor*> profesores = iusuario->listarProfesores();

    if(estudiantes.size() == 0 && profesores.size() == 0) {
        cout << "En este momento no hay ningun usuario para consultar, registre algun usuario para poder consultarlo.\n\n";
    } else {
        cout << "Nickname de los usuarios del sistema: \n";
        for(list<DTEstudiante*>::iterator it = estudiantes.begin(); it != estudiantes.end(); ++it){
            cout << " -" + (*it)->getNickname() + "\n";
        }

        for(list<DTProfesor*>::iterator it = profesores.begin(); it != profesores.end(); ++it){
            cout << " -" + (*it)->getNickname() + "\n";
        }

        string nicknameIngresado;
        cout << "Ingrese el nickname del usuario que quiere consultar: ";
        getline(cin, nicknameIngresado);
        
        //Sale cuando puso bien el nickname
        while(true) {
            list<DTEstudiante*>::iterator itEst = estudiantes.begin();
            while(itEst != estudiantes.end() && (*itEst)->getNickname() != nicknameIngresado) 
                itEst++;
            
            if(itEst != estudiantes.end())
                break;
            else {
                list<DTProfesor*>::iterator itProf = profesores.begin();
                while(itProf != profesores.end() && (*itProf)->getNickname() != nicknameIngresado)
                    itProf++;
                
                if(itProf != profesores.end())
                    break;
                else {
                    cout << "Nickname ingresado incorrecto, intente de nuevo: ";
                    getline(cin, nicknameIngresado);
                }
            }  
        }
        DTUsuario* usuarioConsultado = iusuario->consultarUsuario(nicknameIngresado);
        usuarioConsultado->toStringUsuario();

    }

    for(list<DTEstudiante*>::iterator it = estudiantes.begin(); it != estudiantes.end(); ++it){
        delete (*it);
    }
        
    estudiantes.clear();

    for(list<DTProfesor*>::iterator it = profesores.begin(); it != profesores.end(); ++it){
        delete (*it);
    }

    profesores.clear();
}

