#define LIMIT_NAMES 10
#include <string.h>

typedef struct contacto
{
	int clave;
	char nombre[LIMIT_NAMES];
	char apellido[LIMIT_NAMES];
	unsigned int telefono;
} Contacto;

Contacto* contacto_Crear();
void contacto_Liberar(Contacto* contacto);
void contacto_setNombre(Contacto** contacto, char* nombre);
void contacto_setApellido(Contacto** contacto, char* apellido);


Contacto* contacto_Crear() {
	Contacto* nuevo = malloc(sizeof(Contacto));
	nuevo->clave = -1;
	contacto_setNombre(&nuevo, "");
	contacto_setApellido(&nuevo, "");
	nuevo->telefono = 0;
	return nuevo;
}

void contacto_setNombre(Contacto** contacto, char* nombre){
    if((strlen(nombre)+1) <= LIMIT_NAMES) {
    	strcpy((*contacto)->nombre, nombre);
    }else{
        printf("El nombre ingresado excede el maximo de caracteres permitidos ingrese otro nombre \n");
    }
}


void contacto_setApellido(Contacto** contacto, char* apellido){
	if((strlen(apellido)+1) <= LIMIT_NAMES) {
		strcpy((*contacto)->apellido, apellido);
	}else{
		printf("El apellido ingresado excede el maximo de caracteres permitidos ingrese otro apellido \n");
	}
}


