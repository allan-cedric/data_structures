# Estrutura de dados: Binary Search Tree (BST) (Árvore binária de busca)

## Arquivos do projeto

*   `bst.h && bst.c`: Biblioteca que implementa a estrutura de dados.

*   `test_bst.c`: Programa principal para testar as operações da estrutura de dados.

*   `makefile`: Arquivo para compilação da biblioteca e do programa principal.

## Compilação e teste padrão

```sh
make
./test_bst
```

## Como usar a biblioteca ?

```C
#include "bst.h"

int main()
{
    ...

    BST *rootBst = createBST(); # Instância de uma lista.

    ...
    return 0;
}
```

## Principais operações implementadas

*   Inserção / Busca / Remoção

*   Mínimo / Máximo / Altura

*   Impressão: preOrder; inOrder && posOrder
