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
	FILE *file = fopen(nombre, "wb");

	if(nodo != NULL) {
		if(file != NULL) {
			//Escribiendo tipo de nodo como cabezal. (6 * 1 bytes = 6)
			fwrite(NODOINTER_HEADER, sizeof(char), NODO_HEADER_LENGTH, file);

			//Nombre del nodo (5 * 1 byte = 5 bytes)
			fwrite(nodo->nombre, sizeof(char), LONG_FILENAME, file);
			//Cantidad de Claves (4 bytes)
			fwrite(&nodo->cantidadClaves, sizeof(int), 1, file);
			//Claves (2 * 4 bytes = 8 bytes)
			fwrite(nodo->claves, sizeof(int), INTER_CLAVES, file);

			//Nombre de los hijos (5 * 3 * 1 bytes = 15 bytes)
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