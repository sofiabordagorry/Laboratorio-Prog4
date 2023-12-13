#include "../../include/Leccion.h"
#include "../../include/ControladorCurso.h"

//Constructores
Leccion::Leccion(){
	this->id = 0;
	this->tema = "";
	this->objetivo = "";
	list<Ejercicio *> ejercicios;
	this->Ejercicios = ejercicios;
}
Leccion::Leccion(int id, string tema , string objetivo){
	this->id = id;
	this->tema = tema;
	this->objetivo = objetivo;
	list<Ejercicio *> ejercicios;
	this->Ejercicios = ejercicios;
}
//Getters
int Leccion::getID(){
	return this->id;
}
string Leccion::getTema(){
	return this->tema;
}
string Leccion::getObjetivo(){
	return this->objetivo;
}
list<Ejercicio*> Leccion::getEjercicios(){
	return this->Ejercicios;
}
//Setters
void Leccion::setID(int id){
	this->id = id;
}
void Leccion::setTema(string tema){
	this->tema = tema;
}
void Leccion::setObjetivo(string objetivo){
	this->objetivo = objetivo;
}
void Leccion::setEjercicio(Ejercicio* ej){
	this->Ejercicios.push_back(ej);
}
//Otras operaciones

DTLeccion Leccion::getDataLeccion(){
	list<DTEjercicio> ej;
	list<Ejercicio*>::iterator it;
	for(it = this->Ejercicios.begin(); it != this->Ejercicios.end();it++){
		ej.push_back((*it)->getDataEjercicio());
	}
	DTLeccion lecc(this->id, this->tema, this->objetivo, ej);
	return lecc;
}

void Leccion::agregarEjercicioTraducir(string frase, string descripcion, string traduccion){
	int cantEjercicios = this->Ejercicios.size();
	Ejercicio *ej = new EjercicioTraduccion(cantEjercicios + 1, frase, descripcion, traduccion);
	this->Ejercicios.push_back(ej);
}

void Leccion::agregarEjercicioCompletar(string frase, string descripcion, string palabras){
	int cantEjercicios = this->Ejercicios.size();
	Ejercicio *ej = new EjercicioCompletar(cantEjercicios + 1, frase, descripcion, palabras);
	this->Ejercicios.push_back(ej);

}
int Leccion::getCantEjLecc(){
	return this->Ejercicios.size();
}

void Leccion::getEjerciciosNoAprobados(list<DTEjercicio>& ejerciciosNoAprobados, Inscripcion* i){
	ControladorCurso* cc = ControladorCurso::getInstancia();
	for(list<Ejercicio*>::iterator it = this->Ejercicios.begin(); it != this->Ejercicios.end(); it++) {
		(*it)->getEjercicioNoAprobado(ejerciciosNoAprobados, i);
	}

	if(ejerciciosNoAprobados.size() != 0)
		cc->guardarLeccion(this);
}

DTEjercicio Leccion::buscarEjercicio(int idEj){
	list<Ejercicio*>::iterator it = this->Ejercicios.begin();
	while(it != this->Ejercicios.end() && (*it)->getId() != idEj)
		it++;

	DTEjercicio ejercicio = (*it)->getDataEjercicio();
	return ejercicio;	

}

bool Leccion::buscarEjercicio(int idEj, string frase, Inscripcion* i){
	list<Ejercicio*>::iterator it = this->Ejercicios.begin();
	while(it != this->Ejercicios.end() && (*it)->getId() != idEj)
		++it;
	
	return (*it)->verificarRespuesta(i, frase);
}

Ejercicio* Leccion::getEjercicio(int idEj){
	list<Ejercicio*>::iterator it = this->Ejercicios.begin();
	while(it != this->Ejercicios.end() && (*it)->getId() != idEj)
		++it;
	
	return (*it);
} 

//destructor
Leccion::~Leccion(){
	list<Ejercicio*>::iterator it;
	for(it = this->Ejercicios.begin(); it != this->Ejercicios.end(); it++){
		delete (*it);
	}
	this->Ejercicios.clear();
	//se borra la leccion
}