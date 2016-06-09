#include <contacto.h>

//t = 17.
typedef struct nodo_h
{
	char nombre[LONG_FILENAME];
	Contacto* contacto[CLAVE_LENGTH];
	int cantidadClaves;
	char siguiente[LONG_FILENAME];
} NodoHoja;

/*
	Nodo (Hoja / Interno)
		> CrearNodo.
		> LiberarNodo.
		> Guardar / Cargar.

*/

NodoHoja *crearHoja(){
	NodoHoja *auxHoja=malloc(sizeof(NodoHoja));
	int i;
	for(i=0;i<CLAVE_LENGTH;i++);{
		auxHoja->contacto[i] = NULL;
	}
	auxHoja->nombre = NULL;
	auxHoja->cantidadClaves = -1;
	auxHoja->siguiente = NULL;
	return (auxHoja);
}



/* int LibararHoja(NodoHoja *Hoja,int ){
	if(Hojas == NULL) return 0;
	free(hoja->contacto);
	free(hoja);
	return 0;
}
*/

