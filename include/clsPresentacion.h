//#############################################################################
// ARCHIVO             : clsPresentacion.h
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
//              clase "clsPresentacion".
//
///////////////////////////////////////////////////////////////////////////////

#ifndef CLSPRESENTACION_H
#define CLSPRESENTACION_H
#include <clsSprite.h>
#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsTimer.h>
#include <clsText.h>
#include <clsAudio.h>
#include <clsSoundEffect.h>

class clsPresentacion : public clsSprite
{
    protected:
       void inherit(){};
       clsScreen *screen;
       clsEvent *event;
       clsError error;
       clsTimer timer;
       clsText texto;
       clsAudio audio;
       clsSoundEffect sound;
    public:
       int init(clsScreen*, clsEvent*);
       int run();
};

#endif // CLSPRESENTACION_H
