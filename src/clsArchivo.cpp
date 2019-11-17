//#############################################################################
// ARCHIVO             : clsArchivo.cpp
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
//              clase "clsArchivo".
//
///////////////////////////////////////////////////////////////////////////////

#include "clsArchivo.h"
#include <cstring>
#include <cstdio>

using namespace std;

//-------------------------------------------------------------------------------------
// METODO    : clsArchivo::clsArchivo().
// ACCION    : Constructor -> inicializa las propiedades nombre y comidos.
// PARAMETROS: Nada.
// DEVUELVE  : Nada.
//-------------------------------------------------------------------------------------
clsArchivo::clsArchivo()
{
    char nombre[10] = "Nada";
    int comidos = 0;
}

//-------------------------------------------------------------------------------------
// METODO    : void clsArchivo::Cargar(int c).
// ACCION    : Asigna c a comidos.
// PARAMETROS: int c.
// DEVUELVE  : Nada.
//-------------------------------------------------------------------------------------
void clsArchivo::Cargar(int c)
{
    comidos = c;
}

//-------------------------------------------------------------------------------------
// METODO    : void clsArchivo::Grabar(int c).
// ACCION    : Graba comidos en "puntaje.dat".
// PARAMETROS: int c.
// DEVUELVE  : Nada.
//-------------------------------------------------------------------------------------
void clsArchivo::Grabar(int c)
{
    FILE *p;
    p = fopen("ARCHIVOS\\puntaje.dat", "wb");
    comidos = c;
    fwrite(this, sizeof*this, 1, p);
    fclose(p);
}

//-------------------------------------------------------------------------------------
// METODO    : void clsArchivo::GrabarTodos(char *n, int c).
// ACCION    : Graba nombre y comidos en "puntajes.dat".
// PARAMETROS: char *n, int c.
// DEVUELVE  : Nada.
//-------------------------------------------------------------------------------------
void clsArchivo::GrabarTodos(char *n, int c)
{
    FILE *p;
    p = fopen("ARCHIVOS\\puntajes.dat", "ab");
    strcpy(nombre, n);
    comidos = c;
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}

//-------------------------------------------------------------------------------------
// METODO    : int clsArchivo::Leer().
// ACCION    : Lee a "puntaje.dat".
// PARAMETROS: Nada.
// DEVUELVE  : comidos.
//-------------------------------------------------------------------------------------
int clsArchivo::Leer()
{
    FILE *p;
    p = fopen("ARCHIVOS\\puntaje.dat", "rb");
    fread(this, sizeof *this, 1, p);
    fclose(p);
    return comidos;
}

//-------------------------------------------------------------------------------------
// METODO    : bool clsArchivo::LeerTodos().
// ACCION    : Lee a "puntajes.dat".
// PARAMETROS: Nada.
// DEVUELVE  : leyo si encuentra al archivo, de lo contrario false.
//-------------------------------------------------------------------------------------
bool clsArchivo::LeerTodos(int pos)
{
    bool leyo;
    FILE *p;
    p = fopen("ARCHIVOS\\puntajes.dat", "rb");
    if(p == NULL) return false;
    fseek(p, sizeof(clsArchivo)*pos, SEEK_SET);
    leyo = (fread(this, sizeof *this, 1, p));
    fclose(p);
    return leyo;
}

//-------------------------------------------------------------------------------------
// METODO    : void clsArchivo::poner0Vector(int vComidos[100]).
// ACCION    : Pone en 0 al vector vComidos.
// PARAMETROS: int vComidos[100].
// DEVUELVE  : Nada.
//-------------------------------------------------------------------------------------
void clsArchivo::poner0Vector(int vComidos[100])
{
    for(int i = 0; i < 100; i++)
    {
        vComidos[i] = 0;
    }
}

//-------------------------------------------------------------------------------------
// METODO    : void clsArchivo::poner0Matriz(int vNombress[100][10]).
// ACCION    : Pone en " " a la matriz vNombres.
// PARAMETROS: int vNombress[100][10].
// DEVUELVE  : Nada.
//-------------------------------------------------------------------------------------
void clsArchivo::poner0Matriz(char vNombres[100][10])
{
    for(int i = 0; i < 100; i++)
    {
        strcpy(vNombres[i], " ");
    }
}

//-------------------------------------------------------------------------------------
// METODO    : void clsArchivo::Ordenar(char vNombres[100][10], int *vComidos, int pos).
// ACCION    : Ordena de mayor a menor a la matriz vNombres y al vector vComidos.
// PARAMETROS: char vNombres[100][10], int *vComidos, int pos.
// DEVUELVE  : Nada.
//-------------------------------------------------------------------------------------
void clsArchivo::Ordenar(char vNombres[100][10], int *vComidos, int pos)
{
    char aux1[10] = " ";
    int aux2;
    for(int i = 1; i < pos; i++)
    {
        for(int j = 1; j < pos; j++)
        {
            if(vComidos[j] > vComidos[j-1])
            {
                strcpy(aux1, vNombres[j-1]);
                strcpy(vNombres[j-1], vNombres[j]);
                strcpy(vNombres[j], aux1);
                aux2 = vComidos[j-1];
                vComidos[j-1] = vComidos[j];
                vComidos[j] = aux2;
            }
        }
    }
}
