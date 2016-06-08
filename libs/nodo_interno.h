#include <contacto.h>

typedef struct nodo_i
{
	char nombre[LONG_FILENAME]; 
	int claves[CLAVE_LENGTH];
	char hijos[HIJOS_LENGTH][LONG_FILENAME];
	int cantidadClaves;
} NodoInterno;