//#############################################################################
// ARCHIVO             : clsPuntaje.h
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
//              clase "clsPuntaje".
//
///////////////////////////////////////////////////////////////////////////////

#ifndef CLSPUNTAJE_H
#define CLSPUNTAJE_H

#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsText.h>
#include <clsAudio.h>
#include <clsSoundEffect.h>
#include <clsArchivo.h>

class clsPuntaje
{
    protected:
       clsScreen *screen;
       clsEvent *event;
       clsError error;
       clsText texto;
       clsAudio audio;
       clsSoundEffect sound;
       clsArchivo archivo;
    public:
       int init(clsScreen*, clsEvent*);
       int run();
       int keyCommand(bool*,Uint16);
};

#endif // CLSPUNTAJE_H
