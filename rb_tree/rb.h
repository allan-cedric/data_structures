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
} RBTreeNode;

// === Estrutura de dados de uma Red-Black Tree ===
typedef struct RBTree
{
    RBTreeNode *root, *nil;
} RBTree;

// === Inicializa uma Red-Black Tree ===
void createRBTree(RBTree *rb);

// === Retorna 1 se a Red-Black Tree está vazia, senão 0 ===
int emptyRBTree(RBTree *rb);

// === Cria um nodo nulo para uma Red-Black Tree ===
RBTreeNode *newNil();

// === Cria um novo nodo para uma Red-Black Tree ===
// Retorna um ponteiro para o nodo criado.
RBTreeNode *newNode(RBTree *rb, int key);

// === Destrói os nodos não nulos de uma Red-Black Tree ===
RBTreeNode *destroyNodesRBTree(RBTree *rb, RBTreeNode *root);

// === Destrói completamente uma Red-Black Tree ===
void destroyRBTree(RBTree *rb);

// === Imprimi uma Red-Black Tree ===
// Possui 3 opções (const char op): "pre", "in" e "pos".
void printRBTree(RBTree *rb, RBTreeNode *root, const char *op);

// === Busca um certo elemento em uma Red-Black Tree ===
// Retorna um ponteiro para o nodo encontrado, senão um ponteiro para o nodo Nil.
RBTreeNode *searchRBTree(RBTree *rb, RBTreeNode *root, int key);

// === Retorna um ponteiro para o nodo com o menor elemento ===
RBTreeNode *minRBTree(RBTree *rb, RBTreeNode *root);

// === Retorna um ponteiro para o nodo com o maior elemento ===
RBTreeNode *maxRBTree(RBTree *rb, RBTreeNode *root);

// === Rotação para direita (Caso Esquerda-Esquerda) ===
void LLRotationRBTree(RBTree *rb, RBTreeNode *node_x);

// === Rotação para direita (Caso Direita-Direita) ===
void RRRotationRBTree(RBTree *rb, RBTreeNode *node_x);

// === Insere um novo elemento em uma Red-Black Tree ===
void insertRBTree(RBTree *rb, int key);

// === Corrigi a Red-Black Tree após uma inserção ===
void insertFixUpRBTree(RBTree *rb, RBTreeNode *new);

// === Retorna a altura de um nodo em uma Red-Black Tree ===
int heightNodeRBTree(RBTree *rb, RBTreeNode *root);

#endif
