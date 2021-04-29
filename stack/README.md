# Estrutura de dados: Stack (Pilha)

## Arquivos do projeto

*   `stack.h && stack.c`: Biblioteca que implementa a estrutura de dados.

*   `test_stack.c`: Programa principal para testar as operações da estrutura de dados.

*   `makefile`: Arquivo para compilação da biblioteca e do programa principal.

## Compilação e teste padrão

```sh
make
./test_stack
```

## Como usar a biblioteca ?

```C
#include "stack.h"

int main()
{
    ...

    stack_t stack;      # Instância de uma pilha.
    init_stack(&stack); # Inicializa a pilha.
    
    ...
    return 0;
}
```

## Principais operações implementadas

*   Push(Empilha) / Pop(Desempilha) / Top(Elemento do topo da pilha)
