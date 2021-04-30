# Estrutura de dados: Doubly Linked list (Lista ligada duplamente encadeada)

## Arquivos do projeto

*   `db_linked_list.h && db_linked_list.c`: Biblioteca que implementa a estrutura de dados.

*   `test_db_linked_list.c`: Programa principal para testar as operações da estrutura de dados.

*   `makefile`: Arquivo para compilação da biblioteca e do programa principal.

## Compilação e teste padrão

```sh
make
./test_db_linked_list
```

## Como usar a biblioteca ?

```C
#include "db_linked_list.h"

int main()
{
    ...

    db_linked_list_t list; # Instância de uma lista.
    init_db_list(&list);   # Inicializa a lista.
    
    ...
    return 0;
}
```

## Principais operações implementadas

*   Inserção / Busca / Remoção

*   Concatenação / Impressão / Cópia / Intercalação(Merge)
