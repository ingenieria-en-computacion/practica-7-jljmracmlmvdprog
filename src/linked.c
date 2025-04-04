#include <stdlib.h>
#include <stdio.h>
#include "linked.h"

List_int* list_int_create(void) {
    List_int* list = (List_int*)malloc(sizeof(List_int)); // Reservamos memoria para la lista
    if (!list) return NULL; // Verifica si la memoria fue asignada correctamente

    list->head = list->tail = NULL; // Inicializa la lista vacía
    list->length = 0; // La longitud comienza en 0
    return list; // Devuelve la lista creada
}

void list_int_destroy(List_int* list) {
    if (!list) return; // Si la lista es NULL, no hacemos nada

    Node_int* current = list->head; // Empezamos desde el primer nodo
    while (current) {
        Node_int* temp = current;
        current = current->next;
        free(temp); // Liberamos cada nodo
    }
    free(list); // Finalmente liberamos la memoria de la lista
}

bool list_int_append(List_int* list, int data) {
    if (!list) return false; // Verifica que la lista no sea NULL

    Node_int* new_node = (Node_int*)malloc(sizeof(Node_int)); // Reservamos memoria para un nuevo nodo
    if (!new_node) return false; // Si hubo un error reservando memoria, retorna false

    new_node->data = data; // Asignamos el dato al nuevo nodo
    new_node->next = NULL; // El nuevo nodo no apunta a nada por ahora

    if (list->length == 0) {
        list->head = list->tail = new_node; // Si la lista está vacía, head y tail apuntan al nuevo nodo
    } else {
        list->tail->next = new_node; // El nodo final de la lista apunta al nuevo nodo
        list->tail = new_node; // Ahora el tail es el nuevo nodo
    }

    list->length++; // Aumentamos la longitud de la lista
    return true; // Retorna true indicando que el elemento fue agregado correctamente
}

size_t list_int_length(const List_int* list) {
    if (!list) return 0; // Si la lista es NULL, retorna 0
    return list->length; // Retorna la longitud de la lista
}

void list_int_print(const List_int* list) {
    if (!list) return; // Si la lista es NULL, no imprimimos nada

    Node_int* current = list->head; // Empezamos desde el primer nodo
    while (current) {
        printf("%d -> ", current->data); // Imprimimos el dato de cada nodo
        current = current->next;
    }
    printf("NULL\n"); // Fin de la lista
}
