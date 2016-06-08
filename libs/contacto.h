#define MAX_TEL_LENGTH 12

typedef struct contacto
{
	int clave;
	char* nombre;
	char* apellido;
	int telefono[MAX_TEL_LENGTH];
} Contacto;