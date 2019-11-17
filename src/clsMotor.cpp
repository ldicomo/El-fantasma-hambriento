//#############################################################################
// ARCHIVO             : clsMotor.cpp
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
//              clase "clsMotor".
//
///////////////////////////////////////////////////////////////////////////////

#include "clsMotor.h"

//-------------------------------------------------------------------------------------
// METODO    : int clsMotor::init().
// ACCION    : Inicializa a la pantalla, a presentacion y a menu.
// PARAMETROS: Nada.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsMotor::init()
{
    error.set(0);
    error.set(mode.init(DEFAULT));
    if(error.get())return error.get();
    error.set(screen.init(mode.getScrWidth(),
                          mode.getScrHeight(),
                          mode.getScrDepth(),
                          ENABLED,
                          RESIZABLE));
    if(error.get())return error.get();

    error.set(presentacion.init(&screen,&event));
    if(error.get())return error.get();

    error.set(menu.init(&screen,&event));
    if(error.get())return error.get();

    return error.get();
}

//-------------------------------------------------------------------------------------
// METODO    : int clsMotor::run().
// ACCION    : Ejecuta presentacion y menu.
// PARAMETROS: Nada.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsMotor::run()
{
    error.set(0);

    error.set(presentacion.run());
    if(error.get())return error.get();

    error.set(menu.run());
    if(error.get())return error.get();

    return error.get();
}
