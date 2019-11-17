//#############################################################################
// ARCHIVO             : clsBoton.cpp
// AUTOR               : Luis Antonio Dicomo.
// VERSION             : 1.0
// FECHA DE CREACION   : 25/11/2018.
// ULTIMA ACTUALIZACION: 15/12/2018.          .
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Este archivo contiene la implementacion de los metodos de la
//              clase "clsBoton".
//
///////////////////////////////////////////////////////////////////////////////

#include "clsBoton.h"

//-------------------------------------------------------------------------------------
// METODO    : int clsBoton::init(char* ruta).
// ACCION    : Inicializa al boton.
// PARAMETROS: char* ruta.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsBoton::init(char* ruta)
{
    setItems(1);
    setI(0);
    error.set(load(ruta));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    return error.get();
}

//-------------------------------------------------------------------------------------
// METODO    : void clsBoton::animar(clsScreen *scr).
// ACCION    : Anima al boton.
// PARAMETROS: clsScreen *scr.
// DEVUELVE  : Nada.
//-------------------------------------------------------------------------------------
void clsBoton::animar(clsScreen *scr)
{
    setX(getX());
    setY(getY());
    paste(scr->getPtr());
}

//-------------------------------------------------------------------------------------
// METODO    : bool clsBoton::wasClick(int x, int y).
// ACCION    : Detecta si hubo un evento en el boton.
// PARAMETROS: int x, int y.
// DEVUELVE  : result.
//-------------------------------------------------------------------------------------
bool clsBoton::wasClick(int x, int y)
{
    bool result = false;
    if(x >= getX() && x <= getX() + getWidth() &&
       y >= getY() && y <= getY() + getHeight())
    {
        result = true;
    }
    return result;
}
