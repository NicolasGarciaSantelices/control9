#include "contacto.h"

#define NODOHOJA_HEADER "nodo_h"

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
		> Eliminar contacto del arreglo en nodo.
*/

NodoHoja* nodohoja_Crear() {
	NodoHoja* nuevo = malloc(sizeof(NodoHoja));
	strcpy(nuevo->nombre, "");
	strcpy(nuevo->siguiente, "");

	for (int i = 0; i < CLAVE_LENGTH; ++i)
	{
		nuevo->contacto[i] = NULL;
	}
	nuevo->cantidadClaves = 0;
	return nuevo;
}

void nodohoja_Guardar(NodoHoja** nodo, char* nombre) {
	if(nodo != NULL) {
		FILE* file = fopen(nombre, "wb");

		//Cabezal que indicará el tipo de nodo a guardar.
		fwrite(NODOHOJA_HEADER, sizeof(char), NODO_HEADER_LENGTH, file);

		//Nombre del nodo.
		fwrite((*nodo)->nombre, sizeof(char), LONG_FILENAME, file);

		//Cantidad de Claves.
		fwrite(&(*nodo)->cantidadClaves, sizeof(int), LONG_FILENAME, file);

		//Siguiente Nodo (Nombre).
		fwrite((*nodo)->siguiente, sizeof(int), LONG_FILENAME, file);

		//Escribiendo cada contacto.
		for (int i = 0; i < CLAVE_LENGTH; ++i)
		{
			if((*nodo)->contacto[i] != NULL) {
				fwrite(&((*nodo)->contacto[i])->clave, sizeof(int), 1, file);
				fwrite(((*nodo)->contacto[i])->nombre, sizeof(char), LIMIT_NAMES, file);
				fwrite(((*nodo)->contacto[i])->apellido, sizeof(char), LIMIT_NAMES, file);
				fwrite(&((*nodo)->contacto[i])->telefono, sizeof(unsigned int), 1, file);
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
		char _typeHeaderCheck[NODO_HEADER_LENGTH];
		fread(_typeHeaderCheck, sizeof(char), NODO_HEADER_LENGTH, fp);

		//Comprobando el tipo de archivo mediante el cabezal.
		if(strcmp(_typeHeaderCheck, NODOHOJA_HEADER) == 0) {
			//TODO: Crear esto...
			nuevo = nodohoja_Crear();

			//Nombre del nodo
			fread(nuevo->nombre, sizeof(char), LONG_FILENAME, fp);

			//Cantidad Claves
			fread(&nuevo->cantidadClaves, sizeof(int), 1, fp);

			//Nombre del nodo siguiente
			fread(&nuevo->siguiente, sizeof(char), LONG_FILENAME, fp);

			//Lectura de contactos disponibles.
			for (int i = 0; i < CLAVE_LENGTH; ++i)
			{
				//Si se llega al final del archivo.
				if(!feof(fp)) {
					//TODO: Crear esto...
					nuevo->contacto[i] = contacto_Crear();
					fread(&(nuevo->contacto[i])->clave, sizeof(int), 1, fp);
					fread((nuevo->contacto[i])->nombre, sizeof(char), LIMIT_NAMES, fp);
					fread((nuevo->contacto[i])->apellido, sizeof(char), LIMIT_NAMES, fp);
					fread(&(nuevo->contacto[i])->telefono, sizeof(unsigned int), 1, fp);
				} else {
					nuevo->contacto[i] = NULL;
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