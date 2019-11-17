//#############################################################################
// ARCHIVO             : clsComidas.cpp
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
//              clase "clsComidas".
//
///////////////////////////////////////////////////////////////////////////////

#include "clsComidas.h"

//-------------------------------------------------------------------------------------
// METODO    : int clsComidas::init().
// ACCION    : Inicializa a "comidas.png".
// PARAMETROS: Nada.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsComidas::init()
{
    error.set(0);
    setItems(1);
    setI(0);
    error.set(load("IMAGENES\\comidas.png"));
    if(error.get())return error.get();
    setX(0);
    setY(0);
    return error.get();
}

//-------------------------------------------------------------------------------------
// METODO    : void clsComidas::animar(clsScreen *scr).
// ACCION    : Anima a "comidas.png".
// PARAMETROS: clsScreen *scr.
// DEVUELVE  : Nada.
//-------------------------------------------------------------------------------------
void clsComidas::animar(clsScreen *scr)
{
    setX(getX());
    setY(getY());
    paste(scr->getPtr());
}
