//#############################################################################
// ARCHIVO             : clsBoton.h
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
//              clase "clsBoton".
//
///////////////////////////////////////////////////////////////////////////////

#ifndef CLSBOTON_H
#define CLSBOTON_H

#include <clsSprite.h>


class clsBoton : public clsSprite
{
    public:
        void inherit() {}
        int init(char*);
        void animar(clsScreen *scr);
        bool wasClick(int, int);

    protected:

    private:
};

#endif // CLSBOTON_H
