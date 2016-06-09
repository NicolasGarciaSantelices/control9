#define NODOINTER_HEADER 'I'

#define T 226
#define INTER_CLAVES  2 * T
#define INTER_HIJOS (INTER_CLAVES + 1)

typedef struct nodo_i
{
	int clave;
	char nombre[LONG_FILENAME]; 
	int claves[INTER_CLAVES];
	char hijos[INTER_HIJOS][LONG_FILENAME];
	int cantidadClaves;
} NodoInterno;

/*
	Nodo (Hoja / Interno)
	> CrearNodo.
	> LiberarNodo.
	> Eliminar clave del arreglo en nodo.
	> Guardar / Cargar.
*/

NodoInterno* nodointer_Crear();

int nodointer_liberar(NodoInterno *Nodo){
    if(Nodo!=NULL){
        free(Nodo->nombre);
        free(Nodo->claves);
        free(Nodo->hijos);
        free(Nodo);
        return 1;
    }else{
        return 0;
    }
}

NodoInterno* nodointer_cargar(char *nombre){
    NodoInterno* nuevo_nodo;
    FILE *file=fopen(nombre, "rb");
    if(file!=NULL){
        char _typeHeaderCheck;
        fread(&_typeHeaderCheck, sizeof(char),1, file);
        if(_typeHeaderCheck==NODOINTER_HEADER){
            nuevo_nodo=nodointer_Crear();
            fread(nuevo_nodo->nombre, sizeof(char), LONG_FILENAME, file);
            fread(nuevo_nodo->claves,sizeof(int),INTER_CLAVES, file);
            fread(&nuevo_nodo->cantidadClaves, sizeof(int), 1, file);
            for (int i = 0; i < INTER_HIJOS; ++i)
            {
                if(!feof(file)) {
                    fread(nuevo_nodo->hijos[i],sizeof(char),LONG_FILENAME,file);
                }
            }
            fclose(file);
            
        }else{
            printf("El nodo a cargar no es de tipo interno.\n");
        }
    
    }else{
        printf("Imposible cargar el nodo interno: %s\n", nombre);
    }
    return nuevo_nodo;
}

    
NodoInterno* nodointer_Crear() {
	NodoInterno* nuevo = malloc(sizeof(NodoInterno));
	strcpy(nuevo->nombre, "");
	for (int i = 0; i < INTER_HIJOS; ++i)
	{
		strcpy(nuevo->hijos[i], "");
	}
	for (int i = 0; i < INTER_CLAVES; ++i)
	{
		nuevo->claves[i] = -1;
	}
	nuevo->cantidadClaves = 0;
	return nuevo;
}

void nodointer_Guardar(NodoInterno* nodo, char* nombre) {
    char _HEADER=NODOINTER_HEADER;
	FILE *file = fopen(nombre, "wb");

	if(nodo != NULL) {
		if(file != NULL) {
			//Escribiendo tipo de nodo como cabezal.
			fwrite(&_HEADER, sizeof(char), 1, file);

			//Nombre del nodo
			fwrite(nodo->nombre, sizeof(char), LONG_FILENAME, file);
			//Cantidad de Claves
			fwrite(&nodo->cantidadClaves, sizeof(int), 1, file);
			//Claves
			fwrite(nodo->claves, sizeof(int), INTER_CLAVES, file);

			//Nombre de los hijos
			for (int i = 0; i < INTER_HIJOS; ++i)
			{
				fwrite(nodo->hijos[i], sizeof(char), LONG_FILENAME, file);
			}

			fclose(file);
		} else {
			printf("Imposible guardar el nodo: %s\n", nombre);
		}
	} else {
		printf("Hombre!, no me puedes entregar un nodo nulo.\n");
	}
}