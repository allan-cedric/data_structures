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
  Estrutura de dado de um nodo com valor simples => int
*/
typedef struct node_t
{
  struct node_t *left;
  struct node_t *right;
  struct node_t *parent;
  int value;
} node_t;

/*
  Estrutura de dados da BST
*/
typedef struct BST
{
  struct node_t *root;
} BST;

/* Avalia se a BST está vazia(1) ou não(0) */
int emptyBST(BST *bst);

/* Cria a BST */
int createBST(BST *bst);

/* Cria um nodo raiz */
int insertRootBST(BST *bst, int value);

/* Insere um novo nodo */
int insertNodeBST(BST *bst, int value);

/* Imprime BST com 3 opções possíveis: "pre", "in" ou "pos" */
void printBST(node_t *node, const char *op);

/* Destrói a BST */
void destroyBST(BST *bst, node_t *node);

/* Busca na BST. Retorna um ponteiro para o nodo buscado, caso contrário NULL */
node_t *searchBST(node_t *node, int value);

/* Retorna um ponteiro para o nodo que contém a MENOR valor */
node_t *minValueBST(node_t *node);

/* Retorna um ponteiro para o nodo que contém a MAIOR valor */
node_t *maxValueBST(node_t *node);

/* Retorna o número de nodos da BST */
int numNodesBST(node_t *node);

/* Retorna a altura (nível máximo) da BST */
int heightBST(node_t *node);

#endif
