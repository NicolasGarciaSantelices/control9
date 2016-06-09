#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LONG_FILENAME 5

#include "libs/nodo_hoja.h"
#include "libs/nodo_interno.h"

//Archivo util para funciones de testeo.
#include "libs/sandbox_utils.h"

/*
	Evaluación 2, Control 9.
	> Creación de Arboles B+.

	Juan Pablo Valdivia.
	Bruno Rojas Monroy.
	Nicolas Garcia Santelices.

	Estructura de Datos :: Ingecomp. :: Universidad de La Serena, 2016.
	Prof. Mauro San Martín.
*/


int main(int argc, char const *argv[])
{
	//Hola Mundo!.
	NodoHoja* t = sandbox_newHoja();
	nodohoja_Guardar(&t);
	return 0;
}