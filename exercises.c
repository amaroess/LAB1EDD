#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() 
{
   List* L = create_list(); // se crea lista
   for(int i = 1; i <= 10; i++) // for del 1 al 10
      {
         int * num = malloc(sizeof(int)); //  se reserva memoria por cada elemento
         *num = i; // se le asigna valor
         pushBack(L,num); // se inserta elemento al final de la lista
      }
   return L; // retorna lista
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) 
{
   int suma = 0; // variable para almacenar suma
   int * dato = first(L); // variable que almacena primer elemento de la lista
   while(dato != NULL) // mientras no sea el final de la lista
   {
      suma += *dato; // se suma el dato a la suma total
      dato = next(L);   // se pasa al siguiente elemento
   }
   return suma; // retorna suma total
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem)
{
   int * dato = first(L); // variable se le asigna primer elemento de la lista
   while(dato != NULL) // mientras no sea el final de la lista
   {
      if (*dato == elem) // si dato es igual al elemento
      {
         free(dato); // se libera memoria de dato para poder eliminar el nodo despues
         dato = popCurrent(L); // se elimina el elemento encontrado y retorna el anterior
      }
      else // si no es igual 
      {
         dato = next(L); // se pasa al siguiente elemento
      } 
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) 
{
   Stack* aux = create_stack(); // se crea el stack auxiliar
   void* dato; // variable dato
   dato = top(P1); // dato se le asigna primer elemento del stack
   while(dato != NULL) // mientras stack tenga datos
   {
      push(aux,dato); // se inserta dato en stack auxiliar
      pop(P1); // se elimina primer elemento de stack original
      dato = top(P1); // dato se le asigna primer elemento nuevo del stack para avanzar
   }
   dato = top(aux); // dato se le asigna primer elemento del stack auxiliar.
   while(dato != NULL) // copia final
   {
      push(P1,dato); // restaurar stack original
      push(P2,dato); // insertar en el nuevo
      pop(aux); // se elimina el primer en aux
      dato = top(aux); // se pasa al siguiente
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena)
{
   Stack* aux = create_stack();  // pila para guardar parentesis de apertura
   for(int i = 0; cadena[i] != '\0'; i++) // por cada caracter hasta llegar al final de la cadena \0
   {
      char c = cadena[i];  // variable para facilitar comparaciones y operaciones
      if(c == '(' || c == '{' || c == '[') // si es apertura
      {
         push(aux, (void*) c );   // se inserta en la pila. char --> long --> void* | caracter --> valor ascii --> puntero a void, funcion propuesta requiere void*;
         // char c = numero pequeno , void* -> direccion de memoria , (void*)c --> (void*) 21 --> invalido , "21" como ejemplo.
      }   
      else if(c == ')' || c == '}' || c == ']')   //  si es cierre
      {
         if(top(aux) == NULL) return 0; // si no hay apertura, retorna falso.
         char topc = (char) top(aux); // void* --> long --> char . variable de comparacion
         pop(aux);  // ya se guarda el top en topc, por lo que se elimina para comparar el siguiente en la proxima iteracion.
         if( (c == ')' && topc != '(') || (c == '}' && topc != '{') || (c == ']' && topc != '[') ) return 0; // si apertura no coincide con cierre retorna falso.
      }   
   }   
   if(top(aux) != NULL) return 0; // si quedan elementos en la pila significa que falta un parentesis de cierre, por lo que retorna falso.
   return 1; // retorna verdadero
}

