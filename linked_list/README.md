# Estrutura de dados: Linked list (Lista ligada simples)

## Arquivos do projeto

*   `linked_list.h && linked_list.c`: Biblioteca que implementa a estrutura de dados.

*   `test_linked_list.c`: Programa principal para testar as operações da estrutura de dados.

*   `makefile`: Arquivo para compilação da biblioteca e do programa principal.

## Compilação e teste padrão

```sh
make
./main
```

## Como usar a biblioteca ?

```C
#include "linked_list.h"

int main()
{
    ...

    linked_list_t list; # Instância de uma lista.
    init_list(&list)    # Inicializa a lista.
    
    ...
    return 0;
}
```

## Principais operações implementadas

*   Inserção / Busca / Remoção

*   Concatenação / Impressão / Cópia
