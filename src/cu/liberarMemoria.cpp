# include <iostream>
using namespace std;

#include "../../include/Factory.h"
#include "../../include/ControladorCurso.h"
#include "../../include/ControladorUsuario.h"

void liberarMemoria(){
    factory * fab = factory::getInstancia();
    IUsuario * iusuario = fab->getIUsuario();
    ICurso * icurso = fab->getICurso();
    icurso->liberarCurso(); 
    iusuario->liberarUsuario();


    ControladorUsuario::releaseInstancia();
    ControladorCurso::releaseInstancia();
    factory::releaseInstancia();
}
