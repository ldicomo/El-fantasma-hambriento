//#############################################################################
// ARCHIVO             : clsPuntaje.cpp
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
//              clase "clsPuntaje".
//
///////////////////////////////////////////////////////////////////////////////

#include "clsPuntaje.h"

//-------------------------------------------------------------------------------------
// METODO    : int clsPuntaje::init(clsScreen *scr, clsEvent *ev).
// ACCION    : Inicializar.
// PARAMETROS: clsScreen *scr, clsEvent *ev.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsPuntaje::init(clsScreen *scr, clsEvent *ev)
{
    error.set(0);
    this->screen = scr;
    this->event =ev;
    return error.get();
}

//-------------------------------------------------------------------------------------
// METODO    : int clsPuntaje::run().
// ACCION    : Inicializa audio y texto.
//             Y anima color de fondo de pantalla, audio y texto.
//             Informa sobre el ultimo puntaje y solicita el nombre al jugador.
//             Detecta el evento de escritura y escribe solo letras, permitiendo
//             borrar en caso de error, con BACKSPACE.
//             Luego informa los nombres y puntajes de los 5 que lograron mas puntos.
// PARAMETROS: Nada.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsPuntaje::run()
{
    error.set(0);

    //Inicializa audio.
    error.set(audio.init());
    if(error.get()) return error.get();
    sound.loadEffect("AUDIO\\Hiphop.wav");
    sound.playEffect(1,10);

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

    screen->clean(color);

    //Inicializa texto.
    error.set(texto.init());
    if(error.get())return error.get();
    texto.loadFont("FONTS\\FreeMono.ttf", 30);
    texto.setFontColor(colorT);
    texto.setStyle(BOLD);
    texto.write("INGRESE SU NOMBRE:", 40, 60, screen->getPtr());
    screen->refresh();

    // Proceso de escritura
    bool maximo = false;
    int l = 0;
    char alias[10] = " ";
    while(!maximo)
    {
        /*
        Detecta evento.
        Si fue presionada una letra,
        o el backapace para borrar, o
        el ENTER para continuar.
        */
        if(event->wasEvent())
        {
            if(event->getEventType() == KEY_PRESSED)
            {
                Uint16 key = event->getKey();
                if((key >= KEY_a && key <= KEY_z) ||
                   (key >= KEY_A && key <= KEY_Z))
                {
                    l = strlen(alias);
                    alias[l] = key;
                    alias[l+1] = 0;
                }
                else if(key == KEY_BACKSPACE)
                {
                    int l = strlen(alias);
                    if(l >= 1)
                    {
                        alias[l-1] = 0;
                    }
                }
                else if(key == KEY_ENTER)
                {
                    maximo = true;
                }
            }

            screen->clean(color);
            texto.setFontColor(colorT);
            texto.write("INGRESE SU NOMBRE:", 103, 60, screen->getPtr());
            texto.setFontColor(GRAY);
            texto.write(alias, 480, 60, screen->getPtr());
            texto.setFontColor(GRAY);
            screen->refresh();
        }
    }

    /*
      Inicializa texto.
      Lee archivo "puntajes.dat"
      en vectores, lo ordena de
      mayor a menor, y muestra
      los 5 mejores.
    */
    texto.setFontColor(colorT);
    texto.write("HAMBURGUESAS COMIDAS:", 40, 120, screen->getPtr());
    int cant = archivo.Leer();
    archivo.GrabarTodos(alias, cant);
    char cadena[4];
    sprintf(cadena, "%d", cant);
    int pos = 0;
    int y = 300;
    char vNombres[100][10];
    int vComidos[100];
    char s[3];
    texto.setFontColor(GRAY);
    texto.write(cadena, 500, 120, screen->getPtr());
    archivo.poner0Matriz(vNombres);
    archivo.poner0Vector(vComidos);
    while(archivo.LeerTodos(pos))
    {
        cout << "Nombre: " << archivo.getNombre() << endl;
        strcpy(vNombres[pos], archivo.getNombre());
        vComidos[pos] = archivo.getComidos();
        pos++;
    }

    //Ordena.
    archivo.Ordenar(vNombres, vComidos, pos);

    //Muestra los 5 mejores y refresca.
    texto.setFontColor(colorT);
    texto.write("NOMBRE:", 40, 250, screen->getPtr());
    texto.write("COMIDAS:", 220, 250, screen->getPtr());
    texto.setFontColor(GRAY);
    for(int i = 0; i < 5; i++)
    {
        texto.write(vNombres[i], 52, y-4, screen->getPtr());
        sprintf(s, "%d", vComidos[i]);
        texto.write(s, 272, y, screen->getPtr());
        y += 30;
    }
    screen->refresh();

    //Detecta evento.
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
// METODO    : int clsPuntaje::keyCommand(bool *salir, Uint16 key).
// ACCION    : Al presionarse el boton de escape, sale de esa pagina.
// PARAMETROS: bool *salir, Uint16 key.
// DEVUELVE  : error.get().
//-------------------------------------------------------------------------------------
int clsPuntaje::keyCommand(bool *salir, Uint16 key)
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
