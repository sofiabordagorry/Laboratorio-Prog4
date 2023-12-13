#include "../../include/Factory.h"
#include "../../include/ControladorUsuario.h"
#include <algorithm>

void cu_consultarNotificaciones(){
    factory * fabrica =factory::getInstancia();
    IUsuario * iusuario = fabrica->getIUsuario();

    list<DTEstudiante*> estudiantes = iusuario->listarEstudiantes();
    list<DTProfesor*> profesores = iusuario->listarProfesores();
 
    list<DTEstudiante*>::iterator ite;
    list<DTProfesor*>::iterator itp;

    string nickname;
    if(estudiantes.size() == 0 && profesores.size() == 0)
        cout << "En este momento no hay usuarios a los cuales consultar notificaciones, registre un usuario primero.\n\n";
    else {
        
        cout << "---LISTA DE USUARIOS EN EL SISTEMA---\n";
    for(ite = estudiantes.begin(); ite != estudiantes.end(); ite++){
        cout << "  -" << (*ite)->getNickname() << endl;
    }
    for(itp = profesores.begin(); itp != profesores.end(); itp++){
        cout << "  -" << (*itp)->getNickname() << endl;
    }
        
        cout << "Ingrese el nickname del usuario del cual desea consultar las notificaciones: ";    

        do{
            getline(cin, nickname);
            if(nickname == "FIN" || nickname == "fin" || nickname == "Fin"){
                break;
            }
            if(!iusuario->verificarExistenciaDeUsuario(nickname)){
                cout << "El nickname que ingreso es incorrecto, ingrese un nickname o FIN para volver al Menu: ";
            }
        }while((!iusuario->verificarExistenciaDeUsuario(nickname)));

        if(nickname != "FIN" && nickname != "fin" && nickname != "Fin"){
            list<DTNotificacion> notificaciones = iusuario->listarNotificaciones(nickname);
            if (notificaciones.size() != 0){
                cout << "\n";
                cout << "---------------NOTIFICACIONES---------------\n";
                cout << "\n";
                list<DTNotificacion>::iterator itn;
                for(itn = notificaciones.begin(); itn != notificaciones.end(); itn++){
                    cout << (*itn);
                }

                cout << "----------------------------------------------\n";

                iusuario->eliminarNotificaciones(nickname);
            }else{
                cout << "Este usuario no tiene notificaciones\n";
            }
        }

        for (list<DTEstudiante*>::iterator ite = estudiantes.begin(); ite != estudiantes.end(); ite++) // Los pongo en un set de strings
            {
                delete (*ite);
            }
            
        estudiantes.clear();

        for (list<DTProfesor*>::iterator itp = profesores.begin(); itp != profesores.end(); itp++) // Los pongo en un set de strings
            {
                delete (*itp);
            }
            
        profesores.clear();
    }
}