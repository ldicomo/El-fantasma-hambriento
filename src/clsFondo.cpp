#include "clsFondo.h"

int clsFondo::init()
{
    error.set(0);
    setItems(7);

    setI(0);
    error.set(load("IMAGENES\\presentacion0.png"));
    if(error.get()) return error.get();

    setI(1);
    error.set(load("IMAGENES\\presentacion1.png"));
    if(error.get()) return error.get();

    setI(2);
    error.set(load("IMAGENES\\presentacion2.png"));
    if(error.get()) return error.get();

    setI(3);
    error.set(load("IMAGENES\\presentacion3.png"));
    if(error.get()) return error.get();

    setI(4);
    error.set(load("IMAGENES\\presentacion4.png"));
    if(error.get()) return error.get();

    setI(5);
    error.set(load("IMAGENES\\presentacion5.png"));
    if(error.get()) return error.get();


    setI(6);
    error.set(load("IMAGENES\\despedida.png"));
    if(error.get()) return error.get();

    setX(0);
    setY(0);

    return error.get();
}

void clsFondo::setPresentacion(int i)
{
    setI(i);
}

void clsFondo::setDespedida()
{
    setI(6);
}
