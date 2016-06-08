#define NODOINTER_HEADER "nodo_i"

typedef struct nodo_i
{
	char nombre[LONG_FILENAME]; 
	int claves[CLAVE_LENGTH];
	char hijos[HIJOS_LENGTH][LONG_FILENAME];
	int cantidadClaves;
} NodoInterno;

/*
	Nodo (Hoja / Interno)
	> CrearNodo.
	> LiberarNodo.
	> Eliminar clave del arreglo en nodo.
	> Guardar / Cargar.
*/