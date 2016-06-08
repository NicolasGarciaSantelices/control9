#define MAX_TEL_LENGTH 12
#define LIMIT_NAMES 10

typedef struct contacto
{
	int clave;
	char nombre[LIMIT_NAMES];
	char apellido[LIMIT_NAMES];
	int telefono[MAX_TEL_LENGTH];
} Contacto;