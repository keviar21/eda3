%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <limits.h>

#include "y.tab.h"

/* CONSTANTES */
#define ERROR_ID 3
#define ERROR_STR 5
#define ERROR_INT 7
#define ERROR_REAL 9
#define DEBUG_MODE 0

/* VARIABLES */
FILE    *yyin;
char    *yyltext;

/* FUNCIONES*/
int yyerror(char *, int, int, int);
int insertarTS(const char*, const char*, const char*, int, double, int);
void debug_print(char*, char *);

/* TABLA DE SIMBOLOS*/
    void validarString(char[]);
    void validarFloat(double);
    void validarInt(int);
    char valor[20];
%}

%option noyywrap
%option yylineno

DIGITO			    [0-9]
CTE		            ({DIGITO})+
LETRA			    [a-zA-Z]
COMILLA             "\""
CARACTER	        ({DIGITO}|{CTE})+
ID					{LETRA}({LETRA}|{DIGITO})*
CTE_S               {COMILLA}([^\"])*{COMILLA}

ASIGNA   		    "="
PARA                "\("
PARC                "\)"
CA                  "\["
CC                  "\]"
COMA                "\,"
PYC                 "\;"

%%
{CTE}               {   debug_print("CTE", yytext); 
                        yylval.tipo_int = atoi(yytext);
						validarInt(yylval.tipo_int);
                    	insertarTS(yytext, "CTE", "", yylval.tipo_int, 0, 0);
                        return CTE;                                                     
                    }

{CTE_S}             {   debug_print("CTE_S", yytext); 
                        yylval.tipo_str = yytext;
                    	insertarTS(yylval.tipo_str, "CTE_S", yylval.tipo_str, 0, 0, 0);
                        return CTE_S;                                                   
                    }

{ASIGNA}            {  debug_print("ASIGNA", yytext); return ASIGNA;                    }
{PARA}              {  debug_print("PARA", yytext); return PARA;                        }
{PARC}              {  debug_print("PARC", yytext); return PARC;                        }
{CA}                {  debug_print("CA", yytext); return CA;                            }
{CC}                {  debug_print("CC", yytext); return CC;                            }
{COMA}              {  debug_print("COMA", yytext); return COMA;                        }
{PYC}               {  debug_print("PYC", yytext); return PYC;                          }

"WRITE"             {  debug_print("WRITE", yytext); return WRITE;                      }
"write"             {  debug_print("WRITE", yytext); return WRITE;                      }
"READ"              {  debug_print("READ", yytext); return READ;                        }
"read"              {  debug_print("READ", yytext); return READ;                        }
"posicion"			{  debug_print("POSICION", yytext); return POSICION;                }
{ID}                {  debug_print("ID", yytext); yylval.tipo_str = yytext; 
                       insertarTS(yylval.tipo_str, "INTEGER", "", 0, 0, 0);
                       return ID;  
                    }
" "
.                   {printf("%s", yytext); yyerror("ERROR: TOKEN NO RECONOCIDO", 0, 0, 0);}

%%

int yyerror(char *mensaje, int fila, int ci, int cf)
{
    if(fila == 0 || ci == 0 || cf == 0) /* || fila <= yylineno)*/
        printf("\nLinea %d: %s.\n", yylineno, mensaje);
    else
        printf("\nLinea %d, %d-%d: %s.\n", fila, ci, cf, mensaje);
    
    exit(1);
}

void validarInt(int numero)
{
    if(numero < 0)
    {
        yyerror("Error: La lista solo puede tener constantes enteras positivas", 0, 0, 0);
    }
}

void debug_print(char* tipo, char *mensaje)
{
    if (DEBUG_MODE == 1)
        printf("\nLEX: %s [%s]\n", mensaje, tipo);    

    return;
}