//#############################################################################
// ARCHIVO             : clsMenu.cpp
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
//              clase "clsMenu".
//
///////////////////////////////////////////////////////////////////////////////

#include "clsMenu.h"

//-------------------------------------------------------------------------------------
// METODO    : int clsMenu::init(clsScreen *scr, clsEvent *ev).
// ACCION    : Inicializar.
// PARAMETROS: clsScreen *scr, clsEvent *ev.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsMenu::init(clsScreen *scr, clsEvent *ev)
{
    error.set(0);
    this->screen = scr;
    this->event =ev;
    return error.get();
}

//-------------------------------------------------------------------------------------
// METODO    : int clsMenu::run().
// ACCION    : Inicializa texto y botones. De "boton1.png" a "boton4.png".
//             Y anima color de fondo de pantalla, texto y botones.
//             Detecta si un boton fue presionado por el mouse, para asi saltar a la
//             pagina correspondiente.
// PARAMETROS: Nada.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsMenu::run()
{
    error.set(0);

    //struct color pantalla.
    rgbColor color;
    color.r = 174;
    color.g = 50;
    color.b = 50;

    //struct color texto.
    rgbColor colorT;
    colorT.r = 50;
    colorT.g = 50;
    colorT.b = 174;

    //Inicializa audio
    error.set(audio.init());
    if(error.get()) return error.get();
    sound.loadEffect("AUDIO\\bass1-90-rnb1.wav");
    sound.playEffect(1,10);
    sound.loadEffect("AUDIO\\02_102.wav");
    sound.playEffect(2,20);

    bool salir = false;
    while(!salir)
    {
        screen->clean(color);

        //Inicializa texto.
        error.set(texto.init());
        if(error.get())return error.get();
        texto.loadFont("FONTS\\FreeMono.ttf", 30);
        texto.setFontColor(colorT);
        texto.setStyle(BOLD);
        texto.write("ELIJA UNA DE LAS OPCIONES:", 135, 85, screen->getPtr());

        //Inicializa y refresca imagenes.
        boton1.init("IMAGENES\\boton1.png");
        boton2.init("IMAGENES\\boton2.png");
        boton3.init("IMAGENES\\boton3.png");
        boton4.init("IMAGENES\\boton4.png");
        boton1.setX(67);
        boton1.setY(200);
        boton2.setX(433);
        boton2.setY(200);
        boton3.setX(67);
        boton3.setY(400);
        boton4.setX(433);
        boton4.setY(400);
        boton1.animar(screen);
        boton2.animar(screen);
        boton3.animar(screen);
        boton4.animar(screen);
        screen->refresh();

        //Detecta evento
        if(event->wasEvent())
        {
            if(event->getEventType() == MOUSE_DOWN)
            {
                //Cierra audio
                audio.closeAudio();
                if(boton1.wasClick(event->getCursorX(), event->getCursorY()))
                {
                    error.set(guia.init(screen,event));
                    if(error.get())return error.get();
                    error.set(guia.run());
                    if(error.get())return error.get();

                    //Inicializa audio
                    error.set(audio.init());
                    if(error.get()) return error.get();
                    sound.loadEffect("AUDIO\\bass1-90-rnb1.wav");
                    sound.playEffect(1,10);
                    sound.loadEffect("AUDIO\\02_102.wav");
                    sound.playEffect(2,20);
                }
                if(boton2.wasClick(event->getCursorX(), event->getCursorY()))
                {
                    error.set(juego.init(screen,event));
                    if(error.get())return error.get();
                    error.set(juego.run());
                    if(error.get())return error.get();

                    //Inicializa audio
                    error.set(audio.init());
                    if(error.get()) return error.get();
                    sound.loadEffect("AUDIO\\bass1-90-rnb1.wav");
                    sound.playEffect(1,10);
                    sound.loadEffect("AUDIO\\02_102.wav");
                    sound.playEffect(2,20);
                }
                if(boton3.wasClick(event->getCursorX(), event->getCursorY()))
                {
                    error.set(puntaje.init(screen,event));
                    if(error.get())return error.get();
                    error.set(puntaje.run());
                    if(error.get())return error.get();

                    //Inicializa audio
                    error.set(audio.init());
                    if(error.get()) return error.get();
                    sound.loadEffect("AUDIO\\bass1-90-rnb1.wav");
                    sound.playEffect(1,10);
                    sound.loadEffect("AUDIO\\02_102.wav");
                    sound.playEffect(2,20);
                }
                if(boton4.wasClick(event->getCursorX(), event->getCursorY()))
                {
                    error.set(despedida.init(screen,event));
                    if(error.get())return error.get();
                    error.set(despedida.run());
                    if(error.get())return error.get();
                    salir = true;
                }
            }
        }
    }
    return error.get();
}
