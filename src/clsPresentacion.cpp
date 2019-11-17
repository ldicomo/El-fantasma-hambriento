//#############################################################################
// ARCHIVO             : clsPresentacion.cpp
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
//              clase "clsPresentacion".
//
///////////////////////////////////////////////////////////////////////////////

#include "clsPresentacion.h"

//-------------------------------------------------------------------------------------
// METODO    : int clsPresentacion::init(clsScreen*scr, clsEvent* ev).
// ACCION    : Inicializa de "pacman0.png" a "pacman5.png".
// PARAMETROS: clsScreen*scr, clsEvent* ev.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsPresentacion::init(clsScreen*scr, clsEvent* ev)
{
    error.set(0);
    this->screen = scr;
    this->event =ev;

    setItems(6);

    setI(0);
    error.set(load("IMAGENES\\pacman0.png"));
    if(error.get()) return error.get();

    setI(1);
    error.set(load("IMAGENES\\pacman1.png"));
    if(error.get()) return error.get();

    setI(2);
    error.set(load("IMAGENES\\pacman2.png"));
    if(error.get()) return error.get();

    setI(3);
    error.set(load("IMAGENES\\pacman3.png"));
    if(error.get()) return error.get();

    setI(4);
    error.set(load("IMAGENES\\pacman4.png"));
    if(error.get()) return error.get();

    setI(5);
    error.set(load("IMAGENES\\pacman5.png"));
    if(error.get()) return error.get();

    setX(299);
    setY(290);

    return error.get();
}

//-------------------------------------------------------------------------------------
// METODO    : int clsPresentacion::run().
// ACCION    : Inicializa audio y texto. Y anima color de fondo de pantalla, audio,
//             texto y las imagenes del pacman.
// PARAMETROS: Nada.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsPresentacion::run()
{
    error.set(0);

    //Inicializa audio
    error.set(audio.init());
    if(error.get()) return error.get();
    sound.loadEffect("AUDIO\\Hiphop.wav");
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

    int contar = 0;
    bool salir = false;
    while(!salir)
    {
        //Inicializa texto.
        error.set(texto.init());
        if(error.get())return error.get();
        texto.loadFont("FONTS\\FreeMono.ttf", 26);
        texto.setFontColor(colorT);
        texto.setStyle(BOLD);
        texto.write("EL PACMAN FANTASMA", 237, 130, screen->getPtr());
        texto.write("QUE COME HAMBURGUESAS", 208, 192, screen->getPtr());

        /*
          Muestra las 5 imagenes,
          dando un timer de 0.3 seg.
          entre cada una; repitiendo
          este proceso 3 veces.
        */
        if(contar == 3) salir = true;
        for(int i = 0; i < 6; i++)
        {
            setI(i);
            paste(screen->getPtr());
            screen->refresh();
            timer.wait(300);
        }
        contar++;
    }

    //Cierra audio
    audio.closeAudio();

    return error.get();
}
