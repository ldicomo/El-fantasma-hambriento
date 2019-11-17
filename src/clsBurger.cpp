//#############################################################################
// ARCHIVO             : clsBurger.cpp
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
//              clase "clsBurger".
//
///////////////////////////////////////////////////////////////////////////////

#include "clsBurger.h"

//-------------------------------------------------------------------------------------
// METODO    : int clsBurger::init().
// ACCION    : Inicializa a "burger.png".
// PARAMETROS: Nada.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsBurger::init()
{
    error.set(0);
    setItems(1);
    setI(0);
    error.set(load("IMAGENES\\burger.png"));
    if(error.get())
        return error.get();
    setX(0);
    setY(30);
    return error.get();
}

//-------------------------------------------------------------------------------------
// METODO    : void clsBurger::animar(clsScreen *scr).
// ACCION    : Anima a "burger.png".
// PARAMETROS: clsScreen *scr.
// DEVUELVE  : Nada.
//-------------------------------------------------------------------------------------
void clsBurger::animar(clsScreen *scr)
{
    setY(getY()+5);
    paste(scr->getPtr());
}

//-------------------------------------------------------------------------------------
// METODO    : void clsBurger::setReubicar(bool r).
// ACCION    : Setea para reubicar a "burger.png".
// PARAMETROS: bool r.
// DEVUELVE  : Nada.
//-------------------------------------------------------------------------------------
void clsBurger:: setReubicar(bool r)
{
    reubicar =r;
}

//-------------------------------------------------------------------------------------
// METODO    : void clsBurger::getReubicar().
// ACCION    : Obtiene reubicar de "burger.png".
// PARAMETROS: Nada.
// DEVUELVE  : Nada.
//-------------------------------------------------------------------------------------
bool clsBurger::getReubicar()
{
    return reubicar;
}
