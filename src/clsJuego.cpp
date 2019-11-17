//#############################################################################
// ARCHIVO             : clsJuego.cpp
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
//              clase "clsJuego".
//
///////////////////////////////////////////////////////////////////////////////

#include "clsJuego.h"

//-------------------------------------------------------------------------------------
// METODO    : int clsJuego::init(clsScreen *scr, clsEvent *ev).
// ACCION    : Inicializar.
// PARAMETROS: clsScreen *scr, clsEvent *ev.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsJuego::init(clsScreen *scr, clsEvent *ev)
{
    error.set(0);
    this->screen = scr;
    this->event =ev;

    return error.get();
}

//-------------------------------------------------------------------------------------
// METODO    : int clsJuego::run().
// ACCION    : Inicializa audio y texto.
//             Detecta los eventos de teclado para mover al pacman.
//             Anima audio, color de fondo de la pantalla, barra superior que
//             indica hamburguesas comidas, pacman y hamburguesas.
// PARAMETROS: Nada.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsJuego::run()
{
    //Inicializa audio.
    error.set(audio.init());
    if(error.get())
    return error.get();
    sound.loadEffect("AUDIO\\ANDY_H_FUMERO.wav");
    sound.playEffect(1,1);

    //struct color pantalla.
    rgbColor color;
    color.r = 70;
    color.g = 202;
    color.b = 92;

    screen->clean(color);

    //Inicializa random.
    random.init();

    //Inicializa cartel superior.
    error.set(comidas.init());
    if(error.get())
    return error.get();
    comidas.animar(screen);

    //Inicializa texto.
    error.set(texto.init());
    if(error.get())
    return error.get();
    texto.loadFont("FONTS\\FreeMono.ttf", 14);
    texto.setFontColor(WHITE);
    texto.setStyle(BOLD);

    //Inicializa pacman.
    error.set(pacman.init());
    if(error.get())
    return error.get();
    pacman.setY(screen->getHeight() - pacman.getHeight());
    pacman.setX(screen->getWidth()/2);

    //Inicializa las hamburguesas.
    for(int x =0; x<CANT_HAMBURGUESAS; x++)
    {
        error.set(burger[x].init());
        if(error.get())
        return error.get();
    }

    char s[3];
    int c = 0;
    bool salir = false;
    int cantHamb = 100;
    while(cantHamb > 0)
    {
        screen->clean(color);

        //reubicacion de hamburguesas
        for(int x =0; x<CANT_HAMBURGUESAS; x++)
        {
            if(burger[x].getReubicar())
            {
                cantHamb--;
                if(x == 0) burger[x].setY(comidas.getHeight());
                if(x > 0) burger[x].setY(comidas.getHeight() - random.getNumber(200));
                burger[x].setX(random.getNumber(screen->getWidth() - burger[x].getWidth()));
                burger[x].setReubicar(false);
            }
        }

        //Manejo de eventos de teclado.
        pacman.keyCommand();

        //Validacion de limites.
        if(pacman.getX() <= 0)
            pacman.setX(0);
        if(pacman.getX() >= (screen->getWidth()-pacman.getWidth()))
            pacman.setX((screen->getWidth()-pacman.getWidth()));
        if(pacman.getY() <= comidas.getHeight())
            pacman.setY(comidas.getHeight());
        if(pacman.getY() >= (screen->getHeight()-pacman.getHeight()))
            pacman.setY((screen->getHeight()-pacman.getHeight()));

        //Verifico contacto.
        for(int x =0; x<CANT_HAMBURGUESAS; x++)
        {
            if(burger[x].getContact(&pacman))
            {
                burger[x].setY(screen->getHeight());
                burger[x].setReubicar(true);
                c++;
            }
            if(burger[x].getY()>= screen->getHeight())
            {
                burger[x].setReubicar(true);
            }
        }

        timer.wait(20);

        //animaciones
        pacman.animar(screen);
        for(int x =0; x<CANT_HAMBURGUESAS; x++)
        {
            burger[x].animar(screen);
        }

        //Cartel superior
        sprintf(s, "%d", c);
        comidas.animar(screen);
        texto.write("Hamburguesas comidas: ", 200, 10, screen->getPtr());
        texto.write(s, 400, 10, screen->getPtr());

        screen->refresh();
    }

    //Graba la cantidad de
    //hamburguesas comidas.
    archivo.Grabar(c);

    //Cierra audio.
    audio.closeAudio();

    return error.get();
}
