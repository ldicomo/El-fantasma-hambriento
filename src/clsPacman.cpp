//#############################################################################
// ARCHIVO             : clsPacman.cpp
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
//              clase "clsPacman".
//
///////////////////////////////////////////////////////////////////////////////

#include "clsPacman.h"
#include <clsScreen.h>

//-------------------------------------------------------------------------------------
// METODO    : int clsPacman::init().
// ACCION    : Inicializa a "pacman.png".
// PARAMETROS: Nada.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsPacman::init()
{
    error.set(0);
    setItems(1);
    setI(0);
    error.set(load("IMAGENES\\pacman.png"));
    if(error.get())
        return error.get();
    setX(0);
    setY(0);
    return error.get();
}

//-------------------------------------------------------------------------------------
// METODO    : void clsPacman::animar(clsScreen *scr).
// ACCION    : Anima a "pacman.png".
// PARAMETROS: clsScreen *scr.
// DEVUELVE  : Nada.
//-------------------------------------------------------------------------------------
void clsPacman::animar(clsScreen *scr)
{
    if(arriba)
    {
        setY(getY()-velocidad);
    }
    if(abajo)
    {
        setY(getY()+velocidad);
    }

    if(izquierda)
    {
        setX(getX()-velocidad);
    }
    if(derecha)
    {
        setX(getX()+velocidad);
    }
    paste(scr->getPtr());
}

//-------------------------------------------------------------------------------------
// METODO    : void clsPacman::keyCommand().
// ACCION    : Detecta si las teclas KEY_UP, KEY_LEFT, KEY_RIGHT o KEY_DOWN, fueron
//             presionadas o liberadas.
// PARAMETROS: Nada.
// DEVUELVE  : Nada.
//-------------------------------------------------------------------------------------
void clsPacman::keyCommand()
{
    if(event.wasEvent())
    {
        if(event.getEventType()== KEY_PRESSED)
        {
            switch(event.getKey())
            {
                case KEY_UP:
                {
                    arriba=true;
                }
                break;
                case KEY_LEFT:
                {
                    izquierda=true;
                }
                break;
                case KEY_RIGHT:
                {
                    derecha=true;
                }
                break;
                case KEY_DOWN:
                {
                    abajo=true;
                }
                break;
            }
        }
        if(event.getEventType()== KEY_FREE)
        {
            switch(event.getKey())
            {
                case KEY_UP:
                {
                    arriba=false;
                }
                break;
                case KEY_LEFT:
                {
                    izquierda=false;
                }
                break;
                case KEY_RIGHT:
                {
                    derecha=false;
                }
                break;
                case KEY_DOWN:
                {
                    abajo=false;
                }
                break;
            }
        }
    }
}
