#include <iostream>
#include "../../include/DTEstudiante.h"
#include "../../include/DTProfesor.h"
#include "../../include/DTUsuario.h"
#include "../../include/DTFecha.h"
#include "../../include/Factory.h"
#include "../../include/IUsuario.h"
#include "../../include/DTNotificacion.h"
#include <algorithm>

using namespace std;

// Devuelve true si se logró registrar el estudiante, o false si no.
void cu_AltaDeUsuario() {
    factory *fab = factory::getInstancia(); 
    IUsuario *iusuario = fab->getIUsuario();
    ICurso *icurso = fab->getICurso();

    string nickname;
    cout << "Escriba el nickname del usuario a registrar: ";
    getline(cin, nickname);

    string nombre;
    cout << "Escriba su nombre: ";
    getline(cin, nombre);

    string descripcion;
    cout << "Escriba una descripción para su perfil: ";
    getline(cin, descripcion);

    string password;
    cout << "Escriba una contraseña de al menos 6 caracteres: ";
    getline(cin, password);

    while (password.length() < 6) {
        cout << "La contraseña ingresada tiene un largo menor a 6 caracteres. Ingrese una contraseña válida: ";
        getline(cin, password);
    }

    string tipoUsuario = "";
    cout << "El usuario a registrar es un:\n1. Estudiante\n2. Profesor\n(Ingrese 1 o 2): ";
    cin >> tipoUsuario;
    while (tipoUsuario != "1" && tipoUsuario != "2") {
        cout << "El número ingresado no es válido. Ingreselo de nuevo: ";
        cin >> tipoUsuario;
    }

    if (tipoUsuario == "1") {
        string pais;
        cout << "Escriba el nombre del país donde reside: ";
        cin.ignore();
        getline(cin, pais);

        string dia = "0";
        bool es;
        while(stoi(dia) > 31 || stoi(dia) < 1){
        cout << "Escriba su día de nacimiento (1-31): ";
            do{
            es = true;
            getline(cin, dia);
                for (char c : dia) {
                    if (!isdigit(c)) {
                        es = false;
                    }
                }
                
                if(!es){
                    cout << "Ingrese un numero de dia valido: ";
                }

            }while(!es);
        }
        // }while (stoi(dia) > 31 || stoi(dia) < 1);

        string mes = "0";
        while(stoi(mes) > 12 || stoi(mes) < 1){
        cout << "Escriba su mes de nacimiento (1-12): ";
            do{
            es = true;
            getline(cin, mes);
                for (char c : mes) {
                    if (!isdigit(c)) {
                        es = false;
                    }
                }
                
                if(!es){
                    cout << "Ingrese un numero de mes valido: ";
                }

            }while(!es);
        }
        

        string anio = "0";
        while(stoi(anio) < 1900 || stoi(anio) > 2023){
        cout << "Escriba su año de nacimiento (1900-2023): ";
            do{
            es = true;
            getline(cin, anio);
                for (char c : anio) {
                    if (!isdigit(c)) {
                        es = false;
                    }
                }
                
                if(!es){
                    cout << "Ingrese un numero de año valido: ";
                }

            }while(!es);
        }

        int mesNum, diaNum, anioNum;
        mesNum = stoi(mes);
        diaNum = stoi(dia);
        anioNum = stoi(anio);

        DTFecha fecha = DTFecha(diaNum, mesNum, anioNum);

        list<DTNotificacion> notif;
        DTEstudiante est(nickname, password, nombre, descripcion, notif, pais, fecha);
        bool reg = iusuario->registrarEstudiante(est);
        if (reg) {
            cout << "\n ---- Usuario registrado con éxito ----\n\n";
        } else {
            cout << "No fue posible registrar el usuario. Nickname ya en uso.\n";
        }
    } else if (tipoUsuario == "2") {
        
        list<DTIdioma> idiomas = icurso->listarIdiomas();
        if (idiomas.size()==0) {
            cout << "En este momento no hay idioma disponibles para que se especialice el profesor, ingrese un idioma primero.\n\n";
        } else {

            string nombreInst;
            cout << "Inserte el nombre del instituto en el que trabaja: ";
            cin.ignore();
            getline(cin, nombreInst);
            
            set<string> idiomasStr;
            cout << "Idiomas actualmente registrados en el sistema:\n";
            for (list<DTIdioma>::iterator it = idiomas.begin(); it != idiomas.end(); it++) {
                cout << " -" << it->getNombre() << endl;
                idiomasStr.insert(it->getNombre());
            }
        
            string idioma;
            list<string> idpf;
            cout << "Ingrese el nombre del idioma en el que se especializa, o FIN para terminar de ingresar. (Se debe ingresar al menos un idioma): ";
            getline(cin, idioma);
            while (idioma != "FIN" && idioma != "fin" && idioma != "Fin") {
                if ((idioma == "FIN" || idioma == "fin" || idioma == "Fin") && idpf.size() == 0) {
                    cout << "Debe ingresar al menos un idioma. Ingrese el nombre de nuevo: ";
                    getline(cin, idioma);
                } else if ((idioma != "FIN" && idioma != "fin" && idioma != "Fin") && idiomasStr.count(idioma) == 0) {
                    cout << "El idioma ingresado no es válido, ingrese el nombre de nuevo o escriba FIN para salir: ";
                    getline(cin, idioma);
                } else if (idioma != "FIN" && idioma != "fin" && idioma != "Fin") {
                    idpf.push_back(idioma);
                    cout << "Idioma agregado. Ingrese más idiomas, o FIN para terminar: ";
                    getline(cin, idioma);
                }
            }

            list<DTNotificacion> notif;
            DTProfesor prof(nickname, password, nombre, descripcion, notif, nombreInst, idpf);
            bool reg = iusuario->registrarProfesor(prof);
            if (reg) {
                cout << "\n ---- Usuario registrado con éxito ----\n\n";
            } else {
                cout << "No fue posible registrar el usuario. Nickname ya en uso.";
            }
        }
    }
};