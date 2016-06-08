#include <contacto.h>
#include <nodo_hoja.h>
#include <lista.h>

typedef struct nodo_r
{
	char nombre[LONG_FILENAME]; 
	int claves[CLAVE_LENGTH];
	char hijos[HIJOS_LENGTH][LONG_FILENAME];
	int cantidadClaves;
	//int altura; TODO: ver si es necesario.
} NodoRaiz;