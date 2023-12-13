#include "../../include/DTCurso.h"

//Constructor por defecto

DTCurso::DTCurso() {
     this->nombre = "";
     this->descripcion = "";
     this->dificultad = Principiante;
     this->habilitado = false;
     DTProfesor* dataProfesor = NULL;
     this->dataProfesor= dataProfesor;
     DTIdioma dataIdioma;
     this->dataIdioma = dataIdioma;
     vector<DTLeccion> dataLeccion;
     this->dataLeccion = dataLeccion;
     list<DTParEstudianteCurso> dataParEstudianteCurso;
     this->dataParEstudianteCurso = dataParEstudianteCurso;
} 

//Constructor por parametros

DTCurso::DTCurso(string nombre, string descripicion, tipoDificultad dificultad, bool habilitado, vector<DTLeccion> dataLeccion, DTProfesor* dataProfesor, list<DTParEstudianteCurso> dataParEstudianteCurso, DTIdioma dataIdioma) {
    this->nombre = nombre;
    this->descripcion = descripicion;
    this->dificultad = dificultad;
    this->habilitado = habilitado;
    this->dataLeccion = dataLeccion;
    this->dataProfesor = dataProfesor;
    this->dataParEstudianteCurso = dataParEstudianteCurso;
    this->dataIdioma = dataIdioma;
} 

//Getters
 
string DTCurso::getNombre() const{
    return this->nombre;
} 
 
string DTCurso::getDescripcion() const{
    return this->descripcion;
} 
 
tipoDificultad DTCurso::getTipoDificultad() const{
    return this->dificultad;
} 
 
bool DTCurso::getHabilitado() const{
    return this->habilitado;
} 

DTIdioma DTCurso::getDataIdioma() const{
    return this->dataIdioma;
} 

vector<DTLeccion> DTCurso::getDataLeccion() const{
    return this->dataLeccion;
} 

DTProfesor* DTCurso::getDataProfesor() const{
    return this->dataProfesor;
} 

list<DTParEstudianteCurso> DTCurso::getDTParEstudianteCurso() const{
    return this->dataParEstudianteCurso;
} 
 
void DTCurso::toStringConsultaCurso() const{
    string dificultadCurso = "";
    switch(this->getTipoDificultad()) {
        case 0:
            dificultadCurso = "Principiante";
            break;
        case 1:
            dificultadCurso = "Medio";
            break;
        case 2:
            dificultadCurso = "Avanzado";
            break;
    }

    string habilitado = "No";
    if(this->getHabilitado())
        habilitado = "Si";

    cout << "\n------------------------------------------" << endl;
    cout << " Nombre del Curso: " + this->getNombre() << endl;
    cout << " Descripcion: " + this->getDescripcion() << endl;
    cout << " Tipo dificultad: " + dificultadCurso << endl;
    cout << " Idioma: " + this->getDataIdioma().getNombre() << endl;
    cout << " Profesor: " + this->getDataProfesor()->getNombre() << endl;
    cout << " Habilitado: " + habilitado << endl;
    for(vector<DTLeccion>::const_iterator it1 = this->dataLeccion.begin(); it1 != this->dataLeccion.end(); it1++) {
        it1->toStringConsultaCurso();
    }
    cout << " Estudiantes inscriptos: " << endl;
    if (this->dataParEstudianteCurso.empty()){
         cout << "no hay estudiantes inscriptos " << endl;
    } else{
        cout << "\n";
        for(list<DTParEstudianteCurso>::const_iterator it = this->dataParEstudianteCurso.begin(); it != this->dataParEstudianteCurso.end(); it++)
        {
            cout << " - " + it->getNickname() <<endl;
            cout << it->getDTInscripcion() <<endl;
        }
    }
    cout << "------------------------------------------" << endl;
} 

void DTCurso::toStringInscribirseCurso() const{
    vector<DTLeccion> leccionesDelCurso = this->getDataLeccion();
    int cantLecciones = leccionesDelCurso.size();
    int cantEjercicios = 0;
    for(auto it = leccionesDelCurso.begin(); it != leccionesDelCurso.end(); ++it) 
        cantEjercicios += it->getDataEjercicio().size();

    string dificultadCurso;
    switch(this->getTipoDificultad()) {
        case 0:
            dificultadCurso = "Principiante";
            break;
        case 1:
            dificultadCurso = "Medio";
            break;
        case 2:
            dificultadCurso = "Avanzado";
            break;
    }

    cout << "------------------------------------------" << endl;
    cout << "Nombre del Curso: " + this->getNombre() << endl;
    cout << "Descripcion: " + this->getDescripcion() << endl;
    cout << "Tipo dificultad " + dificultadCurso << endl;
    cout << "Cantidad de lecciones: " + to_string(cantLecciones) << endl;
    cout << "Cantidad de ejercicios: " + to_string(cantEjercicios) << endl;
    cout << "------------------------------------------" << endl;
} 

//Sobrecarga 

ostream& operator<<(ostream& os,const DTCurso& curso){
    string dificultadCurso;
    switch(curso.getTipoDificultad()) {
        case 0:
            dificultadCurso = "Principiante";
            break;
        case 1:
            dificultadCurso = "Medio";
            break;
        case 2:
            dificultadCurso = "Avanzado";
            break;
    }

    os << "------------------------------------------" << endl;
    os << " Nombre del Curso: " + curso.getNombre() << endl;
    os << " Descripcion: " + curso.getDescripcion() << endl;
    os << " Tipo dificultad: " + dificultadCurso << endl;
    os << "------------------------------------------" << endl;
    
    return os;
} 
