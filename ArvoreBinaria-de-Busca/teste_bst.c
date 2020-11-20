/* 
   Source file : 'teste_bst.c'
   Escrito por : Allan Cedric G.B. Alves da Silva
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#include "bst.h"

int main()
{
	BST genericBst;
	node_t *genericNode;

	/* Inicialização da BST */
	printf("\nInicializando uma BST...\n");
	if (createBST(&genericBst))
		printf("BST inicializada com sucesso!\n");
	else
	{
		perror("Erro ao inicializar a BST! - 'createBST()'");
		exit(1);
	}

	/* Criação do nodo raiz e preenchimento da BST */
	if (emptyBST(&genericBst))
	{
		printf("\nBST está vazia!\n");
		printf("Criando nodo raiz com valor 5...\n");
		if (insertRootBST(&genericBst, 5))
			printf("Nodo raiz criado com sucesso!\n");
		else
		{
			perror("Erro ao criar o nodo raiz! - 'insertRootBST()'");
			exit(1);
		}

		printf("Inserindo nodo com valor 1...\n");
		insertNodeBST(&genericBst, 1);
		printf("Inserindo nodo com valor 9...\n");
		insertNodeBST(&genericBst, 9);
		printf("Inserindo nodo com valor 10...\n");
		insertNodeBST(&genericBst, 10);
		printf("Inserindo nodo com valor 0...\n");
		insertNodeBST(&genericBst, 0);
		printf("Inserindo nodo com valor 4...\n");
		insertNodeBST(&genericBst, 4);
		printf("Inserindo nodo com valor 8...\n");
		insertNodeBST(&genericBst, 8);
	}

	/* Impressão de todos os tipos */
	printf("\nImprimindo BST...\n");
	printf("preOrder: ");
	printBST(genericBst.root, "pre");

	printf("\ninOrder: ");
	printBST(genericBst.root, "in");

	printf("\nposOrder: ");
	printBST(genericBst.root, "pos");

	/* Número de nodos da BST e sua altura*/
	printf("\n\nNúmero de nodos da BST: %i\n", numNodesBST(genericBst.root));
	printf("Altura da BST: %i", heightBST(genericBst.root));

	/* Elementos extremos: máximo e mínimo */
	genericNode = maxValueBST(genericBst.root);
	printf("\n\nMaior valor: %i", genericNode->value);
	genericNode = minValueBST(genericBst.root);
	printf("\nMenor valor: %i\n", genericNode->value);

	/* Teste de busca de elementos na BST */
	printf("\nBuscando o valor 4...\n");
	genericNode = searchBST(genericBst.root, 4);
	if (genericNode)
		printf("Valor ENCONTRADO: %i\n", genericNode->value);
	else
		printf("Valor NÃO encontrado\n");

	printf("\nBuscando o valor 12...\n");
	genericNode = searchBST(genericBst.root, 12);
	if (genericNode)
		printf("Valor ENCONTRADO: %i\n", genericNode->value);
	else
		printf("Valor NÃO encontrado\n");

	printf("\n\nRemovendo o valor 5...");
	removeNodeBST(&genericBst, 5);
	printf("\npreOrder: ");
	printBST(genericBst.root, "pre");

	printf("\ninOrder: ");
	printBST(genericBst.root, "in");

	printf("\nposOrder: ");
	printBST(genericBst.root, "pos");

	printf("\n\nRemovendo o valor 8...");
	removeNodeBST(&genericBst, 8);
	printf("\npreOrder: ");
	printBST(genericBst.root, "pre");

	printf("\ninOrder: ");
	printBST(genericBst.root, "in");

	printf("\nposOrder: ");
	printBST(genericBst.root, "pos");

	genericNode = NULL;

	/* Desalocação de memória da BST */
	printf("\n\nDestruindo BST...");
	destroyBST(&genericBst, genericBst.root);
	printf("\nBST destruída com sucesso\n\n");

	return 0;
}
