// === Source file: test_stack.c ===

#include "stack.h"
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    stack_t stack_1;

    printf("\nCreating 'stack_1'...\n");
    init_stack(&stack_1);
    printf("'stack_1' created successfully!\n\n");
    
    for (int i = 0, e; i < 10; i++)
    {
        e = rand() % 30;
        printf("Pushing %i...\n", e);
        push_stack(e, &stack_1);
    }

    printf("'stack_1' size: %i\n\n", stack_size(&stack_1));
    while (!empty_stack(&stack_1))
    {
        printf("Popping %i...\n", top_stack(&stack_1));
        pop_stack(&stack_1);
    }
    printf("Stack is empty!\n");
    printf("'stack_' size: %i\n\n", stack_size(&stack_1));

    return 0;
}
