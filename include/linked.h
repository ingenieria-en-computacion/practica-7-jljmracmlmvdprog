#ifndef LINKED_H
#define LINKED_H

#include <stdlib.h>
#include <stdbool.h>

// Definición del nodo
typedef struct Node_int {
    int data;
    struct Node_int* next;
} Node_int;

// Definición de la lista
typedef struct {
    Node_int* head;
    Node_int* tail;
    size_t length;
} List_int;

// Declaración de funciones para la lista
List_int* list_int_create(void);
void list_int_destroy(List_int* list);
bool list_int_append(List_int* list, int data);
size_t list_int_length(const List_int* list);
void list_int_print(const List_int* list);

#endif // LINKED_H

