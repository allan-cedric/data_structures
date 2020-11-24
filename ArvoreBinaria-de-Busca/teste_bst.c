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
		printf("Criando nodo raiz com valor 5...\n");
		printf("Nodo raiz criado com sucesso!\n\n");

		printf("Inserindo nodo com valor 1...\n");
		rootBst = insertNodeBST(rootBst, 1);
		printf("Inserindo nodo com valor 9...\n");
		rootBst = insertNodeBST(rootBst, 9);
		printf("Inserindo nodo com valor 10...\n");
		rootBst = insertNodeBST(rootBst, 10);
		printf("Inserindo nodo com valor 0...\n");
		rootBst = insertNodeBST(rootBst, 0);
		printf("Inserindo nodo com valor 4...\n");
		rootBst = insertNodeBST(rootBst, 4);
		printf("Inserindo nodo com valor 8...\n");
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
	genericNodeBst = maxValueBST(rootBst);
	printf("\n\nMaior valor: %i", genericNodeBst->value);
	genericNodeBst = minValueBST(rootBst);
	printf("\nMenor valor: %i\n", genericNodeBst->value);

	/* Teste de busca de elementos na BST */
	printf("\nBuscando o valor 4...\n");
	genericNodeBst = searchBST(rootBst, 4);
	if (genericNodeBst)
		printf("Valor ENCONTRADO: %i\n", genericNodeBst->value);
	else
		printf("Valor NÃO encontrado\n");

	printf("\nBuscando o valor 12...\n");
	genericNodeBst = searchBST(rootBst, 12);
	if (genericNodeBst)
		printf("Valor ENCONTRADO: %i\n", genericNodeBst->value);
	else
		printf("Valor NÃO encontrado\n");

	printf("\n\nRemovendo o valor 5...");
	rootBst = removeNodeBST(rootBst, 5);
	printf("\npreOrder: ");
	printBST(rootBst, "pre");

	printf("\ninOrder: ");
	printBST(rootBst, "in");

	printf("\nposOrder: ");
	printBST(rootBst, "pos");

	printf("\n\nRemovendo o valor 8...");
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
