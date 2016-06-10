#include <time.h>

/*
	Operaciones externas que servirán
	para probar la funcionalidad de las estructuras creadas.
*/
	
char* nombres[25] = {
	"Pedro",
	"Juan",
	"Nicolas",
	"Aristoteles",
	"Elizabeth",
	"Anna",
	"Mendoza",
	"Daniella",
	"Ivan",
	"Alejandra",
    "Diego",
    "Carlos",
    "Ramon",
    "Vania",
    "Romina",
    "Carla",
    "Bruno",
    "Michael",
    "Bastian",
    "Steve",
    "Tony",
    "Bruce",
    "Peter",
    "Catalina",
    "Mauricio"
};
	
char* apellidos[25] = {
	"Rojas",
	"Barraza",
	"Garcia",
	"Valdivia",
	"Burgos",
	"Walter",
	"Rivadeneira",
	"Vega",
	"Munizaga",
	"Ramos",
    "Rogers",
    "Stark",
    "banner",
    "Parker",
    "Perez",
    "Gonzales",
    "Santelices",
    "Orellana",
    "Villalobos",
    "Martinez",
    "Durán",
    "Tapia",
    "Arcos",
    "Morales",
    "Vega"
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
/* Obtiene un apellido al azar*/
char* sandbox_getRandomApellido() {
	int r = sandbox_getRandomKey() % 10;
	return apellidos[r];
}

/* Obtiene un numero telefonico al azar */
char* sandbox_getRandomPhone(){
	char* telefono = malloc(sizeof(char) * LIMIT_PHONE);

    telefono[0]='+';
    telefono[1]='5';
    telefono[2]='6';
    telefono[3]='9';

    srand(time(NULL));
    for(int i = 4; i < 11; i++){
    	int d = rand() % 10;
		/*	Conversión de int a char. 
			Fuente: http://stackoverflow.com/questions/2279379/how-to-convert-integer-to-char-in-c*/
        telefono[i] = '0' + d;
    }
    telefono[12] = 0;
    return telefono;
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
		sandbox_getRandomPhone());
	nuevo->cantidadClaves++;
	return nuevo;
}

NodoInterno* sandbox_newInter() {
    NodoInterno* nuevo = nodointer_Crear();
    nuevo->clave = 1;
    
    strcpy(nuevo->nombre, "0001");
    nuevo->nombre[4] = 0;
    NodoHoja* aux = sandbox_newHoja();
    
    nuevo->claves[0] = aux->clave;
    strcpy(nuevo->hijos[0], "0000");
    nuevo->cantidadClaves++;
    return nuevo;

}