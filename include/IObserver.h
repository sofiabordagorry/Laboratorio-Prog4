#ifndef _IOBSERVER_H
#define _IOBSERVER_H
#include "DTNotificacion.h"

class IObserver{
    private:
    public:
        IObserver(){};
        virtual ~IObserver(){};
        virtual void notificar(DTNotificacion) = 0;
};

#endif
