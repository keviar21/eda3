/*---- 1. Declaraciones ----*/

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "y.tab.h"
#include "arbol.h"
#include "structs.h"
#define YYERROR_VERBOSE 1
FILE  *yyin;

#define RENGLONES_IMPRESION_ARBOL 70
#define CARACTERES_RENGLON_ARBOL 350

/* --- Tabla de simbolos --- */
typedef struct
{
        char *nombre;
        char *tipo;
        union Valor{
                int valor_int;
                double valor_double;
                char *valor_str;
        }valor;
        int longitud;
}t_data;

typedef struct s_simbolo
{
        t_data data;
        struct s_simbolo *next;
}t_simbolo;


typedef struct
{
        t_simbolo *primero;
}t_tabla;

void crearTablaTS();
int insertarTS(const char*, const char*, const char*, int, double);
t_data* crearDatos(const char*, const char*, const char*, int, double);
void guardarTS();
t_tabla tablaTS;

/* --- Arbol --- */
int num_nodo;
t_arbol programa;
t_nodo_arbol* SPtr;
t_nodo_arbol* ProgPtr;
t_nodo_arbol* SentPtr;
t_nodo_arbol* ReadPtr;
t_nodo_arbol* AsigPtr;
t_nodo_arbol* PosicionPtr;
t_nodo_arbol* ListaPtr;
t_nodo_arbol* WritePtr;

t_nodo_arbol* IdPtr;
t_nodo_arbol* CtePtr;
t_nodo_arbol* AcumPtr;
t_simbolo *lexemaAsig;
t_simbolo *lexemaIzq;
t_simbolo *lexemaDer;

%}

/*---- 2. Tokens - Start ----*/

%union {
int tipo_int;
char* tipo_str;
}

%start S

%token <tipo_int>CTE
%token <tipo_str>ID
%token <tipo_str>CTE_S

%token ASIGNA
%token PARA      
%token PARC
%token CA 
%token CC
%token COMA
%token PYC

%token WRITE
%token READ
%token POSICION

/*---- 3. Definición de reglas gramaticales ----*/

%%

S:
    {
        printf("\n\nInicia el COMPILADOR\n\n");
    } 
    prog {
        guardarTS();
        printf("Regla 0\n");
        printf("\nCompilacion OK.\n");
    };

prog: 
    sent { printf("Regla 1\n"); }
    |
    prog sent { printf("Regla 2\n"); }
    ;

sent:
    read { printf("Regla 3\n"); }
    |
    write { printf("Regla 4\n"); }
    |
    asig { printf("Regla 5\n"); }
    ;

read:
    READ ID { printf("Regla 6\n");
    
            }
    ; 

asig:
    ID ASIGNA posicion { printf("Regla 7\n"); }
    ;

posicion:
    POSICION PARA ID PYC CA lista CC PARC { printf("Regla 8\n"); }
    |
    POSICION PARA ID PYC CA CC PARC { printf("Regla 9\n"); }
    ;

lista:
    CTE { printf("Regla 10\n"); }
    |
    lista COMA CTE { printf("Regla 11\n"); }
    ;

write:
    WRITE CTE_S { printf("Regla 12\n"); }
    |
    WRITE ID { printf("Regla 13\n"); }
    ;

%%

/*---- 4. Código ----*/

int main(int argc, char *argv[])
{
    if((yyin = fopen(argv[1], "rt"))==NULL)
    {
        printf("\nNo se puede abrir el archivo de prueba: %s\r\n", argv[1]);
        return -1;
    }
    else
    { 
        crearTablaTS(); //tablaTS.primero = NULL;
        yyparse();
        fclose(yyin);
        return 0;
    }
}

