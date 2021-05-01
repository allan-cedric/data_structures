# Estrutura de dados: Adelson-Velsky and Landis Tree (AVL) (Árvore AVL)

## Arquivos do projeto

*   `avl.h && avl.c`: Biblioteca que implementa a estrutura de dados.

*   `test_avl.c`: Programa principal para testar as operações da estrutura de dados.

*   `makefile`: Arquivo para compilação da biblioteca e do programa principal.

## Compilação e teste padrão

```sh
make
./test_avl
```

## Como usar a biblioteca ?

```C
#include "avl.h"

int main()
{
    ...

    AVL *rootAVL = createAVL(); # Instância de uma árvore.

    ...
    return 0;
}
```

## Principais operações implementadas

*   Inserção / Busca / Remoção

*   Mínimo / Máximo / Altura

*   Impressão: preOrder; inOrder && posOrder
