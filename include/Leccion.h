// Declaracion de la clase Leccion

#ifndef _LECCION_H
#define _LECCION_H

#include <iostream>
#include <forward_list>
#include <list>
#include "DTCurso.h"
#include "DTEjercicio.h"
#include "Ejercicio.h"
#include "EjercicioCompletar.h"
#include "EjercicioTraduccion.h"
#include "DTLeccion.h"

using namespace std;


class Leccion {
	private:
		int id;
		string tema;
		string objetivo;
		list<Ejercicio*> Ejercicios;
	public:
		//Constructores
		Leccion();
		Leccion(int, string, string);
		//Getters
		int getID();
		string getTema();
		string getObjetivo();	
		list<Ejercicio*> getEjercicios();
		//Setters
		void setID(int);  
		void setTema(string);
		void setObjetivo(string);
		void setEjercicio(Ejercicio*);
		//Otras operaciones
		//DTCurso getDataCurso();
		DTLeccion getDataLeccion();
		void agregarEjercicioTraducir(string, string, string);
		void agregarEjercicioCompletar(string, string, string);
		int getCantEjLecc();
		void getEjerciciosNoAprobados(list<DTEjercicio>&, Inscripcion*);
		DTEjercicio buscarEjercicio(int);
		bool buscarEjercicio(int, string, Inscripcion*);
		Ejercicio* getEjercicio(int);
		//destructor
		~Leccion();
};

#endif
