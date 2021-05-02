// === Header file: rb.h ===

#ifndef __RB_H__
#define __RB_H__

// === Bibliotecas ===
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// === Conjunto enumerado do sistema de cores da Red-Black Tree ===
typedef enum rbtree_node_color
{
    BLACK,
    RED
} rbtree_node_color;

// === Estrutura de dados de um nodo da Red-Black Tree ===
typedef struct rbtree_node_t
{
    int key;
    rbtree_node_color color;
    struct rbtree_node_t *left, *right, *parent;
} RBTree;

// === Inicializa uma Red-Black Tree ===
RBTree *createRBTree();

// === Retorna 1 se a Red-Black Tree está vazia, senão 0 ===
int emptyRBTree(RBTree *root);

// === Cria um novo nodo para uma Red-Black Tree ===
// Retorna um ponteiro para o nodo criado.
RBTree *newNode(int key);

// === Destrói uma Red-Black Tree ===
RBTree *destroyRBTree(RBTree *root);

// === Imprimi uma Red-Black Tree ===
// Possui 3 opções (const char op): "pre", "in" e "pos".
void printRBTree(RBTree *root, const char *op);

// === Busca um certo elemento em uma Red-Black Tree ===
// Retorna um ponteiro para o nodo encontrado, senão NULL.
RBTree *searchRBTree(RBTree *root, int key);

// === Retorna um ponteiro para o nodo com o menor elemento ===
RBTree *minRBTree(RBTree *root);

// === Retorna um ponteiro para o nodo com o maior elemento ===
RBTree *maxRBTree(RBTree *root);

// === Rotação para direita (Caso Esquerda-Esquerda) ===
RBTree *LLRotationRBTree(RBTree *root, RBTree *node_x);

// === Rotação para direita (Caso Direita-Direita) ===
RBTree *RRRotationRBTree(RBTree *root, RBTree *node_x);

// === Insere um novo elemento em uma Red-Black Tree ===
RBTree *insertRBTree(RBTree *root, int key);

// === Corrigi a Red-Black Tree após uma inserção ===
RBTree *insertFixUpRBTree(RBTree *root, RBTree *new);

// === Retorna a altura de um nodo em uma Red-Black Tree ===
int heightNodeRBTree(RBTree *root);

#endif
