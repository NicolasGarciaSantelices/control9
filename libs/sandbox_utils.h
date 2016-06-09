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
	"Manuel",
	"Anna",
	"Mendoza",
	"Ivan",
	"Sonia",
	"Alejandra"
};

/* Obtener clave random */
int sandbox_getRandomKey() {
	srand((unsigned int) time(NULL));
	return rand();
}