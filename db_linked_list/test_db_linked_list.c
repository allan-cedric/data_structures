// === Source file: test_db_linked_list.c ===

#include "db_linked_list.h"
#include <time.h>

int main()
{
    srand(time(NULL));

    db_linked_list_t db_list1, db_list2, db_list3;

    printf("\nCreating 'db_list1'...\n");
    init_db_list(&db_list1);
    printf("'db_list1' created successfully!\n\n");

    printf("\nCreating 'db_list2'...\n");
    init_db_list(&db_list2);
    printf("'db_list2' created successfully!\n\n");

    printf("\nCreating 'db_list3'...\n");
    init_db_list(&db_list3);
    printf("'db_list3' created successfully!\n\n\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Inserting %i at beginning...\n", i);
        push_front_db_list(i, &db_list1);
    }

    printf("'db_list1': ");
    print_db_list(&db_list1);
    printf("\nChecking if the key 5 is in 'db_list1'...\n");
    if (in_db_list(5, &db_list1))
        printf("FOUND IT!\n\n");
    else
        printf("NO EXIST\n\n");

    int r;
    printf("Removing the first element...\n");
    pop_front_db_list(&r, &db_list1);
    printf("Removing the last element...\n");
    pop_back_db_list(&r, &db_list1);
    printf("Removing a 4th element...\n");
    for (int i = 0; i < 3; i++)
        add_now_db_list(&db_list1);
    pop_now_db_list(&r, &db_list1);
    printf("'db_list1': ");
    print_db_list(&db_list1);
    printf("\nChecking if the key 5 is in 'db_list1'...\n");
    if (in_db_list(5, &db_list1))
        printf("FOUND IT!\n\n");
    else
        printf("NO EXIST\n\n");

    printf("Destroying 'db_list1'...\n\n");
    destroy_db_list(&db_list1);
    init_db_list(&db_list1);

    for (int i = 0; i < 10; i++)
    {
        printf("Inserting %i at ending...\n", i);
        push_back_db_list(i, &db_list1);
    }

    printf("'db_list1': ");
    print_db_list(&db_list1);
    printf("\n");

    for (int i = 0, e; i < 10; i++)
    {
        e = rand() % 20;
        printf("Inserting %i in order...\n", e);
        push_inorder_db_list(e, &db_list2);
    }

    printf("'db_list2': ");
    print_db_list(&db_list2);

    printf("\nConcatenating 'db_list1' with 'db_list2'...\n");
    concatenate_db_lists(&db_list1, &db_list2);

    printf("'db_list1': ");
    print_db_list(&db_list1);

    printf("\nCopying 'db_list1' to 'db_list3'...\n");
    copy_db_list(&db_list1, &db_list3);

    printf("'db_list3': ");
    print_db_list(&db_list3);

    init_db_list(&db_list2);
    printf("\nMerging 'db_list3' to 'db_list1'...\n");
    merge_db_lists(&db_list1, &db_list3, &db_list2);

    printf("'db_list2': ");
    print_db_list(&db_list2);

    printf("\nDestroying all lists!\n\n");
    destroy_db_list(&db_list1);
    destroy_db_list(&db_list2);
    destroy_db_list(&db_list3);

    return 0;
}
