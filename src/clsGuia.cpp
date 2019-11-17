//#############################################################################
// ARCHIVO             : clsGuia.cpp
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
//              clase "clsGuia".
//
///////////////////////////////////////////////////////////////////////////////

#include "clsGuia.h"

//-------------------------------------------------------------------------------------
// METODO    : int clsGuia::init(clsScreen *scr, clsEvent *ev).
// ACCION    : Inicializar.
// PARAMETROS: clsScreen *scr, clsEvent *ev.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsGuia::init(clsScreen *scr, clsEvent *ev)
{
    error.set(0);
    this->screen = scr;
    this->event =ev;
    return error.get();
}

//-------------------------------------------------------------------------------------
// METODO    : int clsGuia::run().
// ACCION    : Inicializa audio y texto. Anima audio, color de fondo de la pantalla,
//             texto y detecta si hubo un evento.
// PARAMETROS: Nada.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsGuia::run()
{
    error.set(0);

    //struct color pantalla.
    rgbColor color;
    color.r = 174;
    color.g = 50;
    color.b = 50;

    screen->clean(color);

    //Inicializa audio
    error.set(audio.init());
    if(error.get()) return error.get();
    sound.loadEffect("AUDIO\\dog_E_98_loop10.wav");
    sound.playEffect(1,20);

    //Inicializa texto
    error.set(texto.init());
    if(error.get())return error.get();
    texto.loadFont("FONTS\\FreeMono.ttf", 14);
    texto.setFontColor(WHITE);
    texto.setStyle(BOLD);
    texto.write("El juego consiste en tres hamburguesas que caen de algún lugar de la parte superior", 28, 60, screen->getPtr());
    texto.write("de la pantalla, y un pacman fantasma va tras ellas para comerlas.", 28, 90, screen->getPtr());
    texto.write("Al comer una, aparece otra, de algun otro lugar de la parte superior de la pantalla.", 28, 120, screen->getPtr());
    texto.write("Si no es asi, aparecera otra cuando alguna llegue a la parte inferior de la pantalla", 28, 150, screen->getPtr());
    texto.write("y desaparezca.", 28, 180, screen->getPtr());
    texto.write("El juego finaliza después del recorrido de 100 hamburguesas, lo que representa un", 28, 240, screen->getPtr());
    texto.write("tiempo aproximado entre dos y tres minutos.", 28, 270, screen->getPtr());
    texto.write("Para salir de una ventana pulsar Escape.", 28, 330, screen->getPtr());

    screen->refresh();

    bool salir = false;
    while(!salir)
    {
        //Detecta evento
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
// METODO    : int clsGuia::keyCommand(bool *salir, Uint16 key).
// ACCION    : Al presionarse el boton de escape, sale de esa pagina.
// PARAMETROS: bool *salir, Uint16 key.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsGuia::keyCommand(bool *salir, Uint16 key)
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
