// === Source file: test_rb.c ===

#include "rb.h"

int main()
{
    RBTree *rootRBTree = createRBTree();
    rootRBTree = newNode(10);
    destroyRBTree(rootRBTree);
    return 0;
}