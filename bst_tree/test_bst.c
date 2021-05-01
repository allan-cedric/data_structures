/* 
   Source file : 'teste_bst.c'
   Escrito por : Allan Cedric G.B. Alves da Silva
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#include "bst.h"

int main()
{
	/* Inicialização da BST */
	printf("\nInicializando uma BST...\n");
	BST *rootBst = createBST();

	/* Criação do nodo raiz e preenchimento da BST */
	if (emptyBST(rootBst))
	{
		printf("\nBST está vazia!\n");
		rootBst = insertNodeBST(rootBst, 5);
		printf("Criando nodo raiz com chave 5...\n");
		printf("Nodo raiz criado com sucesso!\n\n");

		printf("Inserindo nodo com chave 1...\n");
		rootBst = insertNodeBST(rootBst, 1);
		printf("Inserindo nodo com chave 9...\n");
		rootBst = insertNodeBST(rootBst, 9);
		printf("Inserindo nodo com chave 10...\n");
		rootBst = insertNodeBST(rootBst, 10);
		printf("Inserindo nodo com chave 0...\n");
		rootBst = insertNodeBST(rootBst, 0);
		printf("Inserindo nodo com chave 4...\n");
		rootBst = insertNodeBST(rootBst, 4);
		printf("Inserindo nodo com chave 8...\n");
		rootBst = insertNodeBST(rootBst, 8);
	}

	/* Impressão da BST em cada formato */
	printf("\nImprimindo BST...\n");
	printf("preOrder: ");
	printBST(rootBst, "pre");

	printf("\ninOrder: ");
	printBST(rootBst, "in");

	printf("\nposOrder: ");
	printBST(rootBst, "pos");

	/* Número de nodos da BST e sua altura*/
	printf("\n\nNúmero de nodos da BST: %i\n", numNodesBST(rootBst));
	printf("Altura da BST: %i", heightBST(rootBst));

	/* Elementos extremos: máximo e mínimo */
	BST *genericNodeBst;
	genericNodeBst = maxKeyBST(rootBst);
	printf("\n\nMaior chave: %i", genericNodeBst->key);
	genericNodeBst = minKeyBST(rootBst);
	printf("\nMenor chave: %i\n", genericNodeBst->key);

	/* Teste de busca de elementos na BST */
	printf("\nBuscando a chave 4...\n");
	genericNodeBst = searchBST(rootBst, 4);
	if (genericNodeBst)
		printf("Chave ENCONTRADA: %i\n", genericNodeBst->key);
	else
		printf("Chave NÃO encontrada\n");

	printf("\nBuscando a chave 12...\n");
	genericNodeBst = searchBST(rootBst, 12);
	if (genericNodeBst)
		printf("Chave ENCONTRADA: %i\n", genericNodeBst->key);
	else
		printf("Chave NÃO encontrada\n");

	printf("\n\nRemovendo a chave 5...");
	rootBst = removeNodeBST(rootBst, 5);
	printf("\npreOrder: ");
	printBST(rootBst, "pre");

	printf("\ninOrder: ");
	printBST(rootBst, "in");

	printf("\nposOrder: ");
	printBST(rootBst, "pos");

	printf("\n\nRemovendo a chave 8...");
	rootBst = removeNodeBST(rootBst, 8);
	printf("\npreOrder: ");
	printBST(rootBst, "pre");

	printf("\ninOrder: ");
	printBST(rootBst, "in");

	printf("\nposOrder: ");
	printBST(rootBst, "pos");

	genericNodeBst = NULL;

	/* Desalocação de memória da BST */
	printf("\n\nDestruindo BST...\n");
	rootBst = destroyBST(rootBst);
	if (emptyBST(rootBst))
		printf("BST destruída com sucesso\n\n");
	else
	{
		perror("BST NÃO foi destruída com sucesso");
		exit(1);
	}

	return 0;
}
