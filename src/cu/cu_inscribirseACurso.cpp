#include "../../include/Factory.h"
#include <iostream>

using namespace std;

void cu_inscribirseACurso() {
    factory* fab = factory::getInstancia();
    ICurso* icurso = fab->getICurso();
    IUsuario* iusuario = fab->getIUsuario();

    list<DTEstudiante*> estudiantes = iusuario->listarEstudiantes();

    if(estudiantes.size() == 0) 
        cout << "No hay usuarios para inscribirse a un curso, intente mas tarde.\n\n";
    else {
        cout << "---LISTA DE ESTUDIANTES EN EL SISTEMA---\n";
        for(list<DTEstudiante*>::iterator it = estudiantes.begin(); it != estudiantes.end(); it++)
            cout << " -" + (*it)->getNickname() << endl;
            
        string nicknameEst;
        cout << "Introduzca su nickname: ";
        getline(cin, nicknameEst);

        //Itero hasta que ponga bien el nickname
        while(true) {
            list<DTEstudiante*>::iterator itEst = estudiantes.begin();
            while(itEst != estudiantes.end() && (*itEst)->getNickname() != nicknameEst) 
                itEst++;
            if(itEst != estudiantes.end()) 
                break;
            else {
                cout << "El nickname ingresado no existe, intente de nuevo: ";
                getline(cin, nicknameEst);
            }
        }

        for (list<DTEstudiante*>::iterator ite = estudiantes.begin(); ite != estudiantes.end(); ite++) // Los pongo en un set de strings
        {
            delete (*ite);
        }

        estudiantes.clear();
        
        list<DTCurso> cursosDisponibles = icurso->listarCursosHabilitadosEstudiante(nicknameEst);
        if(cursosDisponibles.size() == 0) {
            cout << "No hay cursos disponibles para inscribirse.\nIntente mas tarde o suscribase a un idioma para saber cuando sale un curso nuevo\n\n";
        } else {
            cout << "Estos son los cursos habilitados para inscribirse: \n";
            
            //Listo los cursos habilitados para inscribirse
            for(list<DTCurso>::iterator it = cursosDisponibles.begin(); it != cursosDisponibles.end(); ++it)
                it->toStringInscribirseCurso();

            cout << "Introduza el nombre del curso al cual se quiere inscribir: ";
            string nomCurso;
            getline(cin, nomCurso);

            //Sale cuando pone bien el nombre del curso
            while(true) {
                list<DTCurso>::iterator it = cursosDisponibles.begin();

                while(it != cursosDisponibles.end() && it->getNombre() != nomCurso) 
                    ++it;

                if(it == cursosDisponibles.end()) {
                    cout << "Nombre del curso incorrecto, intente de nuevo: ";
                    getline(cin, nomCurso);
                } else 
                    break;
            }

            for(list<DTCurso>::iterator it = cursosDisponibles.begin(); it != cursosDisponibles.end(); ++it)
                delete (*it).getDataProfesor();
            
            cursosDisponibles.clear();

            icurso->inscribirseACurso(nicknameEst, nomCurso);
            cout << "\n ---- Inscripcion realizada con exito! ----\n\n";
        }
    }
}