#define LIMIT_NAMES 10
#define LIMIT_PHONE 13

typedef struct contacto
{
	int clave;
	char nombre[LIMIT_NAMES];
	char apellido[LIMIT_NAMES];
	char telefono[LIMIT_PHONE];
} Contacto;

Contacto* contacto_Crear();
int contacto_Liberar(Contacto* contacto);
void contacto_setNombre(Contacto** contacto, char* nombre);
void contacto_setApellido(Contacto** contacto, char* apellido);


Contacto* contacto_Crear() {
	Contacto* nuevo = malloc(sizeof(Contacto));
	nuevo->clave = -1;
    for (int i = 0; i < LIMIT_NAMES; ++i)
    {
        nuevo->nombre[i] = 0;
        nuevo->apellido[i] = 0;
    }
    strcpy(nuevo->nombre, " ");
    strcpy(nuevo->apellido, " ");
    //hay que ser demasiado torpe para llamar ese numero :P
	strcpy(nuevo->telefono, "+56900000000");
	return nuevo;
}


void contacto_setNombre(Contacto** contacto, char* nombre){
    if((strlen(nombre)+1) <= LIMIT_NAMES) {
    	strcpy((*contacto)->nombre, nombre);
        (*contacto)->nombre[LIMIT_NAMES-1] = 0;
    }else{
        char Nnombre[LIMIT_NAMES];
        strncpy(Nnombre,nombre,LIMIT_NAMES);
        Nnombre[LIMIT_NAMES-1] = 0;
        strcpy((*contacto)->nombre, Nnombre);

    }
}

void contacto_setApellido(Contacto** contacto, char* apellido){
	if((strlen(apellido)+1) <= LIMIT_NAMES) {
		strcpy((*contacto)->apellido, apellido);
        (*contacto)->apellido[LIMIT_NAMES-1] = 0;
	}else{
        char Napellido[LIMIT_NAMES];
        strncpy(Napellido,apellido,LIMIT_NAMES);
        Napellido[LIMIT_NAMES-1] = 0;
        strcpy((*contacto)->apellido, Napellido);
	}
}

/*
Contacto* contacto_Crear(char* nombre,char* apellido) {
    Contacto* nuevo = malloc(sizeof(Contacto));
    contacto_setNombre(&nuevo, nombre);
    contacto_setApellido(&nuevo, apellido);
    nuevo->clave = -1;
    nuevo->telefono = 0;
    return nuevo;
}*/


int contacto_Liberar(Contacto *contacto){
    if(contacto!=NULL) {
        free(contacto->nombre);
        free(contacto->apellido);
        free(contacto);
        return 1;
    }else{
        return 0;
    }
}

