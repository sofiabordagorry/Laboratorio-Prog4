#include <iostream>
#include <set>
#include <list>
#include "../../include/Factory.h"
#include "../../include/DTCurso.h"
#include "../../include/DTEjercicio.h"
#include "../../include/DTEstudiante.h"

using namespace std;

void cu_realizarEjercicio() {
    factory* fab = factory::getInstancia();
    IUsuario* iusuario = fab->getIUsuario();
    ICurso* icurso = fab->getICurso();

    list<DTEstudiante*> estudiantes = iusuario->listarEstudiantes();

    if(estudiantes.size() == 0) 
        cout << "No hay usuarios para inscribirse a un curso, intente mas tarde.\n\n";
    else {
        cout << "---LISTA DE ESTUDIANTES EN EL SISTEMA---\n";
        for(list<DTEstudiante*>::iterator it = estudiantes.begin(); it != estudiantes.end(); it++)
            cout << " -" + (*it)->getNickname() << endl;
        
        cout << "Introduzca su nickname: ";
        string nicknameEst;
        getline(cin, nicknameEst);

        //Itero hasta que ponga bien el nickname
        while(true) {
            list<DTEstudiante*>::iterator it = estudiantes.begin();

            while(it != estudiantes.end() && (*it)->getNickname() != nicknameEst)
                it++;
            
            if(it != estudiantes.end())
                break;
            else {
                cout << "Nickname ingresado incorrecto, intente de nuevo: ";
                getline(cin, nicknameEst);
            }
        }

        for (list<DTEstudiante*>::iterator ite = estudiantes.begin(); ite != estudiantes.end(); ite++) // Los pongo en un set de strings
        {
            delete (*ite);
        }
            
        estudiantes.clear();


        list<DTCurso> cursosNoAprobados = iusuario->listarCursosNoAprobados(nicknameEst);

        if(cursosNoAprobados.size() == 0){
            cout << "En este momento no tiene ningun curso sin aprobar.\nPuede suscribirse a un idioma para saber el proximo curso que se va a habilitar\n\n";
        } else {

            //Listo los cursos no aprobados del estudiante 
            cout << "Lista de los cursos no aprobados: \n";
            for(list<DTCurso>::iterator it = cursosNoAprobados.begin(); it != cursosNoAprobados.end(); it++) 
                cout << *it;
                
            cout << "Introduzca el nombre del curso al cual quiere entrar: ";
            string nombreCurso;
        
            getline(cin, nombreCurso);

            //Itero hasta que ponga bien el nombre del curso
            while(true) {
                list<DTCurso>::iterator it = cursosNoAprobados.begin();

                while(it != cursosNoAprobados.end() && it->getNombre() != nombreCurso)
                    it++;

                if(it == cursosNoAprobados.end()) {
                    cout << "El nombre del curso ingresado es incorrecto, intente de nuevo: ";
                    getline(cin, nombreCurso);
                }
                else 
                    break;
            }

            for(list<DTCurso>::iterator it = cursosNoAprobados.begin(); it != cursosNoAprobados.end(); it++)
                delete (*it).getDataProfesor();
            
            cursosNoAprobados.clear();

            list<DTEjercicio> ejerciciosNoAprobados = iusuario->listarEjerciciosNoAprobados(nombreCurso);

            //Listo los Ejercicios no aprobados 
            cout << "Lista de los ejercicios no aprobados: \n";
            for(list<DTEjercicio>::iterator it = ejerciciosNoAprobados.begin(); it != ejerciciosNoAprobados.end(); it++) 
                cout << *it;
                
            cout << "Introduzca el numero del ejercicio que quiere hacer: ";
            string numeroEj;
            getline(cin, numeroEj);

            //Itero hasta que haya puesto un numero valido
            while(true) {
                list<DTEjercicio>::iterator it = ejerciciosNoAprobados.begin();

                while(it != ejerciciosNoAprobados.end() && to_string(it->getId()) != numeroEj)
                    it++;

                if(it == ejerciciosNoAprobados.end()) {
                    cout << "El numero es incorrecto, intente de nuevo: ";
                    getline(cin, numeroEj);
                }
                else
                    break;
            }

            int IDEj = stoi(numeroEj);

            DTEjercicio ejercicioARealizar = icurso->seleccionarEjercicio(IDEj);
            cout << "Ejercicio a realizar: \n\n";
            cout << "Problema: " << ejercicioARealizar.getFrase() << "\n\n";
            string tipoEjercicio = ejercicioARealizar.getTipo();
            string respuesta;

            //Se sale del while cuando aprueba el ejercicio o cuando no quiere seguir intentando hacerlo 
            bool salir = true;
            while(salir) {
                if(tipoEjercicio == "Traduccion") {
                    cout << "Escriba la traduccion: ";  
                    getline(cin, respuesta);
                    while(respuesta != "NO" && respuesta != "No" && respuesta != "no") {
                        if (icurso->realizarEjercicioTraduccion(IDEj, respuesta)) {
                            cout << "\n ---- Respuesta correcta! ----\n\n";
                            respuesta = "No";
                            salir = false;
                        } else {
                            cout << "Respuesta incorrecta, intente nuevamente o ingrese NO si no quiere intentar mas: ";
                            getline(cin, respuesta);
                            if(respuesta == "NO" || respuesta == "No" || respuesta == "no") {
                                salir = false;
                            }
                        } 
                    }
                } else if(tipoEjercicio == "Completar") {
                    cout << "Escriba las palabras faltantes separandolas con coma y espacio entre cada una (ejemplo: palabras, faltantes): ";
                    getline(cin, respuesta);
                    while(respuesta != "NO" && respuesta != "No" && respuesta != "no") {
                        if (icurso->realizarEjercicioPalabras(IDEj, respuesta)) {
                            cout << "\n ---- Respuesta correcta! ----\n\n";
                            respuesta = "No";
                            salir = false;
                        } else {
                            cout << "Respuesta incorrecta, intente nuevamente o ingrese NO si no quiere intentar mas: ";
                            getline(cin, respuesta);
                            if(respuesta == "NO" || respuesta == "No" || respuesta == "no")
                                respuesta = false;
                        }
                    }       
                }
            }
        }
    }
}

