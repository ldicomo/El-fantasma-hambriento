#ifndef CLSJUEGO_H
#define CLSJUEGO_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <adnConsts.h>
#include <clsError.h>
#include <clsTimer.h>
#include <clsRandom.h>
#include <clsAudio.h>
#include <clsText.h>
#include <clsSoundEffect.h>
#include <clsPuntaje.h>
#include <clsArchivo.h>
#include <clsComidas.h>
//#############################################################################
// ARCHIVO             : clsJuego.h
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
//              clase "clsJuego".
//
///////////////////////////////////////////////////////////////////////////////

#include <clsBurger.h>
#include <clsPacman.h>

const int CANT_HAMBURGUESAS = 3;
const int CANT = 100;

class clsJuego
{
    protected:
       clsScreen *screen;
       clsEvent *event;
       clsError error;
       clsTimer timer;
       clsRandom random;
       clsAudio audio;
       clsText texto;
       clsSoundEffect sound;
       clsPuntaje puntaje;
       clsArchivo archivo;
       clsArchivo arch[CANT];
       clsComidas comidas;
       clsBurger burger[CANT_HAMBURGUESAS];
       clsPacman pacman;
    public:
       int init(clsScreen*, clsEvent*);
       int run();
       int keyCommand(bool*,Uint16);
};

#endif // CLSJUEGO_H
