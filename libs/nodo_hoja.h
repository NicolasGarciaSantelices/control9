#include <contacto.h>

//t = 17.
typedef struct nodo_h
{
	char* nombre;
	Contacto* contacto[CLAVE_LENGTH];
	int cantidadClaves;
	struct nodo_h* siguiente;
} NodoHoja;

/*
	Nodo (Hoja / Interno)
		> CrearNodo.
		> LiberarNodo.
		> Guardar / Cargar.

*/