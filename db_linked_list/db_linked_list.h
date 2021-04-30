// === Header file: db_linked_list.h ===

#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

// === Bibliotecas ===
#include <stdio.h>
#include <stdlib.h>

// === Estrutura de dados de um nodo com chave inteira ===
typedef struct node_t
{
  int key;
  struct node_t *before, *next;
} node_t;

// === Estrutura de dados: Doubly Linked List ===
typedef struct db_linked_list_t
{
  node_t *init, *now, *end;
  int size;
} db_linked_list_t;

// === Inicializa uma lista duplamente encadeada ===
// Haverá a criação de dois nodos especiais:
// Sentinela de início && Sentinela de fim.
// Esses dois nodos facilitam algumas operações, como inserção e busca.
void init_db_list(db_linked_list_t *l);

// === Retorna 1 se a lista está vazia, senão 0 ===
int empty_db_list(db_linked_list_t *l);

// === Retorna 1 se a lista está completamente destruída, senão 0 ===
int destroyed_db_list(db_linked_list_t *l);

// === Destrói uma lista ===
void destroy_db_list(db_linked_list_t *l);

// === Retorna o tamanho da lista ===
int db_list_size(db_linked_list_t *l);

// === Aponta o ponteiro *now para o primeiro elemento da lista ===
void init_now_begin_db_list(db_linked_list_t *l);

// === Aponta o ponteiro *now para o último elemento da lista ===
void init_now_end_db_list(db_linked_list_t *l);

// === Aponta o ponteiro *now para o próximo elemento apontado por ele ===
void add_now_db_list(db_linked_list_t *l);

// === Aponta o ponteiro *now para o elemento anterior apontado por ele ===
void sub_now_db_list(db_linked_list_t *l);

// === Insere um elemento no início da lista ===
void push_front_db_list(int item, db_linked_list_t *l);

// === Insere um elemento no final da lista ===
void push_back_db_list(int item, db_linked_list_t *l);

// === Insere um elemento na lista de forma ordenada ===
void push_inorder_db_list(int item, db_linked_list_t *l);

// === Remove o primeiro elemento da lista ===
// Retorna o valor removido em (int *item).
void pop_front_db_list(int *item, db_linked_list_t *l);

// === Remove o último elemento da lista ===
// Retorna o valor removido em (int *item).
void pop_back_db_list(int *item, db_linked_list_t *l);

// === Remove o elemento apontado por *now ===
// Retorna o valor removido em (int *item).
void pop_now_db_list(int *item, db_linked_list_t *l);

// === Retorna a chave do elemento apontado por *now em (int *item) ===
void check_now_key_db_list(int *item, db_linked_list_t *atual);

// === Retorna 1 se a chave foi encontrada, senão 0. ===
int in_db_list(int item, db_linked_list_t *l);

// === Imprime toda a lista ===
void print_db_list(db_linked_list_t *l);

// === Copia a lista 'l' na lista 'c' ===
void copy_db_list(db_linked_list_t *l, db_linked_list_t *c);

// === Concatena a lista 'c' na lista 'l', a lista 'c' depois é destruída ===
void concatenate_db_lists(db_linked_list_t *l, db_linked_list_t *c);

// === Ordenada uma lista 'l' ===
void sort_db_list(db_linked_list_t *l);

// === Gera uma lista 'i' que é resultado da intercalação de uma lista 'l' com uma lista 'm' ===
void merge_db_lists(db_linked_list_t *l, db_linked_list_t *m, db_linked_list_t *i);

#endif