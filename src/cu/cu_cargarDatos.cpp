#include <iostream>
#include "../../include/DTEstudiante.h"
#include "../../include/DTProfesor.h"
#include "../../include/DTUsuario.h"
#include "../../include/DTFecha.h"
#include "../../include/Factory.h"
#include "../../include/IUsuario.h"
#include "../../include/DTNotificacion.h"
#include "../../include/ControladorCurso.h"
#include "../../include/Curso.h"
#include "../../include/Idioma.h"
#include "../../include/Profesor.h"
#include "../../include/Leccion.h"
#include "../../include/Ejercicio.h"
#include "../../include/ControladorCurso.h"
#include "../../include/ControladorUsuario.h"

void cu_cargarDatos() {
    factory *fab = factory::getInstancia(); 
    IUsuario *iusuario = fab->getIUsuario();
    ICurso *icurso = fab->getICurso();
    ControladorCurso* cc = ControladorCurso::getInstancia();
    ControladorUsuario* cu = ControladorUsuario::getInstancia();
    
    bool estIngresado = false;

    DTFecha fecha1(15,07,1995);
    list<DTNotificacion> notif1;
    DTEstudiante U1("jpidiom", "asdfg123", "Juan Perez", "Soy un apasionado del aprendizaje de idiomas.", notif1, "Argentina", fecha1);
    estIngresado = iusuario->registrarEstudiante(U1);
    
    
    DTFecha fecha2(28,02,1998);
    list<DTNotificacion> notif2;
    DTEstudiante U2("marsilva", "qwer456", "Maria Silva", "Como amante de los idiomas disfruto explorando nuevas formas de interactuar.", notif2, "Ecuador", fecha2);
    estIngresado = iusuario->registrarEstudiante(U2);
    
    DTFecha fecha3(10,11,1994);
    list<DTNotificacion> notif3;
    DTEstudiante U3("pero12", "789werty", "Pedro Rodriguez", "Soy un entusiasta del aprendizaje de idiomas.", notif3, "Peru", fecha3);
    estIngresado = iusuario->registrarEstudiante(U3);

    DTFecha fecha4(22,04,1997);
    list<DTNotificacion> notif4;
    DTEstudiante U4("laugu", "c1v2b3m4", "Laura Gutierrez", "Estoy fascinada por la forma en que las palabras pueden unir a las personas", notif4, "Chile", fecha4);
    estIngresado = iusuario->registrarEstudiante(U4);

    DTFecha fecha5(03,9,1996);
    list<DTNotificacion> notif5;
    DTEstudiante U5("carlo22", "tyuipz147", "Carlos Lopez", "Emocionado por adquirir fluidez en diferentes lenguas.", notif5, "Uruguay", fecha5);
    estIngresado = iusuario->registrarEstudiante(U5);

    DTFecha fecha6(12,01,1999);
    list<DTNotificacion> notif6;
    DTEstudiante U6("anator", "1qsxc36", "Ana Torres", "Disfruto de la belleza de las diferentes estructuras y sonidos", notif6, "Argentina", fecha6);
    estIngresado = iusuario->registrarEstudiante(U6);

    DTFecha fecha7(25,06,1993);
    list<DTNotificacion> notif7;
    DTEstudiante U7("luher24", "t7h8y5u6", "Lucia Hernandez", "Emocionada en la riqueza cultural que cada idioma ofrece.", notif7, "Colombia", fecha7);
    estIngresado = iusuario->registrarEstudiante(U7);
    
    DTFecha fecha8(8,12,1997);
    list<DTNotificacion> notif8;
    DTEstudiante U8("dagon", "1w2e3r4t5", "David Gonzalez", "Aprender nuevas lenguas y sumergirme en diferentes culturas.", notif8, "Uruguay", fecha8);
    estIngresado = iusuario->registrarEstudiante(U8);

    DTFecha fecha9(17,03,1995);
    list<DTNotificacion> notif9;
    DTEstudiante U9("carmor", "6yu7i8m9", "Carmen Morales", "El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas.", notif9, "Chile", fecha9);
    estIngresado = iusuario->registrarEstudiante(U9);

    DTFecha fecha10(02,8,1998);
    list<DTNotificacion> notif10;
    DTEstudiante U10("jose24", "qwj789p", "Jose Fernandez", "Disfruto del proceso de descubrir nuevas formas de comunicarme", notif10, "Bolivia", fecha10);
    estIngresado = iusuario->registrarEstudiante(U10);
    
    DTIdioma I1("Ingles");
    DTIdioma I2("Aleman");
    DTIdioma I3("Portugues");
    
    estIngresado = icurso->registrarIdioma(I1);
    estIngresado = icurso->registrarIdioma(I2);
    estIngresado = icurso->registrarIdioma(I3);

    

    list<string> idpf11;
    idpf11.push_back(I1.getNombre());
    idpf11.push_back(I3.getNombre());
    list<DTNotificacion> notif11;
    DTProfesor U11("langMaster", "P4s512", "Marta Grecia", "Soy una profesora apasionada por los idiomas.", notif11, "Instituto de Idiomas Moderno", idpf11);
    estIngresado = iusuario->registrarProfesor(U11);
    

    list<string> idpf12;
    idpf12.push_back(I1.getNombre());
    idpf12.push_back(I2.getNombre());
    idpf12.push_back(I3.getNombre());
    list<DTNotificacion> notif12;
    DTProfesor U12("linguaPro", "Pess23", "Carlos Petro", "Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas", notif12, "Centro Global", idpf12);
    estIngresado = iusuario->registrarProfesor(U12);


    list<string> idpf13;
    idpf13.push_back(I2.getNombre());
    list<DTNotificacion> notif13;
    DTProfesor U13("talkExpert", "Secret1", "Laura Perez", "Soy una profesora entusiasta del aprendizaje de idiomas", notif13, "Instituto de Idiomas Vanguardia", idpf13);
    estIngresado = iusuario->registrarProfesor(U13);


    list<string> idpf14;
    idpf14.push_back(I3.getNombre());
    list<DTNotificacion> notif14;
    DTProfesor U14("lingoSensei", "Secure2", "Franco Lopez", "Apasionada en guiar a mis estudiantes en su viaje por nuevos horizontes idiomaticos", notif14, "Centro de Idiomas", idpf14);
    estIngresado = iusuario->registrarProfesor(U14);


    list<string> idpf15;
    idpf15.push_back(I1.getNombre());
    list<DTNotificacion> notif15;
    DTProfesor U15("wordMaestro", "Passw0", "Ana Morales", "Soy una profesora comprometida en desarrollo de habilidades idiomaticas", notif15, "Instituto de Idiomas Progreso", idpf15);
    estIngresado = iusuario->registrarProfesor(U15);

    if(!estIngresado)
        cout << "Error al cargar datos";

    map<string, Profesor*> profes = cu->getProfesores();
    map<string, Idioma*> idiomas = cc->getIdiomas();

    list<Curso*> previas1{};
    Curso* C1 = new Curso("Ingles para principiantes", "Curso para personas con poco o ningun conocimiento de ingles.\n Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.", 0, true, profes.find(U11.getNickname())->second, idiomas.find(I1.getNombre())->second, previas1);
    icurso->setCurso(C1);
    idiomas.find(I1.getNombre())->second->agregarCurso(C1);
    profes.find(U11.getNickname())->second->setCursoCreado(C1);

    list<Curso*> previas2{};
    Curso* C2 = new Curso("Curso de ingles basico", "Construye una base solida en el idioma.\n Cubre gramatica, vocabulario, com-prension auditiva y expresion oral.", 0, false, profes.find(U11.getNickname())->second, idiomas.find(I1.getNombre())->second, previas2);
    icurso->setCurso(C2);
    idiomas.find(I1.getNombre())->second->agregarCurso(C2);
    profes.find(U11.getNickname())->second->setCursoCreado(C2);
    
    list <Curso*> previas3{};
    previas3.push_back(C1);
    Curso* C3 = new Curso("Ingles intermedio: mejora tu nivel", "Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa.\n Se centra en la fluidez oral, lectura comprensiva y escritura", 1, true, profes.find(U12.getNickname())->second, idiomas.find(I1.getNombre())->second, previas3);
    icurso->setCurso(C3);
    idiomas.find(I1.getNombre())->second->agregarCurso(C3);
    profes.find(U12.getNickname())->second->setCursoCreado(C3);

    list<Curso*> previas4{};
    previas4.push_back(C1);
    previas4.push_back(C3);
    Curso* C4 = new Curso("Curso avanzado de ingles", "Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma.\n Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva", 2, true, profes.find(U12.getNickname())->second, idiomas.find(I1.getNombre())->second, previas4);
    icurso->setCurso(C4);
    idiomas.find(I1.getNombre())->second->agregarCurso(C4);
    profes.find(U12.getNickname())->second->setCursoCreado(C4);

    list<Curso*> previas5{};
    Curso * C5 = new Curso("Portugues intermedio", "Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel.\n Incluye practica de lectura, escritura y comprension auditiva.", 1, true, profes.find(U12.getNickname())->second, idiomas.find(I3.getNombre())->second, previas5);    
    icurso->setCurso(C5);
    idiomas.find(I3.getNombre())->second->agregarCurso(C5);
    profes.find(U12.getNickname())->second->setCursoCreado(C5);

    list<Curso*> previas6{};
    previas6.push_back(C5);
    Curso * C6 = new Curso("Portugues avanzado","Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma.\n Se trabaja en la gramatica avanzada y la expresion oral.",2,false, profes.find(U14.getNickname())->second, idiomas.find(I3.getNombre())->second, previas6);
    icurso->setCurso(C6);
    idiomas.find(I3.getNombre())->second->agregarCurso(C6);
    profes.find(U14.getNickname())->second->setCursoCreado(C6);
    
    Leccion* L1 = new Leccion(1, "Saludos y Presentaciones", "Aprender a saludar y despedirse");
    C1->setLecciones(L1);
    
    Leccion* L2 = new Leccion(2, "Artı́culos y Plurales", "Comprender y utilizar los articulos definidos e indefinidos.\n Aprender a formar los plurales regulares e irregulares de sustantivos");
    C1->setLecciones(L2);

    Leccion* L3 = new Leccion(1, "Actividades Cotidianas", "Comprender y utilizar los articulos definidos e indefinidos.\n Aprender a formar los plurales regulares e irregulares de sustantivos");
    C2->setLecciones(L3);

    Leccion* L4 = new Leccion(2, "Presente Simple",  "Aprender el uso del presente simple");
    C2->setLecciones(L4);

    Leccion* L5 = new Leccion(1, "Conversaciones cotidianas",  "Aprender a hacer preguntas y respuestas en situaciones comunes");
    C3->setLecciones(L5);
    
    Leccion* L6 = new Leccion(1, "Uso de modales avanzados",  "Explorar el uso de los modales complejos");
    C4->setLecciones(L6);

    Leccion* L7 = new Leccion(1, "Lectura y comprension de textos",  "Analizar el contenido, vocabulario y estructuras gramaticales utilizadas");
    C5->setLecciones(L7);
    
    Ejercicio* E1 = new EjercicioTraduccion(1, "Mucho gusto en conocerte", "Presentaciones", "Nice to meet you");
    L1->setEjercicio(E1);

    Ejercicio* E2 = new EjercicioCompletar(2, "Please — me to introduce —", "Presentaciones formales", "allow, myself");
    L1->setEjercicio(E2);
    
    Ejercicio* E3 = new EjercicioTraduccion(1, "I have two brothers and three sisters", "Plurales regulares", "Tengo dos hermanos y tres hermanas");
    L2->setEjercicio(E3);

    Ejercicio* E4 = new EjercicioCompletar(2, "Can I have — water, please?", "Sustantivos contables en plural", "some");
    L2->setEjercicio(E4);

    Ejercicio* E5 = new EjercicioCompletar(1, "Wake —", "Actividades diarias", "up");
    L3->setEjercicio(E5);

    Ejercicio* E6 = new EjercicioCompletar(1, "Q: Do you — the time?, A: Yes, it is half — 4", "Consultas de la hora", "have, past");
    L5->setEjercicio(E6);

    Ejercicio* E7 = new EjercicioTraduccion(1, "You should visit that museum", "Dar consejos o expresar obligacion", "Deberias visitar ese museo");
    L6->setEjercicio(E7);

    Ejercicio* E8 = new EjercicioTraduccion(1, "Fale comigo", "Imperativo", "Habla conmigo");
    L7->setEjercicio(E8);
    
    map<string, Estudiante*> estudiantes = cu->getEstudiantes();

    DTFecha FI1(01, 01, 2022);
    Inscripcion* N1 = new Inscripcion(FI1, true, C1, estudiantes.find(U1.getNickname())->second);
    estudiantes.find(U1.getNickname())->second->setInscripcion(N1);
    C1->setInscripciones(N1);

    DTFecha FI2(12, 06, 2022);
    Inscripcion* N2 = new Inscripcion(FI2, true, C3, estudiantes.find(U1.getNickname())->second);
    estudiantes.find(U1.getNickname())->second->setInscripcion(N2);
    C3->setInscripciones(N2);

    DTFecha FI3(02, 03, 2023);
    Inscripcion* N3 = new Inscripcion(FI3, false, C4, estudiantes.find(U1.getNickname())->second);
    estudiantes.find(U1.getNickname())->second->setInscripcion(N3);
    C4->setInscripciones(N3);

    DTFecha FI4(02, 01, 2022);
    Inscripcion* N4 = new Inscripcion(FI4, false, C1, estudiantes.find(U2.getNickname())->second);
    estudiantes.find(U2.getNickname())->second->setInscripcion(N4);
    C1->setInscripciones(N4);

    DTFecha FI5(02, 01, 2022);
    Inscripcion* N5 = new Inscripcion(FI5, false, C1, estudiantes.find(U3.getNickname())->second);
    estudiantes.find(U3.getNickname())->second->setInscripcion(N5);
    C1->setInscripciones(N5);

    DTFecha FI6(03, 01, 2023);
    Inscripcion* N6 = new Inscripcion(FI6, false, C1, estudiantes.find(U4.getNickname())->second);
    estudiantes.find(U4.getNickname())->second->setInscripcion(N6);
    C1->setInscripciones(N6);

    DTFecha FI7(03, 01, 2023);
    Inscripcion* N7 = new Inscripcion(FI7, false, C5, estudiantes.find(U4.getNickname())->second);
    estudiantes.find(U4.getNickname())->second->setInscripcion(N7);
    C5->setInscripciones(N7);
    
    DTFecha FI8(05, 01, 2023);
    Inscripcion* N8 = new Inscripcion(FI8, false, C5, estudiantes.find(U5.getNickname())->second);
    estudiantes.find(U5.getNickname())->second->setInscripcion(N8);
    C5->setInscripciones(N8);

    N1->setEjercicioAprobado(E1);
    E1->setInscripcion(N1);

    N1->setEjercicioAprobado(E2);
    E2->setInscripcion(N1);

    N1->setEjercicioAprobado(E3);
    E3->setInscripcion(N1);

    N1->setEjercicioAprobado(E4);
    E4->setInscripcion(N1);

    N2->setEjercicioAprobado(E6);
    E6->setInscripcion(N2);

    N4->setEjercicioAprobado(E1);
    E1->setInscripcion(N4);

    N4->setEjercicioAprobado(E2);
    E2->setInscripcion(N4);

    N5->setEjercicioAprobado(E1);
    E1->setInscripcion(N5);

    N5->setEjercicioAprobado(E2);
    E2->setInscripcion(N5);
    
    N5->setEjercicioAprobado(E4);
    E4->setInscripcion(N5);



    cout << "\n ---- Los datos se han cargado correctamente ----\n\n";
}