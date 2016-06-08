#include <contacto.h>
#include <lista.h>

typedef struct nodo_h
{
	char* nombre;
	Contacto* contacto[CLAVE_LENGTH];
	int cantidadClaves;
	int altura;
	struct nodo_h* siguiente;
} NodoHoja;