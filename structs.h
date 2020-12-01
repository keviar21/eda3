#ifndef STRUCTS_H
#define STRUCTS_H

#define OK 0
#define TIPO_INT 1
#define TIPO_STRING 2
#define TIPO_CONST_INT 3
#define SUMA 4
#define AUX 5
#define NODO_SIN_TIPO 0
#define SIN_MEMORIA -1

/* --- Nodo árbol --- */
typedef struct s_nodo_arbol
{
	int numero;
	char valor[50];
	int tipo;
	struct s_nodo_arbol *hijo_izq;
	struct s_nodo_arbol *hijo_der;
} t_nodo_arbol;

typedef t_nodo_arbol* t_arbol;

#endif