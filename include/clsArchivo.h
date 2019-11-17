//#############################################################################
// ARCHIVO             : clsArchivo.h
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
//              clase "clsArchivo".
//
///////////////////////////////////////////////////////////////////////////////

#ifndef CLSARCHIVO_H
#define CLSARCHIVO_H

#include <cstring>

using namespace std;

class clsArchivo
{
    public:
        clsArchivo();
        void setNombre(const char *nombre) {strcpy(this->nombre, nombre);}
        void setComidos(int comidos) {this->comidos = comidos;}
        const char *getNombre() {return this->nombre;}
        int getComidos() {return this->comidos;}
        void Cargar(int c);
        void Mostrar();
        void Grabar(int c);
        void GrabarTodos(char* n, int c);
        int Leer();
        bool LeerTodos(int pos);
        void poner0Vector(int vComidos[100]);
        void poner0Matriz(char vNonbres[100][10]);
        void Ordenar(char vNombres[100][10], int *vComidos, int pos);
    private:
        char nombre[10];
        int comidos;
};

#endif // CLSARCHIVO_H
