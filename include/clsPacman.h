//#############################################################################
// ARCHIVO             : clsPacman.h
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
// DESCRIPCION: Este archivo contiene la definicion de los metodos de la
//              clase "clsPacman".
//
///////////////////////////////////////////////////////////////////////////////

#ifndef CLSPACMAN_H
#define CLSPACMAN_H
#include <clsScreen.h>
#include <clsSprite.h>
#include <clsEvent.h>

class clsPacman : public clsSprite
{
    protected:
       void inherit() {};
       clsEvent event;
       clsScreen screen;
       bool arriba = false;
       bool abajo = false;
       bool derecha = false;
       bool izquierda = false;
       int velocidad= 7;
    public:
       int init();
       void animar(clsScreen *);
       void keyCommand();
};

#endif // CLSPACMAN_H
