// === Header file: stack.h ===

#ifndef __STACK_H__
#define __STACK_H__

// === Bibliotecas ===
#include <stdio.h>

// === Estrutura de dados de um nodo com chave inteira ===
typedef struct node_t
{
	int key;
	struct node_t *next;
} node_t;

// === Estrutura de dados: Stack ===
typedef struct stack_t
{
	node_t *init;
	int size;
} stack_t;

// === Inicializa uma pilha ===
void init_stack(stack_t *s);

// === Retorna 1 se a pilha está vazia, senão 0 ===
int empty_stack(stack_t *s);

// === Retorna o tamanho da pilha ===
int stack_size(stack_t *s);

// === Empilha um elemento na pilha ===
void push_stack(int x, stack_t *s);

// === Desempilha um elemento da pilha ===
int pop_stack(stack_t *s);

// === Retorna o elemento no topo da pilha ===
int top_stack(stack_t *s);

#endif
