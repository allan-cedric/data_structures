// === Source file: test_linked_list.c ===

#include "linked_list.h"
#include <time.h>

int main()
{
    srand(time(NULL));

    linked_list_t list, list_1, list_2;

    printf("\nCreating 'list'...\n");
    init_list(&list);
    printf("'list' created successfully!\n\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Inserting %i at beginning...\n", i);
        push_front_list(i, &list);
    }

    printf("'list': ");
    print_list(&list);
    printf("\nChecking if the key 5 is in 'list'...\n");
    if (in_list(5, &list))
        printf("FOUND IT!\n\n");
    else
        printf("NO EXIST\n\n");

    int r;
    printf("Removing the first element...\n");
    pop_front_list(&r, &list);
    printf("Removing the last element...\n");
    pop_back_list(&r, &list);
    printf("Removing a element with key 5...\n");
    pop_list(5, &r, &list);
    printf("'list': ");
    print_list(&list);
    printf("\nChecking if the key 5 is in 'list'...\n");
    if (in_list(5, &list))
        printf("FOUND IT!\n\n");
    else
        printf("NO EXIST\n\n");

    printf("Destroying 'list'...\n\n");
    destroy_list(&list);

    for (int i = 0; i < 10; i++)
    {
        printf("Inserting %i at ending...\n", i);
        push_back_list(i, &list);
    }

    printf("'list': ");
    print_list(&list);

    printf("\nCreating 'list_1'...\n");
    init_list(&list_1);
    printf("'list_1' created successfully!\n\n");

    for (int i = 0, e; i < 10; i++)
    {
        e = rand() % 20;
        printf("Inserting %i in order...\n", e);
        push_inorder_list(e, &list_1);
    }

    printf("'list_1': ");
    print_list(&list_1);

    printf("\nConcatenating 'list' with 'list_1'...\n");
    concatenate_lists(&list, &list_1);

    printf("'list': ");
    print_list(&list);

    printf("\nCopying 'list' to 'list_2'...\n");
    copy_list(&list, &list_2);

    printf("'list_2': ");
    print_list(&list_2);

    printf("\nDestroying all lists!\n\n");
    destroy_list(&list);
    destroy_list(&list_2);

    return 0;
}