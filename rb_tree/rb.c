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
            printf("(%i, %c)", root->key, root->color == RED ? 'R' : 'B');
            printRBTree(root->left, op);
            printRBTree(root->right, op);
        }
        else if (!strcmp(op, "in"))
        {
            printRBTree(root->left, op);
            printf("(%i, %c)", root->key, root->color == RED ? 'R' : 'B');
            printRBTree(root->right, op);
        }
        else if (!strcmp(op, "pos"))
        {
            printRBTree(root->left, op);
            printRBTree(root->right, op);
            printf("(%i, %c)", root->key, root->color == RED ? 'R' : 'B');
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

RBTree *insertRBTree(RBTree *root, int key)
{
    RBTree *node_y = NULL, *node_x = root;
    while (node_x)
    {
        node_y = node_x;
        if (key == node_x->key)
            return root;
        node_x = (key < node_x->key ? node_x->left : node_x->right);
    }
    RBTree *new = newNode(key);
    new->parent = node_y;
    if (!node_y)
        root = new;
    else if (key < node_y->key)
        node_y->left = new;
    else
        node_y->right = new;

    return insertFixUpRBTree(root, new);
}

RBTree *insertFixUpRBTree(RBTree *root, RBTree *new)
{
    while (new->parent && new->parent->color == RED)
    {
        if (new->parent == new->parent->parent->left)
        {
            RBTree *node_y = new->parent->parent->right;
            if (node_y && node_y->color == RED) // Case 1
            {
                new->parent->color = BLACK;
                node_y->color = BLACK;
                new->parent->parent->color = RED;
                new = new->parent->parent;
            }
            else
            {
                if (new == new->parent->right) // Case 2
                {
                    new = new->parent;
                    root = RRRotationRBTree(root, new);
                }
                // Case 3
                new->parent->color = BLACK;
                new->parent->parent->color = RED;
                root = LLRotationRBTree(root, new->parent->parent);
            }
        }
        else
        {
            RBTree *node_y = new->parent->parent->left;
            if (node_y && node_y->color == RED) // Case 1
            {
                new->parent->color = BLACK;
                node_y->color = BLACK;
                new->parent->parent->color = RED;
                new = new->parent->parent;
            }
            else
            {
                if (new == new->parent->left) // Case 2
                {
                    new = new->parent;
                    root = LLRotationRBTree(root, new);
                }
                // Case 3
                new->parent->color = BLACK;
                new->parent->parent->color = RED;
                root = RRRotationRBTree(root, new->parent->parent);
            }
        }
    }

    root->color = BLACK;
    return root;
}

int heightNodeRBTree(RBTree *root)
{
    if (!root)
        return -1;
    int heightLeft = heightNodeRBTree(root->left);
    int heightRight = heightNodeRBTree(root->right);
    if (heightLeft > heightRight)
        return heightLeft + 1;
    return heightRight + 1;
}
