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

NodoHoja *crearHoja(){
	NodoHoja *auxHoja=malloc(sizeof(NodoHoja));
	auxHoja->contacto = NULL;
	auxHoja->nombre = NULL;
	auxHoja->cantidadClaves = -1;
	auxHoja->siguiente = NULL;
	return (auxHoja);
}
