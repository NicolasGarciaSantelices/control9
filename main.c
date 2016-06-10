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
	:: Creación de Arboles B+.

	Juan Pablo Valdivia.
	Bruno Rojas Monroy.
	Nicolas Garcia Santelices.

	Estructura de Datos :: Ingecomp. :: Universidad de La Serena, 2016.
	Prof. Mauro San Martín.
*/

int main(int argc, char const *argv[])
{ 
    /*
		Prueba de Nodos Hoja.
    */
    printf("Probando funciones I/O para el nodo hoja.\n----------\n");
	NodoHoja* t = sandbox_newHoja();
    
	for (int j = 0; j < HOJA_CLAVES; j++)
	{
		if((t->contactos[j])->clave > -1) 
			printf("Contacto[%i]: [%i] Nombre: %s %s (Tel.: %s)\n", j, 
				(t->contactos[j])->clave, (t->contactos[j])->nombre, (t->contactos[j])->apellido, (t->contactos[j])->telefono);
	}

	nodohoja_Guardar(&t);
	t = nodohoja_Cargar("0000");


	printf("\nContactos cargados desde el fichero - 0000\n\n");
	for (int j = 0; j < HOJA_CLAVES; j++)
	{
		if((t->contactos[j])->clave > -1) 
			printf("Contacto[%i]: [%i] Nombre: %s %s (Tel.: %s)\n", j, 
				(t->contactos[j])->clave, (t->contactos[j])->nombre, (t->contactos[j])->apellido, (t->contactos[j])->telefono);
	}
    
    /*
		Prueba de Nodos Internos.
    */
    printf("\n\nProbando funciones I/O para el nodo interno.\n----------\n");
    NodoInterno* i = sandbox_newInter();
    
    nodointer_Guardar(i);
    
    printf("Cargando nodo interno - 0001\n");
    
    i = nodointer_Cargar("0001");
    
    printf("Clave[0]: %i\n", i->claves[0]);
    printf("Hijo[0]: %s\n",i->hijos[0]);
    
    
    return 0;
    
}