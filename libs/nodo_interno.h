#define NODOINTER_HEADER 'i'

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



NodoInterno nodointer_cargar(char *nombre){
    NodoInterno* nuevo_nodo;
    FILE *file=fopen(nombre, "rb");
    if(file!=NULL){
        char _typeHeaderCheck;
        fread(&_typeHeaderCheck, sizeof(char),1, file);
        if(_typeHeaderCheck==NODOINTER_HEADER){
            nuevo_nodo=nodointer_crear();
            fread(nuevo_nodo->nombre, sizeof(char), LONG_FILENAME, file);
            fread(nuevo_nodo->claves,sizeof(int),CLAVE_LENGTH, file);
            fread(&nuevo_nodo->cantidadClaves, sizeof(int), 1, file);
            for (int i = 0; i < HIJOS_LENGTH; ++i)
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
