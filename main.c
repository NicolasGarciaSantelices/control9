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
	t = nodohoja_Cargar("0000");
	printf("clave: %i \n", t->clave);
	printf("nombre: %s \n", t->nombre);
	printf("cantidadClaves: %i \n", t->cantidadClaves);
	printf("nombre (sig): %s \n", t->siguiente);
	printf("Contacto[0]: Clave: %i\n", (t->contactos[1])->clave);
	printf("Contacto[0]: Nombre: %s %s\n", (t->contactos[1])->nombre, (t->contactos[1])->apellido);
	printf("Contacto[0]: Tel.: %s\n", (t->contactos[1])->telefono);
	return 0;
    
}