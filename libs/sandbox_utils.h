#include <time.h>

/*
	Operaciones externas que servirán
	para probar la funcionalidad de las estructuras creadas.
*/
	
char* nombres[10] = {
	"Pedro",
	"Juan",
	"Nicolas",
	"Aristoteles",
	"Elizabeth",
	"Anna",
	"Mendoza",
	"Daniella",
	"Ivan",
	"Alejandra"
};
	
char* apellidos[10] = {
	"Rojas",
	"Barraza",
	"Garcia",
	"Valdivia",
	"Burgos",
	"Walter",
	"Rivadeneira",
	"Vega",
	"Munizaga",
	"Ramos"
};

/* Obtener clave random */
int sandbox_getRandomKey() {
	srand(time(NULL));
	return rand();
}

/* Obtiene un nombre al azar*/
char* sandbox_getRandomNombre() {
	int r = sandbox_getRandomKey() % 10;
	return nombres[r];
}
/* Obtiene un nombre al azar*/
char* sandbox_getRandomApellido() {
	int r = sandbox_getRandomKey() % 10;
	return apellidos[r];
}

Contacto* sandbox_newContacto(int clave, char* nombre, char* apellido, char* telefono){
	Contacto* nuevo = contacto_Crear();
	nuevo->clave = clave;
	contacto_setNombre(&nuevo, nombre);
	contacto_setApellido(&nuevo, apellido);
	strcpy(nuevo->telefono, telefono);
	return nuevo;
}

NodoHoja* sandbox_newHoja() {
	NodoHoja* nuevo = nodohoja_Crear();
	nuevo->clave = 1;
	nuevo->contactos[0] = sandbox_newContacto(10, 
											sandbox_getRandomNombre(), 
											sandbox_getRandomApellido(), 
											"+56965232502");
	nuevo->cantidadClaves++;
	return nuevo;
}