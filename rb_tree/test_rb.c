// === Source file: test_rb.c ===

#include "rb.h"

int main()
{
    printf("Creating a RB Tree...\n");
    RBTree rb_tree;
    createRBTree(&rb_tree);
    printf("RB Tree created successfully!\n\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Inserting %i...\n", i);
        insertRBTree(&rb_tree, i);
    }
    printf("\n");

    printf("preOrder: ");
    printRBTree(&rb_tree, rb_tree.root, "pre");
    printf("\n\n");
    printf("inOrder: ");
    printRBTree(&rb_tree, rb_tree.root, "in");
    printf("\n\n");
    printf("posOrder: ");
    printRBTree(&rb_tree, rb_tree.root, "pos");
    printf("\n\n");

    printf("Height: %i\n", heightNodeRBTree(&rb_tree, rb_tree.root));
    printf("Min.: %i\n", minRBTree(&rb_tree, rb_tree.root)->key);
    printf("Max.: %i\n\n", maxRBTree(&rb_tree, rb_tree.root)->key);

    int remove = 5;
    printf("Deleting %i...\n", remove);
    deleteRBTree(&rb_tree, remove);
    printf("inOrder: ");
    printRBTree(&rb_tree, rb_tree.root, "in");
    printf("\n\n");

    remove = 8;
    printf("Deleting %i...\n", remove);
    deleteRBTree(&rb_tree, remove);
    printf("inOrder: ");
    printRBTree(&rb_tree, rb_tree.root, "in");
    printf("\n\n");

    remove = 2;
    printf("Deleting %i...\n", remove);
    deleteRBTree(&rb_tree, remove);
    printf("inOrder: ");
    printRBTree(&rb_tree, rb_tree.root, "in");
    printf("\n\n");

    printf("Destroying the RB Tree...\n");
    destroyRBTree(&rb_tree);
    printf("RB Tree destroyed successfully!\n");
    return 0;
}
