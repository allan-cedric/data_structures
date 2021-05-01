// === Source file: rb.c ===

#include "rb.h"

RBTree *createRBTree()
{
    return NULL;
}

int emptyRBTree(RBTree *root)
{
    return (root == NULL);
}

RBTree *newNode(int key)
{
    RBTree *new = (RBTree *)malloc(sizeof(RBTree));

    if (!new)
    {
        fprintf(stderr, "Memory allocation error!\n");
        exit(1);
    }

    new->key = key;
    new->color = RED;

    new->left = NULL;
    new->right = NULL;
    new->parent = NULL;

    return new;
}

RBTree *destroyRBTree(RBTree *root)
{
    if (root)
    {
        destroyRBTree(root->left);
        destroyRBTree(root->right);
        free(root);
    }
    return NULL;
}

void printRBTree(RBTree *root, const char *op)
{
    if (root)
    {
        if (!strcmp(op, "pre"))
        {
            printf("%i ", root->key);
            printRBTree(root->left, op);
            printRBTree(root->right, op);
        }
        else if (!strcmp(op, "in"))
        {
            printRBTree(root->left, op);
            printf("%i ", root->key);
            printRBTree(root->right, op);
        }
        else if (!strcmp(op, "pos"))
        {
            printRBTree(root->left, op);
            printRBTree(root->right, op);
            printf("%i ", root->key);
        }
        else
            fprintf(stderr, "Invalid option to print a Red-Black Tree!\n");
    }
}

RBTree *searchRBTree(RBTree *root, int key)
{
    if (!root || root->key == key)
        return root;

    if (key < root->key)
        return searchRBTree(root->left, key);
    return searchRBTree(root->right, key);
}

RBTree *minRBTree(RBTree *root)
{
    if (!root || !root->left)
        return root;
    return minRBTree(root->left);
}

RBTree *maxRBTree(RBTree *root)
{
    if (!root || !root->right)
        return root;
    return maxRBTree(root->right);
}

RBTree *LLRotationRBTree(RBTree *root, RBTree *node_x)
{
    // === Filho do node_y => Filho do node_x ===
    RBTree *node_y = node_x->left;
    node_x->left = node_y->right;
    if (node_x->left)
        node_x->left->parent = node_x;
    node_y->parent = node_x->parent;

    // === Pai do node_x => Pai do node_y ===
    if (!node_x->parent)
        root = node_y;
    else if (node_x == node_x->parent->left)
        node_x->parent->left = node_y;
    else
        node_x->parent->right = node_y;

    // === Pai antigo do node_x => Pai novo (node_y) do node_x ===
    node_y->right = node_x;
    node_x->parent = node_y;

    return root;
}

RBTree *RRRotationRBTree(RBTree *root, RBTree *node_x)
{
    // === Filho do node_y => Filho do node_x ===
    RBTree *node_y = node_x->right;
    node_x->right = node_y->left;
    if (node_x->right)
        node_x->right->parent = node_x;
    node_y->parent = node_x->parent;

    // === Pai do node_x => Pai do node_y ===
    if (!node_x->parent)
        root = node_y;
    else if (node_x == node_x->parent->left)
        node_x->parent->left = node_y;
    else
        node_x->parent->right = node_y;

    // === Pai antigo do node_x => Pai novo (node_y) do node_x ===
    node_y->left = node_x;
    node_x->parent = node_y;

    return root;
}
