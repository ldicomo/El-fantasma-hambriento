//#############################################################################
// ARCHIVO             : clsMenu.h
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
//              clase "clsMenu".
//
///////////////////////////////////////////////////////////////////////////////

#ifndef CLSMENU_H
#define CLSMENU_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsTimer.h>
#include <clsText.h>
#include <clsBoton.h>
#include <clsGuia.h>
#include <clsJuego.h>
#include <clsPuntaje.h>
#include <clsDespedida.h>
#include <clsAudio.h>
#include <clsSoundEffect.h>

class clsMenu
{
    protected:
       clsScreen *screen;
       clsEvent *event;
       clsError error;
       clsTimer timer;
       clsText texto;
       clsBoton boton1;
       clsBoton boton2;
       clsBoton boton3;
       clsBoton boton4;
       clsGuia guia;
       clsJuego juego;
       clsPuntaje puntaje;
       clsDespedida despedida;
       clsAudio audio;
       clsSoundEffect sound;
    public:
       int init(clsScreen*, clsEvent*);
       int run();
       int keyCommand(bool*,Uint16);
};

#endif // CLSMENU_H
