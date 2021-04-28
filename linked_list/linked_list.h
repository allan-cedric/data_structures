// === Header file: linked_list.h ===

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

// === Bibliotecas ===
#include <stdio.h>
#include <stdlib.h>

// === Estrutura de dados de um nodo com chave inteira ===
typedef struct node_t
{
    int key;
    struct node_t *next;
} node_t;

// === Estrutura de dados: Linked list ===
typedef struct linked_list_t
{
    node_t *init;
    int size;
} linked_list_t;

// === Inicializa uma lista ===
void init_list(linked_list_t *l);

// === Retorna 1 se a lista está vazia, senão 0 ===
int empty_list(linked_list_t *l);

// === Destrói uma lista ===
void destroy_list(linked_list_t *l);

// === Insere uma chave 'x' no início da lista ===
void push_front_list(int x, linked_list_t *l);

// === Insere uma chave 'x' no final da lista ===
void push_back_list(int x, linked_list_t *l);

// === Inserção de uma chave 'x' de forma ordenada ===
void push_inorder_list(int x, linked_list_t *l);

// === Remove a primeira chave da lista ===
// Retorna o elemento removido em 'item'.
void pop_front_list(int *item, linked_list_t *l);

// === Remove a última chave da lista ===
// Retorna o elemento removido em 'item'.
void pop_back_list(int *item, linked_list_t *l);

// === Remove uma certa chave da lista ===
// Retorna o elemento removido em 'item'.
void pop_list(int key, int *item, linked_list_t *l);

// === Busca de uma chave na lista ===
// Retorna 1 se encontrou, senão 0.
int in_list(int key, linked_list_t *l);

// === Concatena duas listas distintas ===
void concatenate_lists(linked_list_t *l, linked_list_t *m);

// === Cria uma cópia da lista 'l' na lista 'm' ===
void copy_list(linked_list_t *l, linked_list_t *m);

// === Impressão de uma lista ===
void print_list(linked_list_t *l);

#endif