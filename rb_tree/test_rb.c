// === Source file: test_rb.c ===

#include "rb.h"
#include <time.h>

int main()
{
    srand(time(NULL));

    RBTree rb_tree;
    createRBTree(&rb_tree);

    for (int i = 0, value; i < 10; i++)
    {
        value = rand() % 20;
        insertRBTree(&rb_tree, value);
        printf("%i ", value);
    }
    printf("\n");

    printRBTree(&rb_tree, rb_tree.root, "in");
    printf("\n");

    printf("Height: %i\n", heightNodeRBTree(&rb_tree, rb_tree.root));
    printf("Min.: %i\n", minRBTree(&rb_tree, rb_tree.root)->key);
    printf("Max.: %i\n", maxRBTree(&rb_tree, rb_tree.root)->key);

    destroyRBTree(&rb_tree);
    return 0;
}
