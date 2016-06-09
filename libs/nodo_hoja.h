#include "contacto.h"

#define NODOHOJA_HEADER 'H'

#define K 74
#define HOJA_CLAVES 2*K


typedef struct nodo_h
{
	int clave;
	char nombre[LONG_FILENAME];
	Contacto* contactos[HOJA_CLAVES];
	int cantidadClaves;
	char siguiente[LONG_FILENAME];
} NodoHoja;

/*
	Nodo (Hoja / Interno)
		> Eliminar contacto del arreglo en nodo.
*/

NodoHoja* nodohoja_Crear() {
	NodoHoja* nuevo = malloc(sizeof(NodoHoja));
	strcpy(nuevo->nombre, "");
	strcpy(nuevo->siguiente, "");

	for (int i = 0; i < HOJA_CLAVES; ++i)
	{
		nuevo->contactos[i] = NULL;
	}
	nuevo->cantidadClaves = 0;
	return nuevo;
}

void nodohoja_Guardar(NodoHoja** nodo, char* nombre) {
    char _HEADER=NODOHOJA_HEADER;
	if(nodo != NULL) {
		FILE* file = fopen(nombre, "wb");

		//Cabezal que indicará el tipo de nodo a guardar.
		fwrite(&_HEADER, sizeof(char),1, file);

		//Nombre del nodo.
		fwrite((*nodo)->nombre, sizeof(char), LONG_FILENAME, file);

		//Cantidad de Claves.
		fwrite(&(*nodo)->cantidadClaves, sizeof(int), LONG_FILENAME, file);

		//Siguiente Nodo (Nombre).
		fwrite((*nodo)->siguiente, sizeof(int), LONG_FILENAME, file);

		//Escribiendo cada contacto. 
		for (int i = 0; i < HOJA_CLAVES; ++i)
		{
			if((*nodo)->contactos[i] != NULL) {
				//clave
				fwrite(&((*nodo)->contactos[i])->clave, sizeof(int), 1, file);
				//nombre
				fwrite(((*nodo)->contactos[i])->nombre, sizeof(char), LIMIT_NAMES, file);
				//apellido
				fwrite(((*nodo)->contactos[i])->apellido, sizeof(char), LIMIT_NAMES, file);
				//Telefono
				fwrite(&((*nodo)->contactos[i])->telefono, sizeof(unsigned int), 1, file);
			}
		}

		fclose(file);
	}
}

NodoHoja* nodohoja_Cargar(char* nombre) {
	NodoHoja* nuevo = NULL;

	FILE* fp = fopen(nombre, "rb");
	if(fp != NULL) {

		//Leyendo el tipo de archivo mediante el cabezal.
		char _typeHeaderCheck;
		fread(&_typeHeaderCheck, sizeof(char), 1, fp);

		//Comprobando el tipo de archivo mediante el cabezal.
		if(_typeHeaderCheck == NODOHOJA_HEADER) {
			nuevo = nodohoja_Crear();

			//Nombre del nodo
			fread(nuevo->nombre, sizeof(char), LONG_FILENAME, fp);

			//Cantidad Claves
			fread(&nuevo->cantidadClaves, sizeof(int), 1, fp);

			//Nombre del nodo siguiente
			fread(&nuevo->siguiente, sizeof(char), LONG_FILENAME, fp);

			//Lectura de contactos disponibles.
			for (int i = 0; i < HOJA_CLAVES; ++i)
			{
				nuevo->contactos[i] = contacto_Crear();
				
				//Si se llega al final del archivo.
				if(!feof(fp)) {
					fread(&(nuevo->contactos[i])->clave, sizeof(int), 1, fp);
					fread((nuevo->contactos[i])->nombre, sizeof(char), LIMIT_NAMES, fp);
					fread((nuevo->contactos[i])->apellido, sizeof(char), LIMIT_NAMES, fp);
					fread(&(nuevo->contactos[i])->telefono, sizeof(char),LIMIT_PHONE, fp);
				}
			}
			fclose(fp);
		} else {
			printf("El nodo a cargar no es de tipo hoja.\n");
		}

	} else {
		printf("Imposible cargar el nodo hoja: %s\n", nombre);
	}

	return nuevo;
}