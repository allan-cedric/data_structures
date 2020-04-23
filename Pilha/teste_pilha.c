#include "pilha.h"
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    pilha_t pilha;

    printf("\nInicializando pilha...\n");
    inicializa_pilha(&pilha);
    printf("Pilha inicializada com sucesso!\n\n");
    int i, e;
    for (i = 0; i < 10; i++)
    {
        e = rand() % 30;
        printf("Empilhando %i...\n", e);
        empilha(e, &pilha);
    }
    printf("Tamanho atual da pilha: %i\n\n", tamanho_pilha(&pilha));
    while (!pilha_vazia(&pilha))
    {
        topo(&e, &pilha);
        printf("Desempilhando %i...\n", e);
        desempilha(&pilha);
    }
    printf("PILHA ESTÁ VAZIA!\n");
    printf("Tamanho atual da pilha: %i\n\n", tamanho_pilha(&pilha));

    return 0;
}