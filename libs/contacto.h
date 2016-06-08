#define LIMIT_NAMES 10
#include<string.h>

typedef struct contacto
{
	int clave;
	char nombre[LIMIT_NAMES];
	char apellido[LIMIT_NAMES];
	int telefono;
} Contacto;

//TDA Contacto.
/*
	1. Creé el contacto. (Reserve memoria)
	1.5 Cree el contacto (Reserva memoria) junto a un nombre & apellido.
	2. Set al Nombre & apellido.

	contacto_setNombre(char* nombre);
	contacto_setApellido(char* apellido);

	3. Liberar contacto de memoria.>w<
*/


Contacto **contacto_setNombre(Contacto contacto,char* nombre){
    if((strlen(nombre)+1)<=LIMIT_NAMES){
        (*contacto)->nombre=nombre;
    }else{
        printf("El nombre ingresado excede el maximo de caracteres permitidos ingrese otro nombre \n");
    }
}


Contacto **contacto_setApellido(Contacto contacto,char* apellido){
    if((strlen(apellido)+1)<=LIMIT_NAMES){
        (*contacto)->nombre=apellido;
    }else{
        printf("El apellido ingresado excede el maximo de caracteres permitidos ingrese otro apellido \n");
    }
}


