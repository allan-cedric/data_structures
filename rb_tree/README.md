# Estrutura de dados: Red-Black Tree (Árvore Rubro-negra)

## Arquivos do projeto

*   `rb.h && rb.c`: Biblioteca que implementa a estrutura de dados.

*   `test_rb.c`: Programa principal para testar as operações da estrutura de dados.

*   `makefile`: Arquivo para compilação da biblioteca e do programa principal.

## Compilação e teste padrão

```sh
make
./test_rb
```

## Como usar a biblioteca ? #TODO

```C
#include "rb.h"

int main()
{
    ...

    RBTree *rootRBTree = createRBTree(); # Instância de uma árvore.

    ...
    return 0;
}
```

## Principais operações implementadas #TODO

*   Inserção / Busca / Remoção

*   Mínimo / Máximo / Altura

*   Impressão: preOrder; inOrder && posOrder
