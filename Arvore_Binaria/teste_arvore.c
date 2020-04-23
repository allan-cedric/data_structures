/* 
   Source file : 'teste_arvore.c'
   Escrito por : Allan Cedric G.B. Alves da Silva
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#include "arvore_binaria.h"

int main()
{
	arvore_t arvore1;
	nodo_t *aux;

	/* Inicialização da árvore */
	printf("\nInicializando árvore...\n");
	if (inicializa_arvore(&arvore1))
		printf("Árvore inicializada com sucesso!\n");
	else
	{
		perror("Erro ao inicializar a ÁRVORE!");
		return 1;
	}

	/* Criação do nodo raiz e preenchimento da árvore */
	if (arvore_vazia(&arvore1))
	{
		printf("\nÁrvore está vazia!\n");
		printf("Inicializando nodo raiz...\n");
		if (inicializa_raiz(&arvore1, 5))
			printf("Raiz inicializada com sucesso!\n");
		else
		{
			perror("Erro ao inicializar a RAIZ!");
			return 1;
		}

		insere_nodo(&arvore1, 1);
		insere_nodo(&arvore1, 9);
		insere_nodo(&arvore1, 10);
		insere_nodo(&arvore1, 0);
		insere_nodo(&arvore1, 4);
	}

	/* Impressão de todos os tipos */
	printf("\nImprimindo árvore...\n");
	printf("Pre-order: ");
	imprime_arvore(arvore1.raiz, 1);

	printf("\nIn-order: ");
	imprime_arvore(arvore1.raiz, 2);

	printf("\nPos-order: ");
	imprime_arvore(arvore1.raiz, 3);

	/* Elementos extremos: máximo e mínimo */
	aux = maximo(arvore1.raiz);
	printf("\n\nMaior elemento: %i\n", aux->chave);

	aux = minimo(arvore1.raiz);
	printf("Menor elemento: %i\n", aux->chave);

	/* Teste de busca de elementos na árvore */
	printf("\nBuscando o elemento 4...\n");
	aux = busca(arvore1.raiz, 4);
	if (aux)
	{
		printf("Elemento encontrado: %i\n", aux->chave);
	}
	else
	{
		printf("Elemento NÃO encontrado\n");
	}

	printf("\nBuscando o elemento 12...\n");
	aux = busca(arvore1.raiz, 12);
	if (aux)
	{
		printf("Elemento encontrado: %i\n", aux->chave);
	}
	else
	{
		printf("Elemento NÃO encontrado\n");
	}

	aux = NULL;

	/* Desalocação de memória da árvore */
	printf("\nDestruindo árvore...");
	destroi_arvore(arvore1.raiz);
	printf("\nÁrvore destruída com sucesso\n\n");

	return 0;
}