int insertarTS(const char *nombre, const char *tipo, const char* valString, int valInt, double valDouble)
{
    t_simbolo *tabla = tablaTS.primero;
    char nombreCTE[50] = "_";
    strcat(nombreCTE, nombre);
    
    while(tabla)
    {
        if(strcmp(tabla->data.nombre, nombre) == 0 || strcmp(tabla->data.nombre, nombreCTE) == 0)
        {
            return 1;
        }
        
        if(tabla->next == NULL)
        {
            break;
        }
        tabla = tabla->next;
    }

    t_data *data = (t_data*)malloc(sizeof(t_data));
    data = crearDatos(nombre, tipo, valString, valInt, valDouble);

    if(data == NULL)
    {
        return 1;
    }

    t_simbolo* nuevo = (t_simbolo*)malloc(sizeof(t_simbolo));

    if(nuevo == NULL)
    {
        return 2;
    }

    nuevo->data = *data;
    nuevo->next = NULL;

    if(tablaTS.primero == NULL)
    {
        tablaTS.primero = nuevo;
    }
    else
    {
        tabla->next = nuevo;
    }

    return 0;
}

t_data* crearDatos(const char *nombre, const char *tipo, const char* valString, int valInt, double valDouble)
{
    char full[50] = "_";
    char aux[20];

    t_data *data = (t_data*)calloc(1, sizeof(t_data));
    if(data == NULL)
    {
        return NULL;
    }

    data->tipo = (char*)malloc(sizeof(char) * (strlen(tipo) + 1));
    strcpy(data->tipo, tipo);

    //Si es una variable
    if(strcmp(tipo, "INTEGER") == 0)
    {
        //Al nombre lo dejo aca porque no lleva _
        data->nombre = (char*)malloc(sizeof(char) * (strlen(nombre) + 1));
        strcpy(data->nombre, nombre);
        return data;
    }
    else if(strcmp(tipo, "CTE_S") == 0)
    { 
        data->valor.valor_str = (char*)malloc(sizeof(char) * strlen(valString) +1);
        strcpy(data->valor.valor_str, valString);
        
        data->nombre = (char*)malloc(sizeof(char) * (strlen(valString) + 1));
        strcat(full, valString);
        strcpy(data->nombre, full); 
        return data;   
    }
    else if(strcmp(tipo, "CTE") == 0)
    {
        data->valor.valor_int = valInt;
        sprintf(aux, "%d", valInt);
        strcat(full, aux);
        data->nombre = (char*)malloc(sizeof(char) * strlen(full));
        strcpy(data->nombre, full);
        return data;
    }
    return NULL;
}

void guardarTS()
{
    FILE* arch;
    if((arch = fopen("ts.txt", "wt")) == NULL)
    {
            printf("\nNo se pudo crear la tabla de simbolos.\n\n");
            return;
    }
    else if(tablaTS.primero == NULL)
            return;
    
    fprintf(arch, "%-50s%-25s%-50s%-30s\n", "NOMBRE", "TIPODATO", "VALOR", "LONGITUD");

    t_simbolo *aux;
    t_simbolo *tabla = tablaTS.primero;
    char linea[160];

    while(tabla)
    {
        aux = tabla;
        tabla = tabla->next;
        
        if(strcmp(aux->data.tipo, "INTEGER") == 0) //variable int
        {
            sprintf(linea, "%-50s%-25s%-50s%-ld\n", aux->data.nombre, aux->data.tipo, "--", strlen(aux->data.nombre));
        }
        else if(strcmp(aux->data.tipo, "CTE") == 0)
        {
            sprintf(linea, "%-50s%-25s%-50d%-ld\n", aux->data.nombre, aux->data.tipo, aux->data.valor.valor_int, strlen(aux->data.nombre));
        }
        else if(strcmp(aux->data.tipo, "CTE_S") == 0)
        {
            sprintf(linea, "%-50s%-25s%-50s%-ld\n", aux->data.nombre, aux->data.tipo, aux->data.valor.valor_str, strlen(aux->data.nombre));
        }
        fprintf(arch, "%s", linea);
        free(aux);
    }
    fclose(arch); 
}

void crearTablaTS()
{
    tablaTS.primero = NULL;
}