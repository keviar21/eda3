include number.asm
include macros2.asm

.MODEL LARGE                  ; Modelo de memoria           
.386                          ; Tipo de procesador          
.STACK 200h                   ; Bytes en el stack           

.DATA

S__Ingrese_un_valor_pivot_mayor_o_igual_a_1____1  db        "Ingrese un valor pivot mayor o igual a 1: ", '$', 42 dup (?); Constante string
pivot          dd             ?              ; Variable int 
resul          dd             ?              ; Variable int 
_10            dd             10.0           ; Constante int
_20            dd             20.0           ; Constante int
_30            dd             30.0           ; Constante int
_40            dd             40.0           ; Constante int
_5             dd             5.0            ; Constante int
_4             dd             4.0            ; Constante int
S__Elemento_encontrado_en_posicion____2           db        "Elemento encontrado en posicion: ", '$', 33 dup (?); Constante string
@salto         dd             10.0           ; lugar a donde voy a saltar
@pos           dd             -1.0           ; primera posicion encontrada en la lista
@idComp        dd             -1.0           ; pivot ingresado por el usuario
@aux           dd             0.0            ; posicion de la lista en la que voy
@1             dd             1.0            ; constante para incrementar @aux

.CODE

inicio:

mov AX,@DATA                  ; Inicializa el segmento de datos
mov DS,AX                     
mov ES,AX                     


mov AX,4C00h                  ; Indica que debe finalizar la ejecución
int 21h

END inicio