/* 
   Source file : 'teste_lista.c' 
   Escrito por : Allan Cedric G.B. Alves da Silva
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#include "lista.h"
#include <time.h>

int main()
{
    srand(time(NULL));

    t_lista lista, lista_1, lista_2;

    printf("\nCriando a 'lista'...\n");
    cria_lista(&lista);
    printf("Lista criada com sucesso!\n\n");

    int i;
    for (i = 0; i < 10; i++)
    {
        printf("Inserindo %i no início...\n", i);
        insere_inicio_lista(i, &lista);
    }

    printf("'lista': ");
    imprime_lista(&lista);
    printf("\nVerificando se a chave 5 está na 'lista'...\n");
    if (pertence_lista(5, &lista))
        printf("ENCONTREI!\n\n");
    else
        printf("NÃO encontrei\n\n");

    int r;
    printf("Removendo o primeiro nodo...\n");
    remove_primeiro_lista(&r, &lista);
    printf("Removendo último nodo...\n");
    remove_ultimo_lista(&r, &lista);
    printf("Removendo o nodo com chave 5...\n");
    remove_item_lista(5, &r, &lista);
    printf("'lista': ");
    imprime_lista(&lista);
    printf("\nVerificando se a chave 5 está na 'lista'...\n");
    if (pertence_lista(5, &lista))
        printf("ENCONTREI!\n\n");
    else
        printf("NÃO encontrei\n\n");

    printf("Destruindo 'lista'...\n\n");
    destroi_lista(&lista);

    for (i = 0; i < 10; i++)
    {
        printf("Inserindo %i no final...\n", i);
        insere_fim_lista(i, &lista);
    }

    printf("'lista': ");
    imprime_lista(&lista);

    printf("\nCriando a 'lista_1'...\n");
    cria_lista(&lista_1);
    printf("Lista criada com sucesso!\n\n");

    int e;
    for (i = 0; i < 10; i++)
    {
        e = rand() % 20;
        printf("Inserindo %i ordenado...\n", e);
        insere_ordenado_lista(e, &lista_1);
    }

    printf("'lista_1': ");
    imprime_lista(&lista_1);

    printf("\nConcatenando 'lista' e 'lista_1'...\n");
    concatena_listas(&lista, &lista_1);

    printf("'lista': ");
    imprime_lista(&lista);

    printf("\nCopiando a 'lista' em uma nova lista, 'lista_2'...\n");
    copia_lista(&lista, &lista_2);

    printf("'lista_2': ");
    imprime_lista(&lista_2);

    printf("\nDestruindo todas as listas!\n\n");
    destroi_lista(&lista);
    destroi_lista(&lista_2);

    return 0;
}