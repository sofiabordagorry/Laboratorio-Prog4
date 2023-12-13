#include <iostream>
#include <thread>

using namespace std;

void cu_AltaDeIdioma();
void cu_consultarIdiomas();
void cu_AltaDeUsuario();
void cu_consultaDeUsuario();
void cu_AltaDeCurso();
void cu_consultarCurso();
void cu_HabilitarCurso();
void cu_AgregarLeccion();
void cu_AgregarEjercicio();
void cu_suscribirseANotificaciones();
void cu_inscribirseACurso();
void cu_cargarDatos();
void cu_consultarNotificaciones();
void cu_EliminarSuscripciones();
void cu_consultarEstadisticas();
void cu_realizarEjercicio();
void cu_eliminarCurso();
void liberarMemoria();

int main(){
    string op_usuario;
    do{
        cout << "----MENU PRINCIPAL----\n";
        cout << "1: Alta de Usuario\n";
        cout << "2: Consulta de Usuario\n";
        cout << "3: Alta de Idioma\n";
        cout << "4: Consultar Idiomas\n";
        cout << "5: Alta de Curso\n";
        cout << "6: Consultar Curso\n";
        cout << "7: Agregar Leccion\n";
        cout << "8: Agregar Ejercicio\n";
        cout << "9: Habilitar Curso\n";
        cout << "10: Eliminar Curso\n";
        cout << "11: Inscribirse a Curso\n";
        cout << "12: Realizar Ejercicio\n";
        cout << "13: Consultar Estadisticas\n";
        cout << "14: Suscribirse a Notificaciones\n";
        cout << "15: Consulta de Notificaciones\n";
        cout << "16: Eliminar suscripciones\n";
        cout << "17: Cargar Datos de Prueba\n";
        cout << "18: Salir\n";


        bool es;
        do{
            es = true;
            op_usuario = "0";
            cout << ":";
            getline(cin, op_usuario);
            
            if ((op_usuario == "\n") || (op_usuario == "") ){
                es = false;
            }else{

                for (char c : op_usuario) {
                    if( !isdigit(c)) {
                        es = false;
                    }
                }
            }
            if(!es){
                cout << "Ingrese un numero de los que se encuentran en la lista" << endl;
            }


        }while(!es);

        system("clear");
        switch (stoi(op_usuario))
        {
        case 1://Alta de Usuario
            cu_AltaDeUsuario();
            break;
        case 2://Consulta de Usuario
            cu_consultaDeUsuario();
            break;
        case 3://Alta de Idioma
            cu_AltaDeIdioma();
            break;
        case 4://Consultar Idiomas
            cu_consultarIdiomas();
            break;
        case 5://Alta de Curso
            cu_AltaDeCurso();
            break;
        case 6://ConsultarCurso
            cu_consultarCurso();
            break;
        case 7://Agregar Leccion
            cu_AgregarLeccion();
            break;
        case 8://Agregar ejercicio
            cu_AgregarEjercicio();
            break;
        case 9://Habilitar Curso
            cu_HabilitarCurso();
            break;
        case 10://Eliminar Curso
            cu_eliminarCurso();
            break;
        case 11://Inscribirse a Curso
            cu_inscribirseACurso();
            break;
        case 12://Realizar Ejercicio
            cu_realizarEjercicio();
            break;
        case 13://Consultar Estadisticas
            cu_consultarEstadisticas();
            break;
        case 14://Suscribirse a Notificaciones
            cu_suscribirseANotificaciones();
            break;
        case 15://Consulta de Notificaciones
            cu_consultarNotificaciones();
            break;
        case 16://Eliminar Suscripciones
            cu_EliminarSuscripciones();
            break;
        case 17://Cargar datos de prueba
            cu_cargarDatos();
            break;
        case 18://Salir
            cout << "Hasta la proxima!\n";
            break;
        default://Opcion incorrecta
            cout << "Ha ingresado una opcion invalida, por favor intente nuevamente\n";
            this_thread::sleep_for(chrono::seconds(3));
            break;
        }
    
    }while(stoi(op_usuario) != 18);

    liberarMemoria();

    return 0;
}