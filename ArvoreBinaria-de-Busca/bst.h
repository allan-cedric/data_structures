/* 
   Header file : 'bst.h'
   Escrito por : Allan Cedric G.B. Alves da Silva
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
  Estrutura de dado de um nodo (p/ BST) com valor simples => int
*/
typedef struct node_t
{
  struct node_t *left;
  struct node_t *right;
  struct node_t *parent;
  int value;
} BST;

/* Avalia se a BST está vazia(1) ou não(0) */
int emptyBST(BST *root);

/* Cria a BST */
BST *createBST();

/* Cria um novo nodo */
BST *newNode(int value);

/* Insere um novo nodo */
BST *insertNodeBST(BST *root, int value);

/* Imprime BST com 3 opções possíveis: "pre", "in" ou "pos" */
void printBST(BST *root, const char *op);

/* Destrói a BST */
BST *destroyBST(BST *root);

/* Busca na BST. Retorna um ponteiro para o nodo buscado, caso contrário NULL */
BST *searchBST(BST *node, int value);

/* Retorna um ponteiro para o nodo que contém a MENOR valor */
BST *minValueBST(BST *node);

/* Retorna um ponteiro para o nodo que contém a MAIOR valor */
BST *maxValueBST(BST *node);

/* Retorna o número de nodos da BST */
int numNodesBST(BST *node);

/* Retorna a altura (nível máximo) da BST */
int heightBST(BST *node);

/* Remove um nodo da BST */
BST *removeNodeBST(BST *root, int value);

/* Redireciona uma sub-árvore como filho de um novo nodo */
BST *transplantSubtreeBST(BST *root, BST *node, BST *nodeChild);

#endif
