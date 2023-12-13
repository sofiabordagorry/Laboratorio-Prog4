#ifndef FACTORY
#define FACTORY

#include <iostream>
#include "ICurso.h"
#include "IUsuario.h"
using namespace std;

class factory
{//

private:
    factory();
    static factory *instancia;
    ~factory();

public:
    static factory *getInstancia();
    static void releaseInstancia();
    ICurso *getICurso();
    IUsuario *getIUsuario();
};

#endif
