//#############################################################################
// ARCHIVO             : clsDespedida.cpp
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
//              clase "clsDespedida".
//
///////////////////////////////////////////////////////////////////////////////

#include "clsDespedida.h"

//-------------------------------------------------------------------------------------
// METODO    : int clsDespedida::init(clsScreen *scr, clsEvent *ev).
// ACCION    : Inicializa a "pacman1.png".
// PARAMETROS: clsScreen *scr, clsEvent *ev.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsDespedida::init(clsScreen *scr, clsEvent *ev)
{
    error.set(0);
    this->screen = scr;
    this->event =ev;

    setItems(1);
    setI(0);
    error.set(load("IMAGENES\\pacman1.png"));
    if(error.get()) return error.get();
    setX(70);
    setY(70);

    return error.get();
}

//-------------------------------------------------------------------------------------
// METODO    : int clsDespedida::run().
// ACCION    : Inicializa audio y texto. Y anima color de fondo de pantalla, audio
//             y texto. Ademas detecta si hubo un envento.
// PARAMETROS: Nada.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsDespedida::run()
{
    error.set(0);

    //Inicializa audio
    error.set(audio.init());
    if(error.get()) return error.get();
    sound.loadEffect("AUDIO\\dog_E_98_loop10.wav");
    sound.playEffect(1,10);

    //struct color pantalla.
    rgbColor color;
    color.r = 50;
    color.g = 50;
    color.b = 174;

    //struct color texto.
    rgbColor colorT;
    colorT.r = 174;
    colorT.g = 50;
    colorT.b = 50;

    screen->clean(color);

    //Inicializa texto
    error.set(texto.init());
    if(error.get())return error.get();
    texto.loadFont("FONTS\\FreeMono.ttf", 28);
    texto.setFontColor(colorT);
    texto.setStyle(BOLD);
    texto.write("ESPERO QUE HAYA", 320, 150, screen->getPtr());
    texto.write("DISFRUTADO EL JUEGO", 320, 220, screen->getPtr());
    texto.loadFont("FONTS\\FreeMono.ttf", 33);
    texto.write("HASTA PRONTO!!!", 320, 390, screen->getPtr());

    //Pega a "pacman1.png" y refresca pantalla.
    setI(0);
    paste(screen->getPtr());
    screen->refresh();

    //Detecta evento
    bool salir = false;
    while(!salir)
    {
        if(event->wasEvent())
        {
            if(event->getEventType() ==KEY_PRESSED)
            {
                 keyCommand(&salir,event->getKey());
            }
        }
    }

    //Cierra audio
    audio.closeAudio();

    return error.get();
}

//-------------------------------------------------------------------------------------
// METODO    : int clsDespedida::keyCommand(bool *salir, Uint16 key).
// ACCION    : Al presionarse el boton de escape, se sale de la aplicacion.
// PARAMETROS: bool *salir, Uint16 key.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsDespedida::keyCommand(bool *salir, Uint16 key)
{
    error.set(0);
    switch(key)
    {
    case KEY_ESCAPE:
    {
        *salir = true;
    }
    break;
    }
    return error.get();
}
