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

List* crea_lista() {
   List* L = create_list();
   for(int i = 1; i <= 10; i++)
   {
      int* valor = (int*)malloc(sizeof(int));
      *valor = i;
      pushBack(L,valor);
   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int* actual = (int*)first(L);
   int sum = 0;
   while (actual != NULL)
   {
      sum += *actual;
      actual = (int*)next(L);
   }  
   return sum;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int* actual = (int*)first(L);
   while (actual != NULL)
   {
      if (*actual == elem)
      {
         popCurrent(L);
      }
      actual = (int*)next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {

Stack* PAUX = create_stack();
   while (top(P1) != NULL)
   {
      int* valor = (int*)top(P1);
      push(PAUX,valor);
      pop(P1);
   }
   while (top(PAUX) != NULL)
   {
      int* valor = (int*)top(PAUX);
      push(P2,valor);
      push(P1,valor);
      pop(PAUX);
   }
}
/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   int i = 0;
   Stack* Pila1 = create_stack();
   Stack* Pila2 = create_stack();
   if (strlen(cadena) % 2 == 0)
   {
      while (cadena[i] != '\0')
      {
         char elemento = cadena[i];
         push(Pila1, (void*)(int*)elemento);
         i++;
      }
      for (size_t i = 0; i < (strlen(cadena) / 2); i++)
      {
         char letra = (char)top(Pila1);
         push(Pila2,(void*)(int*)letra);
         pop(Pila1);
      }
      for (size_t i = 0; i < (strlen(cadena) / 2); i++)
      {
         if (top(Pila1) != top(Pila2))
         {
            return 0;
         }
         pop(Pila1);
         pop(Pila2);
      }
      return 1;
   }
   return 1;
   }