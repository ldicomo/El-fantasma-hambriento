//#############################################################################
// ARCHIVO             : clsMotor.h
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
//              clase "clsMotor".
//
///////////////////////////////////////////////////////////////////////////////

#ifndef CLSMOTOR_H
#define CLSMOTOR_H
#include <clsEvent.h>
#include <clsMode.h>
#include <clsScreen.h>
#include <clsError.h>
#include <adnConsts.h>
#include <clsPresentacion.h>
#include <clsMenu.h>

class clsMotor
{
    protected:
       clsEvent event;
       clsMode mode;
       clsScreen screen;
       clsError error;
       clsPresentacion presentacion;
       clsMenu menu;
    public:
       int init();
       int run();
       int keyCommand(bool*,Uint16);
};

#endif // CLSMOTOR_H
