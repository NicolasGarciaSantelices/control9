#include "contacto.h"

#define NODOHOJA_HEADER 'H'

#define K 55
#define HOJA_CLAVES 2 * K


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
	nuevo->clave = 0;
	nuevo->cantidadClaves = 0;
	strcpy(nuevo->nombre, "0000");
	strcpy(nuevo->siguiente, "0000");
	nuevo->nombre[LONG_FILENAME-1]  = 0;
	nuevo->siguiente[LONG_FILENAME-1]  = 0;

	for (int i = 0; i < HOJA_CLAVES; ++i)
	{
		nuevo->contactos[i] = contacto_Crear();
	}
	return nuevo;
}

void nodohoja_Guardar(NodoHoja** nodo) {
    char _header = NODOHOJA_HEADER;
	if(*nodo != NULL) {
		FILE* file = fopen((*nodo)->nombre, "wb");

		//Cabezal que indicará el tipo de nodo a guardar.
		fwrite(&_header, sizeof(char),1, file);

		//Nombre del nodo.
		fwrite((*nodo)->nombre, sizeof(char), LONG_FILENAME, file);

		//Clave del Nodo
		fwrite(&(*nodo)->clave, sizeof(int), 1, file);

		//Cantidad de Claves.
		fwrite(&(*nodo)->cantidadClaves, sizeof(int), 1, file);

		//Siguiente Nodo (Nombre).
		fwrite((*nodo)->siguiente, sizeof(char), LONG_FILENAME, file);

		//Escribiendo cada contacto. 
		for (int i = 0; i < HOJA_CLAVES; ++i)
		{
			//clave
			fwrite(&((*nodo)->contactos[i])->clave, sizeof(int), 1, file);
			//nombre
			fwrite(((*nodo)->contactos[i])->nombre, sizeof(char), LIMIT_NAMES, file);
			//apellido
			fwrite(((*nodo)->contactos[i])->apellido, sizeof(char), LIMIT_NAMES, file);
			//Telefono
			fwrite(((*nodo)->contactos[i])->telefono, sizeof(char), LIMIT_PHONE, file);

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
		if(_typeHeaderCheck == NODOHOJA_HEADER) 
		{
			nuevo = nodohoja_Crear();

			//Nombre del nodo
			fread(nuevo->nombre, sizeof(char), LONG_FILENAME, fp);
			//Clave del Nodo
			fread(&nuevo->clave, sizeof(int), 1, fp);
			//Cantidad Claves
			fread(&(nuevo->cantidadClaves), sizeof(int), 1, fp);
			//Nombre del nodo siguiente
			fread(nuevo->siguiente, sizeof(char), LONG_FILENAME, fp);

			//Lectura de contactos disponibles.
			for (int i = 0; i < HOJA_CLAVES; ++i)
			{
				//Si se llega al final del archivo.
				fread(&(nuevo->contactos[i])->clave, sizeof(int), 1, fp);
				fread((nuevo->contactos[i])->nombre, sizeof(char), LIMIT_NAMES, fp);
				fread((nuevo->contactos[i])->apellido, sizeof(char), LIMIT_NAMES, fp);
				fread((nuevo->contactos[i])->telefono, sizeof(char), LIMIT_PHONE, fp);
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

void nodohoja_addContacto(NodoHoja **nodo, Contacto* contacto) {
    if((*nodo)->cantidadClaves == 0){
        (*nodo)->contactos[(*nodo)->cantidadClaves] = contacto;
        (*nodo)->cantidadClaves++;
    }else{
        (*nodo)->contactos[(*nodo)->cantidadClaves] = contacto;
        
        //con for's la vida es más sabrosa
        for (int i = 0; i < (*nodo)->cantidadClaves; ++i)
        {
        	for (int j = 0; j < (*nodo)->cantidadClaves - i; ++j)
        	{
        		int h = j + 1;                
        		if(((*nodo)->contactos[j])->clave > ((*nodo)->contactos[h])->clave){
                    Contacto* a = (*nodo)->contactos[j];
                    (*nodo)->contactos[j] = (*nodo)->contactos[h];
                    (*nodo)->contactos[h] = a;
                }
        	}
        }
        (*nodo)->cantidadClaves++;

    }
}

//TODO: Revisar...
int nodohoja_eliminarContacto(NodoHoja *nodo, int clave){
    if(nodo != NULL) {
        int i = 0;

        while((nodo->contactos[i])->clave != clave){
            i++;
        }

        if(nodo->contactos[i+1] != NULL){
            for(i; i<nodo->cantidadClaves; i++){
                nodo->contactos[i] = nodo->contactos[i+1];
            }
        }

        nodo->contactos[i] = NULL;
    }else{
        return 0;
    }
    return 1;
}
