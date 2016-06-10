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
	Contacto* c1 = contacto_Generar(3, "Bruno", "Rojas", "+56956615239");
	Contacto* c2 = contacto_Generar(6, "Iracundo", "Canivilo", "+56965863107");
	nodohoja_Guardar(&t);


	t = nodohoja_Cargar("0000");


	for (int j = 0; j < HOJA_CLAVES; j++)
	{
			printf("Contacto[%i]: [%i] Nombre: %s %s (Tel.: %s)\n", j, (t->contactos[j])->clave, (t->contactos[j])->nombre, (t->contactos[j])->apellido, (t->contactos[j])->telefono);
	}

	return 0;
}