#ifndef ARBOL_H
#define ARBOL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"

int armar_arbol(t_arbol *);
void recorrer_arbol_posorden(t_arbol *pa,FILE* );
t_nodo_arbol* crear_nodo(int *, char *, int , t_nodo_arbol *, t_nodo_arbol *);
void free_nodo(t_nodo_arbol *);
void free_arbol(t_arbol *);
t_nodo_arbol* copiar_nodo(int *, t_nodo_arbol*);
int escribir_archivo_txt(t_nodo_arbol *pn);
void copiar_sin_finalizador(char * dest,char * orig); 
int _print_t(t_nodo_arbol *tree, int is_left, int offset, int depth, char * s, int max);

#endif