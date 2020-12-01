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

#define RENGLONES_IMPRESION_ARBOL 150
#define CARACTERES_RENGLON_ARBOL 500

int contadorString = 0;

/* --- Tabla de simbolos --- */
typedef struct
{
        char *nombre;
        char *nombreASM;
        char *tipo;
        union Valor{
                int valor_int;
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

t_simbolo * getLexema(const char *);
char* limpiarString(char*, const char*);
char* reemplazarChar(char*, const char*, const char, const char);
char* reemplazarString(char*, const char*);
char* obtenerID(char*);
char* limpiarPivot(char*);

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
t_nodo_arbol* CteSPtr;
t_nodo_arbol* CtePtr;
t_nodo_arbol* PosPtr; //Return de la funcion Posicion - se inicializa en 0
t_nodo_arbol* IdCompPtr; //este es el id que el usuario quiere encontrar
t_nodo_arbol* IfPtr; //Puntero al nodo IF
t_nodo_arbol* IfIzqPtr; //Puntero al nodo IF
t_nodo_arbol* IfDerPtr; //Puntero al nodo IF
t_nodo_arbol* CmpPtr; //seria el == de la comparacion del if
t_nodo_arbol* SaltoPtr; //a donde voy a saltar si encuentra la posicion
t_nodo_arbol* BiPtr; //puntero al salto incondicional
t_nodo_arbol* SumPunt; //puntero al simbolo "+"
t_nodo_arbol* UnoPtr; //1 para sumarle al pos
t_nodo_arbol* AuxPtr; //va a indicar en que posicion de la lista estoy - se inicializa en 1

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
        SPtr = ProgPtr;
        programa = SPtr;
        guardarTS();
        printf("Regla 0\n");
        printf("\nCompilacion OK.\n");
    };

prog: 
    sent { printf("Regla 1\n"); 
           ProgPtr = SentPtr;
         }
    |
    prog sent { printf("Regla 2\n"); 
                ProgPtr = crear_nodo(&num_nodo, "SENT", NODO_SIN_TIPO, ProgPtr, SentPtr);
              }
    ;

sent:
    read { printf("Regla 3\n"); 
           SentPtr = ReadPtr;
         }
    |
    write { printf("Regla 4\n"); 
            SentPtr = WritePtr;
          }
    |
    asig { printf("Regla 5\n"); 
           SentPtr = AsigPtr;
         }
    ;

read:
    READ ID { printf("Regla 6\n");
              char *valor = (char*) malloc(sizeof(char)*200);
              sprintf(valor,"%s",$2);
              valor[strlen(valor)] = '\0';

              IdPtr = crear_nodo(&num_nodo, valor, TIPO_INT, NULL, NULL);
              ReadPtr = crear_nodo(&num_nodo, "READ", NODO_SIN_TIPO, IdPtr, NULL);
            }
    ; 

asig:
    ID ASIGNA posicion { printf("Regla 7\n");
                     
                         SaltoPtr = crear_nodo(&num_nodo, "@salto", TIPO_INT, NULL, NULL);

                         AsigPtr = crear_nodo(&num_nodo, ";", NODO_SIN_TIPO, SaltoPtr, AsigPtr);

                         char *valor = (char*) malloc(sizeof(char)*200);
                         sprintf(valor,"%s",$1);
                         obtenerID(valor);
                         limpiarString(valor,valor);
                         valor[strlen(valor)] = '\0';
                         IdPtr = crear_nodo(&num_nodo, valor, TIPO_INT, NULL, NULL);

                         /* char *posi = (char*) malloc(sizeof(char)*200);
                         sprintf(posi,"%s",$3);
                         posi[strlen(valor)] = '\0';
                         PosPtr = crear_nodo(&num_nodo, posi, TIPO_INT, NULL, NULL); */
                         PosPtr = crear_nodo(&num_nodo, "@pos", TIPO_INT, ListaPtr, AsigPtr);

                         AsigPtr = crear_nodo(&num_nodo, "ASIGNA", NODO_SIN_TIPO, IdPtr, PosPtr);
                       }
    ;

posicion:
    POSICION PARA ID PYC CA lista CC PARC { printf("Regla 8\n"); 
                                            char *valor = (char*) malloc(sizeof(char)*200);
                                            sprintf(valor,"%s",$3);
                                            limpiarPivot(valor);
                                            valor[strlen(valor)] = '\0';
                                            IdPtr = crear_nodo(&num_nodo, valor, TIPO_INT, NULL, NULL);
                                            IdCompPtr = crear_nodo(&num_nodo, "@IdComp", TIPO_INT, NULL, NULL);
                                            AsigPtr = crear_nodo(&num_nodo, "ASIGNA", NODO_SIN_TIPO, IdCompPtr, IdPtr);
                                          }
    |
    POSICION PARA ID PYC CA CC PARC { printf("Regla 9\n"); }
    ;

lista:
    CTE { printf("Regla 10\n"); 
          char cad[20];

          //sumatoria del aux
          AuxPtr = crear_nodo(&num_nodo, "@aux", TIPO_INT, NULL, NULL);
          UnoPtr = crear_nodo(&num_nodo, "@1", TIPO_INT, NULL, NULL);
          SumPunt = crear_nodo(&num_nodo, "+", SUMA, AuxPtr, UnoPtr);

          //lado izquierdo (condicion)
          IfIzqPtr = crear_nodo(&num_nodo, "@IdComp", TIPO_INT, SumPunt, NULL);

          char *valor = (char*) malloc(sizeof(char)*200);
          itoa($1, cad, 10);
          sprintf(valor,"%s",cad);
          valor[strlen(valor)] = '\0';
          IfDerPtr = crear_nodo(&num_nodo, valor, TIPO_INT, NULL, NULL);
          CmpPtr = crear_nodo(&num_nodo, "CMP", NODO_SIN_TIPO, IfIzqPtr, IfDerPtr);

          //lado derecho (guardar pos y salto)
          PosPtr = crear_nodo(&num_nodo, "@pos", TIPO_INT, NULL, NULL);
          AuxPtr = crear_nodo(&num_nodo, "@aux", TIPO_INT, NULL, NULL);
          AsigPtr = crear_nodo(&num_nodo, "ASIGNA", NODO_SIN_TIPO, PosPtr, AuxPtr);

          SaltoPtr = crear_nodo(&num_nodo, "@salto", TIPO_INT, NULL, NULL);

          BiPtr = crear_nodo(&num_nodo, "BI", NODO_SIN_TIPO, AsigPtr, SaltoPtr);
          
          //padre
          ListaPtr = crear_nodo(&num_nodo, "IF", NODO_SIN_TIPO, CmpPtr, BiPtr);
        }
    |
    lista COMA CTE { printf("Regla 11\n"); 
                     char cad[20];

                     //sumatoria del aux
                     AuxPtr = crear_nodo(&num_nodo, "@aux", TIPO_INT, NULL, NULL);
                     UnoPtr = crear_nodo(&num_nodo, "@1", TIPO_INT, NULL, NULL);
                     SumPunt = crear_nodo(&num_nodo, "+", SUMA, AuxPtr, UnoPtr);

                     //lado izquierdo (condicion)
                     IfIzqPtr = crear_nodo(&num_nodo, "@IdComp", TIPO_INT, SumPunt, NULL);

                     char *valor = (char*) malloc(sizeof(char)*200);
                     itoa($3, cad, 10);
                     sprintf(valor,"%s",cad);
                     valor[strlen(valor)] = '\0';
                     IfDerPtr = crear_nodo(&num_nodo, valor, TIPO_INT, NULL, NULL);
                     CmpPtr = crear_nodo(&num_nodo, "CMP", NODO_SIN_TIPO, IfIzqPtr, IfDerPtr);

                     //lado derecho (guardar pos y salto)
                     PosPtr = crear_nodo(&num_nodo, "@pos", TIPO_INT, NULL, NULL);
                     AuxPtr = crear_nodo(&num_nodo, "@aux", TIPO_INT, NULL, NULL);
                     AsigPtr = crear_nodo(&num_nodo, "ASIGNA", NODO_SIN_TIPO, PosPtr, AuxPtr);

                     SaltoPtr = crear_nodo(&num_nodo, "@salto", TIPO_INT, NULL, NULL);

                     BiPtr = crear_nodo(&num_nodo, "BI", NODO_SIN_TIPO, AsigPtr, SaltoPtr);

                     //padre
                     IfPtr = crear_nodo(&num_nodo, "IF", NODO_SIN_TIPO, CmpPtr, BiPtr);
                     ListaPtr = crear_nodo(&num_nodo, ";", NODO_SIN_TIPO, ListaPtr, IfPtr);
                   }
    ;

write:
    WRITE CTE_S { printf("Regla 12\n"); 
                  char *valor = (char*) malloc(sizeof(char)*200);
                  sprintf(valor,"%s",$2);
                  valor[strlen(valor)] = '\0';

                  CteSPtr = crear_nodo(&num_nodo, valor, TIPO_STRING, NULL, NULL);
                  WritePtr = crear_nodo(&num_nodo, "WRITE",  NODO_SIN_TIPO, CteSPtr, NULL);
                }
    |
    WRITE ID { printf("Regla 13\n"); 
               char *valor = (char*) malloc(sizeof(char)*200);
               sprintf(valor,"%s",$2);
               valor[strlen(valor)] = '\0';

               IdPtr = crear_nodo(&num_nodo, valor, TIPO_INT, NULL, NULL);
               WritePtr = crear_nodo(&num_nodo, "WRITE", NODO_SIN_TIPO, IdPtr, NULL);
             }
    ;

%%

/*---- Código ----*/

int main(int argc, char *argv[])
{
    if((yyin = fopen(argv[1], "rt"))==NULL)
    {
        printf("\nNo se puede abrir el archivo de prueba: %s\r\n", argv[1]);
        return -1;
    }
    else
    { 
        armar_arbol(&programa);
        num_nodo = 1;

        crearTablaTS(); //tablaTS.primero = NULL;
        yyparse();
        escribir_archivo_txt(programa);
        free_arbol(&programa);
        fclose(yyin);
        return 0;
    }
}

/*---- TS ----*/

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
    char aux[100];

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
        data->nombreASM = (char*)malloc(sizeof(char) * (strlen(nombre) + 1));
        strcpy(data->nombreASM, nombre);
        return data;
    }
    else if(strcmp(tipo, "CTE_S") == 0)
    { 
        contadorString++;

        data->valor.valor_str = (char*)malloc(sizeof(char) * strlen(valString) +1);
        strcpy(data->valor.valor_str, valString);

        char auxString[50];
        strcpy(full, ""); 
        strcpy(full, "S_");
        reemplazarString(auxString, nombre);
        strcat(full, auxString);
        char numero[10];
        sprintf(numero, "_%d", contadorString);
        strcat(full, numero);


        data->nombre = (char*)malloc(sizeof(char) * (strlen(valString) + 1));
        data->nombreASM = (char*)malloc(sizeof(char) * (strlen(full) + 1));
        strcpy(data->nombre, full);
        strcpy(data->nombreASM, data->nombre);
        return data;   
    }
    else if(strcmp(tipo, "CTE") == 0)
    {
        data->valor.valor_int = valInt;
        sprintf(aux, "%d", valInt);
        strcat(full, aux);
        data->nombre = (char*)malloc(sizeof(char) * (strlen(full) + 1));
        data->nombre = (char*)malloc(sizeof(char) * strlen(full));
        strcpy(data->nombre, full);
        data->nombreASM = (char*)malloc(sizeof(char) * (strlen(full) + 1));
        strcpy(data->nombreASM, full);
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

t_simbolo * getLexema(const char *valor){
    t_simbolo *lexema;
    t_simbolo *tablaSimbolos = tablaTS.primero;

    char nombreLimpio[32];
    limpiarString(nombreLimpio, valor);
    char nombreCTE[32] = "_";
    strcat(nombreCTE, nombreLimpio);
    int esID, esCTE, esASM, esValor =-1;

    while(tablaSimbolos){  
        esID = strcmp(tablaSimbolos->data.nombre, nombreLimpio);
        esCTE = strcmp(tablaSimbolos->data.nombre, nombreCTE);
        esASM = strcmp(tablaSimbolos->data.nombreASM, valor);

        if(strcmp(tablaSimbolos->data.tipo, "CTE_S") == 0)
        {
            esValor = strcmp(valor, tablaSimbolos->data.valor.valor_str);
        }

        if(esID == 0 || esCTE == 0 || esASM == 0 || esValor == 0)
        { 
            lexema = tablaSimbolos;
            return lexema;
        }
        tablaSimbolos = tablaSimbolos->next;
    }
    return NULL;
}

/*    Funciones extras    */

char* limpiarString(char* dest, const char* cad)
{
    int i, longitud, j=0;
    longitud = strlen(cad);
    for(i=0; i<longitud; i++)
    {
        if(cad[i] != '"')
        {
            dest[j] = cad[i];
            j++;
        }
    }
    dest[j] = '\0';
    return dest;
}

char* reemplazarChar(char* dest, const char* cad, const char viejo, const char nuevo)
{
    int i, longitud;
    longitud = strlen(cad);

    for(i=0; i<longitud; i++)
    {
        if(cad[i] == viejo)
        {
            dest[i] = nuevo;
        }
        else
        {
            dest[i] = cad[i];
        }
    }
    dest[i] = '\0';
    return dest;
}

char* reemplazarString(char* dest, const char* cad)
{
    int i, longitud;
    longitud = strlen(cad);

    for(i=0; i<longitud; i++)
    {
        if((cad[i] >= 'a' && cad[i] <= 'z') || (cad[i] >='A' && cad[i] <= 'Z') || (cad[i] >= '0' && cad[i] <= '9'))
        {
            dest[i] = cad[i];
        }
        else
        {
            dest[i] = '_';
        }
    }
    dest[i] = '\0';
    return dest;
}

char* obtenerID(char* cadena)
{
    char* posAsig = strtok(cadena, "=");
    int i;

    for(i=0 ; i<strlen(cadena) ; i++) {
        if(cadena[i] == ' ') {
            cadena[i] = '\0';
        }
    }
    return cadena;
}

char* limpiarPivot(char* cadena)
{
    char* posAsig = strtok(cadena, ";");
    int i;

    for(i=0 ; i<strlen(cadena) ; i++) {
        if(cadena[i] == ' ') {
            cadena[i] = '\0';
        }
    }
    return cadena;
}

/* --- Árbol --- */

int armar_arbol(t_arbol *pa)
{
  t_nodo_arbol *pn = (t_nodo_arbol*) malloc(sizeof(t_nodo_arbol));
  if(pn == NULL) return SIN_MEMORIA;
  pn->numero = 0;
  strcpy(pn->valor,"PRG"); 
  pn->hijo_izq = NULL; 
  pn->hijo_der = NULL; 
  *pa = pn;
  return OK;
}

t_nodo_arbol* crear_nodo(int *n, char *valor, int tipo, t_nodo_arbol *hizq, t_nodo_arbol *hder)
{
  t_nodo_arbol *pn = (t_nodo_arbol*) malloc (sizeof(t_nodo_arbol));
  if(pn == NULL) return NULL;
  pn->numero = *n;
  strcpy(pn->valor,valor);
  pn->tipo = tipo; 
  pn->hijo_izq = hizq; 
  pn->hijo_der = hder; 
  *n = *n + 1;
  return pn;
}

void recorrer_arbol_posorden(t_arbol *pa, FILE *pf)
{
    if(!*pa) 
        return;
    if(!&(*pa)->hijo_izq)
    	return;

    recorrer_arbol_posorden(&(*pa)->hijo_izq,pf);
    recorrer_arbol_posorden(&(*pa)->hijo_der,pf);

	if(strcmpi((*pa)->valor,"READ")==0){
        t_simbolo *lexema = getLexema((*pa)->hijo_izq->valor);
        fprintf(pf, "\tgetFloat \t\t\t\t%s\n\tNEWLINE\n", lexema->data.nombreASM);
  	}


	if(strcmpi((*pa)->valor,"WRITE")==0){
	    if ((*pa)->hijo_izq->tipo == TIPO_INT)
	    {
	      	fprintf(pf,"\tdisplayFloat \t\t\t%s,2\n\tNEWLINE\n",(*pa)->hijo_izq->valor);
	    }
	    else if ((*pa)->hijo_izq->tipo == TIPO_STRING)
	    {
            t_simbolo *lexema = getLexema((*pa)->hijo_izq->valor);
	      	fprintf(pf,"\tdisplayString \t\t\t%s\n\tNEWLINE\n",lexema->data.nombreASM);
	    }
  	}

    if(strcmpi((*pa)->valor,"ASIGNA")==0){
        if ((*pa)->hijo_der->tipo == TIPO_INT || (*pa)->hijo_der->tipo == TIPO_CONST_INT)
        {
            lexemaDer = getLexema((*pa)->hijo_der->valor);
            fprintf(pf,"\tfld \t\t\t%s\n\t",lexemaDer->data.nombreASM);
        }
        lexemaIzq = getLexema((*pa)->hijo_izq->valor);
        fprintf(pf,"\tfstp \t\t\t%s\n\t",lexemaIzq->data.nombreASM);
    }


    if(strcmpi((*pa)->valor,"MUL")==0){
        if (((*pa)->hijo_izq->tipo == TIPO_INT || (*pa)->hijo_izq->tipo == TIPO_CONST_INT) && ((*pa)->hijo_der->tipo == TIPO_INT || (*pa)->hijo_der->tipo == TIPO_CONST_INT))
        {
            lexemaIzq = getLexema((*pa)->hijo_izq->valor);
            lexemaDer = getLexema((*pa)->hijo_der->valor);

            fprintf(pf,"\tfld \t\t\t%s\n\t",lexemaIzq->data.nombreASM);
            fprintf(pf,"\tfld \t\t\t%s\n\t",lexemaDer->data.nombreASM);
        }
        fprintf(pf,"\tfmul \n\t");
    }
    
    if(strcmpi((*pa)->valor,"MAS")==0){

        if (((*pa)->hijo_izq->tipo == TIPO_INT || (*pa)->hijo_izq->tipo == TIPO_CONST_INT) && ((*pa)->hijo_der->tipo == TIPO_INT || (*pa)->hijo_der->tipo == TIPO_CONST_INT))
        {
            lexemaIzq = getLexema((*pa)->hijo_izq->valor);
            lexemaDer = getLexema((*pa)->hijo_der->valor);

            fprintf(pf,"\tfld \t\t\t%s\n\t",lexemaIzq->data.nombreASM);
            fprintf(pf,"\tfld \t\t\t%s\n\t",lexemaDer->data.nombreASM);
        }
        fprintf(pf,"\tfadd \n\t");
    }
    
    if(strcmpi((*pa)->valor,"DIV")==0){
        if (((*pa)->hijo_izq->tipo == TIPO_INT || (*pa)->hijo_izq->tipo == TIPO_CONST_INT) && ((*pa)->hijo_der->tipo == TIPO_INT || (*pa)->hijo_der->tipo == TIPO_CONST_INT))
        {
            lexemaIzq = getLexema((*pa)->hijo_izq->valor);
            lexemaDer = getLexema((*pa)->hijo_der->valor);

            fprintf(pf,"\tfld \t\t\t%s\n\t",lexemaIzq->data.nombreASM);
            fprintf(pf,"\tfld \t\t\t%s\n\t",lexemaDer->data.nombreASM);
        }
        fprintf(pf,"\tfdiv \n\t");
    }
    
}

void free_nodo(t_nodo_arbol* pn)
{
    if(pn == NULL) return;
    free_nodo(pn->hijo_izq);
    pn->hijo_izq = NULL;
    free_nodo(pn->hijo_der);
    pn->hijo_der = NULL;
    free(pn);
    pn = NULL;
}

void free_arbol(t_arbol *pa)
{
    free_nodo(*pa);
}

t_nodo_arbol* copiar_nodo(int *n, t_nodo_arbol* pn)
{
  t_nodo_arbol *pnn = (t_nodo_arbol*) malloc (sizeof(t_nodo_arbol));
  if(pn == NULL) return NULL;
  pnn->numero = *n;
  strcpy(pnn->valor,pn->valor); 
  pnn->tipo = pn->tipo; 
  
  *n = *n + 1; 
  
  if(pn->hijo_izq == NULL){
    pnn->hijo_izq = NULL; 
  }else{
      pnn->hijo_izq = copiar_nodo(n,pn->hijo_izq); 
  }
  
  if(pn->hijo_der == NULL){
    pnn->hijo_der = NULL; 
  }else{
      pnn->hijo_der = copiar_nodo(n,pn->hijo_der); 
  }
  
  
  return pnn;
}

void copiar_sin_finalizador(char * dest,char * orig) 
{
    
    while(*orig && *dest)
    {
        *dest = *orig;
        orig++;
        dest++;     
    }
}

int _print_t(t_nodo_arbol *tree, int is_left, int offset, int depth, char * s, int max)
{
    int i;
    char b[50];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%s)", tree->valor);

    int left  = _print_t(tree->hijo_izq,  1, offset, depth + 1, s,max);
    int right = _print_t(tree->hijo_der, 0, offset + left + width, depth + 1, s,max);

    copiar_sin_finalizador(s + (2 * depth)*max + offset + left,b);

    if (depth && is_left) {

      for (i = 0; i < width + right; i++)
                copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width/2 + i,"-"); 
                copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width/2 ,"+"); 
                copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width + right + width/2 ,"+"); 

    } else if (depth && !is_left) {
        for (i = 0; i < left + width; i++)
            copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset - width/2 + i ,"-"); 
            copiar_sin_finalizador(s + (2 * depth - 1)*max  + offset + left + width/2 ,"+"); 
    }

    return left + width + right;
}

int escribir_archivo_txt(t_nodo_arbol *tree)
{
    
  FILE *f = fopen("Intermedia.txt", "w+");
    if (f == NULL)
    {
        puts("Error abriendo archivo de notacion intermedia");
        exit(1);
    }
    int i;
  char * s = (char *) malloc(sizeof(char) * RENGLONES_IMPRESION_ARBOL * CARACTERES_RENGLON_ARBOL);

  for (i = 0; i < RENGLONES_IMPRESION_ARBOL * CARACTERES_RENGLON_ARBOL; i++)
  {
    if(i == 0 || i % (CARACTERES_RENGLON_ARBOL - 1))
        sprintf(s + i, "%c", ' ');
    else
        sprintf(s + i, "%c", '\0');
  }

    _print_t(tree, 0, 0, 0, s,CARACTERES_RENGLON_ARBOL);

    for (i = 0; i < RENGLONES_IMPRESION_ARBOL; i++)
    {
        fprintf(f, "%s\n", s + i*CARACTERES_RENGLON_ARBOL);
    }    
    fclose(f);
}