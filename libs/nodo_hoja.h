#include <contacto.h>

typedef struct nodo_h
{
	char* nombre;
	Contacto* contacto[CLAVE_LENGTH];
	int cantidadClaves;
	struct nodo_h* siguiente;
} NodoHoja;