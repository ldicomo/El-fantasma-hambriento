//#############################################################################
// ARCHIVO             : clsBurger.h
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
//              clase "clsBurger".
//
///////////////////////////////////////////////////////////////////////////////

#ifndef CLSBURGER_H
#define CLSBURGER_H
#include <clsScreen.h>
#include <clsSprite.h>

class clsBurger : public clsSprite
{
    protected:
       void inherit() {};
       bool reubicar = true;
    public:
       int init();
       void animar(clsScreen *);
       void setReubicar(bool);
       bool getReubicar();
};

#endif // CLSBURGER_H
