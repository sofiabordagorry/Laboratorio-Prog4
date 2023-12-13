#include "../../include/Factory.h"
#include "../../include/IUsuario.h"
#include "../../include/ICurso.h"
#include <thread>
#include <iomanip>

void EstadisticaEstudiante(){
    system("clear");
    factory * fab = factory::getInstancia();
    IUsuario * iusuario = fab->getIUsuario();
    cout << "*****ESTADISTICA ESTUDIANTE*****\n";
    cout << "\n";

    list<DTEstudiante*> estudiantes = iusuario->listarEstudiantes();
    if(estudiantes.size() > 0){
        cout << "Ingrese el nickname de alguno de los estudiantes que se encuentran en la siguiente lista:\n";
        set<string> nicknames;
        list<DTEstudiante*>::iterator ite;
        for(ite = estudiantes.begin(); ite != estudiantes.end(); ite++){
            cout << (*ite)->getNickname() << "--Nombre: " << (*ite)->getNombre() << endl;
            nicknames.insert((*ite)->getNickname());
            delete (*ite);
        }

        estudiantes.clear();
        
        string nickEst;
        bool nickValido;
        cout << "--------------------------------------\n\n";
        do{
            cout << ":"; 
            getline(cin, nickEst);
            nickValido = (nicknames.count(nickEst) != 0);
                if(!nickValido){
                    cout << "El nickname que ingreso no correspone a ningun estudiante, intente nuevamente\n";
                }    
        }while(!nickValido);

        list<DTEstadisticaCurso> estCursos = iusuario->mostrarPromediosCursosEstudiante(nickEst);
        if(estCursos.size() > 0){
            cout << "-------------ESTADISTICAS-------------\n\n";
            list<DTEstadisticaCurso>::iterator itee;
            for(itee = estCursos.begin(); itee != estCursos.end(); itee++){
                cout << " Nombre del curso: " + (*itee).getNombreCurso() << endl;
                cout << " Promedio: " << fixed << setprecision(2) << (*itee).getPromedio() << endl;
                cout << "\n";
            }
            cout << "--------------------------------------\n\n";
        }else{
            cout << "\nEl estudiante no esta inscripto a ningun curso\n\n";
        }
    }else{
        cout << "En este momento no hay estudiantes para consultar estadisticas\n\n";
    }
}

void EstadisticaProfesor(){
    system("clear");
    factory * fab = factory::getInstancia();
    IUsuario * iusuario = fab->getIUsuario();
    cout << "*****ESTADISTICA PROFESOR*****\n";
    cout << "\n";

    list<DTProfesor*> profesores = iusuario->listarProfesores();
    if(profesores.size() > 0){
        cout << "Ingrese el nickame de alguno de los profesores que se encuentran en la siguiente lista\n";
        set<string> nicknames;
        list<DTProfesor*>::iterator itp;
        for(itp = profesores.begin(); itp != profesores.end(); itp++){
            cout << (*itp)->getNickname() << "--Nombre: " << (*itp)->getNombre() << "\n";
            nicknames.insert((*itp)->getNickname());
            delete (*itp);
        }

        profesores.clear();

        string nickProf;
        bool nickValido;
        do{
            cout << ":";
            getline(cin, nickProf);
            nickValido = (nicknames.count(nickProf) != 0);
            if(!nickValido)
                cout << "Ha ingresado un nickname invalido, por favor intente nuevamente\n";
        }while(!nickValido);    


        list<DTEstadisticaCurso> estCursos = iusuario->mostrarPromediosCursosProfesor(nickProf);
        if(estCursos.size() > 0){
            cout << "-------------ESTADISTICAS-------------\n\n";
            list<DTEstadisticaCurso>::iterator itcp;
            for(itcp = estCursos.begin();itcp != estCursos.end(); itcp++){
                cout << " Nombre del curso: " + (*itcp).getNombreCurso() << endl;
                cout << " Promedio: " << fixed << setprecision(2) << (*itcp).getPromedio() << endl;
                cout << "\n";
            }
            cout << "--------------------------------------\n\n";
        }else{
            cout << "\nEl profesor no tiene cursos creados\n\n";
        }
    }else{
        cout << "En este momento no hay profesores para consultar estadisticas\n\n";
    }
}

void EstadisticaCurso(){
    system("clear");
    factory * fab = factory::getInstancia();
    ICurso * icurso = fab->getICurso();
    cout << "*****ESTADISTICA CURSO*****\n";
    cout << "\n";
    list<DTCurso> cursos = icurso->listarCursosHabilitados();

    if(cursos.size() > 0){
        cout << "Ingrese el nombre de alguno de los cursos que se encuentran en la siguiente lista\n";
        set<string> nombres;
        list<DTCurso>::iterator itc;
        for(itc = cursos.begin(); itc != cursos.end(); itc++){
            cout << (*itc).getNombre() << endl;
            nombres.insert((*itc).getNombre());
            delete (*itc).getDataProfesor();
        }
        string nomCurso;
        bool cursoValido;
        do{
            cout << ":";
            getline(cin, nomCurso);
            cout << nomCurso << endl;
            cursoValido = (nombres.count(nomCurso) != 0);
            if(!cursoValido){
                cout << "Ha ingresado un curso invalido, por favor intente nuevamente\n";
            }
        }while(!cursoValido);
        cout << "-------------ESTADISTICA-------------\n\n";
        DTEstadisticaCurso estCurso = icurso->mostrarPromedioCurso(nomCurso);
        cout << " Nombre del curso: " + estCurso.getNombreCurso() << endl;
        cout << " Promedio: " << fixed << setprecision(2) << estCurso.getPromedio() << endl;
        cout << "\n";
        cout << "-------------------------------------\n\n";
    }else{
        cout << "En este momento no hay cursos para consultar estadisticas\n\n";
    }
}

void cu_consultarEstadisticas(){
    string op;
    do{
        system("clear");
        cout << "Ingrese el tipo de estadisticas que desea consultar\n";
        cout << "1: Estudiante\n";
        cout << "2: Profesor\n";
        cout << "3: Curso\n";
        cout << "4: Menu Principal\n";
        //cout << ":";
        //getline(cin, op);

        bool es;
        do{
        es = true;
        cout << ":";
        getline(cin, op);
        
            for (char c : op) {
                if (!isdigit(c)) {
                    es = false;
                }
            }
            
            if(!es){
                cout << "Ingrese un numero de los que se encuentran en la lista" << endl;
            }


        }while(!es);
        system("clear");
        switch (stoi(op)){
            case 1:
                EstadisticaEstudiante();
                break;
            case 2:
                EstadisticaProfesor();
                break;
            case 3:
                EstadisticaCurso();
                break;
            case 4:
                break;
            default:
                cout << "Eligió una opcion invalida, por favor intente nuevamente\n";
                this_thread::sleep_for(chrono::seconds(3));
                op = "0";
                break;
        }
    }while(stoi(op)==0);
}


