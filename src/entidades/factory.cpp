#include "../../include/Factory.h"
#include "../../include/ControladorUsuario.h"
#include "../../include/ControladorCurso.h"

 factory::factory(){}; 

 factory *factory::instancia = NULL; 

factory *factory::getInstancia()
{
    if (instancia == NULL)
        instancia = new factory();
    return instancia;
}; 

void factory::releaseInstancia()
{
    if (instancia != NULL)
    {
        delete instancia;
        instancia = NULL;
    };
}; 

ICurso *factory::getICurso()
{
    return ControladorCurso::getInstancia();
}; 

IUsuario *factory::getIUsuario()
{
    return ControladorUsuario::getInstancia();
};


factory::~factory(){}; 
