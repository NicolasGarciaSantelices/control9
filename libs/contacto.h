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
        char Nnombre[LIMIT_NAMES];
        strncpy(Nnombre,nombre,LIMIT_NAMES);
        Nnombre[LIMIT_NAMES-1]='\0';
        strcpy((*contacto)->nombre, Nnombre);
        free(Nnombre);
    }
}

void contacto_setApellido(Contacto** contacto, char* apellido){
	if((strlen(apellido)+1) <= LIMIT_NAMES) {
		strcpy((*contacto)->apellido, apellido);
	}else{
        char Napellido[LIMIT_NAMES];
        strncpy(Napellido,apellido,LIMIT_NAMES);
        Napellido[LIMIT_NAMES-1]='\0';
        strcpy((*contacto)->apellido, Napellido);
        free(Napellido);
	}
}

Contacto* contacto_Crear(char* nombre,char* apellido) {
    Contacto* nuevo = malloc(sizeof(Contacto));
    contacto_setNombre(&nuevo, nombre);
    contacto_setApellido(&nuevo,apellido);
    nuevo->clave = -1;
    nuevo->telefono = 0;
    return nuevo;
}


int contacto_Liberar(Contacto *contacto){
    if(contacto!=NULL){
        free(contacto->nombre);
        free(contacto->apellido);
        free(contacto);
        return 1;
    }else{return 0;
    
    }
}

