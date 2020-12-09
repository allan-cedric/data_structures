/* 
   Source file : 'teste_avl.c'
   Escrito por : Allan Cedric G.B. Alves da Silva
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#include "avl.h"

int main()
{
	/* Inicialização da AVL */
	printf("\nInicializando uma AVL...\n");
	AVL *rootAVL = createAVL();

	/* Criação do nodo raiz e preenchimento da AVL */
	if (emptyAVL(rootAVL))
	{
		printf("\nAVL está vazia!\n");
		rootAVL = insertNodeAVL(rootAVL, 5);
		printf("Criando nodo raiz com chave 5...\n");
		printf("Nodo raiz criado com sucesso!\n\n");

		printf("Inserindo nodo com chave 1...\n");
		rootAVL = insertNodeAVL(rootAVL, 1);
		printf("Inserindo nodo com chave 9...\n");
		rootAVL = insertNodeAVL(rootAVL, 9);
		printf("Inserindo nodo com chave 10...\n");
		rootAVL = insertNodeAVL(rootAVL, 10);
		printf("Inserindo nodo com chave 0...\n");
		rootAVL = insertNodeAVL(rootAVL, 0);
		printf("Inserindo nodo com chave 4...\n");
		rootAVL = insertNodeAVL(rootAVL, 4);
		printf("Inserindo nodo com chave 8...\n");
		rootAVL = insertNodeAVL(rootAVL, 8);
	}

	/* Impressão da AVL em cada formato */
	printf("\nImprimindo AVL...\n");
	printf("preOrder: ");
	printAVL(rootAVL, "pre");

	printf("\ninOrder: ");
	printAVL(rootAVL, "in");

	printf("\nposOrder: ");
	printAVL(rootAVL, "pos");

	/* Número de nodos da AVL e sua altura*/
	printf("\n\nNúmero de nodos da AVL: %i\n", numNodesAVL(rootAVL));
	printf("Altura da AVL: %i", heightAVL(rootAVL));

	/* Elementos extremos: máximo e mínimo */
	AVL *genericNodeAVL;
	genericNodeAVL = maxKeyAVL(rootAVL);
	printf("\n\nMaior chave: %i", genericNodeAVL->key);
	genericNodeAVL = minKeyAVL(rootAVL);
	printf("\nMenor chave: %i\n", genericNodeAVL->key);

	/* Teste de busca de elementos na AVL */
	printf("\nBuscando a chave 4...\n");
	genericNodeAVL = searchAVL(rootAVL, 4);
	if (genericNodeAVL)
		printf("Chave ENCONTRADA: %i\n", genericNodeAVL->key);
	else
		printf("Chave NÃO encontrada\n");

	printf("\nBuscando a chave 12...\n");
	genericNodeAVL = searchAVL(rootAVL, 12);
	if (genericNodeAVL)
		printf("Chave ENCONTRADA: %i\n", genericNodeAVL->key);
	else
		printf("Chave NÃO encontrada\n");

	printf("\n\nRemovendo a chave 5...");
	rootAVL = removeNodeAVL(rootAVL, 5);
	printf("\npreOrder: ");
	printAVL(rootAVL, "pre");

	printf("\ninOrder: ");
	printAVL(rootAVL, "in");

	printf("\nposOrder: ");
	printAVL(rootAVL, "pos");

	printf("\n\nRemovendo a chave 8...");
	rootAVL = removeNodeAVL(rootAVL, 8);
	printf("\npreOrder: ");
	printAVL(rootAVL, "pre");

	printf("\ninOrder: ");
	printAVL(rootAVL, "in");

	printf("\nposOrder: ");
	printAVL(rootAVL, "pos");

	genericNodeAVL = NULL;

	/* Desalocação de memória da AVL */
	printf("\n\nDestruindo AVL...\n");
	rootAVL = destroyAVL(rootAVL);
	if (emptyAVL(rootAVL))
		printf("AVL destruída com sucesso\n\n");
	else
	{
		perror("AVL NÃO foi destruída com sucesso");
		exit(1);
	}

	return 0;
}