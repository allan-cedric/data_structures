// === Source file: rb.c ===

#include "rb.h"

void createRBTree(RBTree *rb)
{
    rb->nil = newNil();
    rb->root = rb->nil;
}

int emptyRBTree(RBTree *rb)
{
    return (rb->root == rb->nil);
}

RBTreeNode *newNil()
{
    RBTreeNode *new = (RBTreeNode *)malloc(sizeof(RBTreeNode));

    if (!new)
    {
        fprintf(stderr, "Memory allocation error!\n");
        exit(1);
    }

    new->key = 0;
    new->color = BLACK;

    new->left = NULL;
    new->right = NULL;
    new->parent = NULL;

    return new;
}

RBTreeNode *newNode(RBTree *rb, int key)
{
    RBTreeNode *new = (RBTreeNode *)malloc(sizeof(RBTreeNode));

    if (!new)
    {
        fprintf(stderr, "Memory allocation error!\n");
        exit(1);
    }

    new->key = key;
    new->color = RED;

    new->left = rb->nil;
    new->right = rb->nil;
    new->parent = rb->nil;

    return new;
}

RBTreeNode *destroyNodesRBTree(RBTree *rb, RBTreeNode *root)
{
    if (root != rb->nil)
    {
        destroyNodesRBTree(rb, root->left);
        destroyNodesRBTree(rb, root->right);
        free(root);
    }
    return NULL;
}

void destroyRBTree(RBTree *rb)
{
    rb->root = destroyNodesRBTree(rb, rb->root);
    free(rb->nil);
}

void printRBTree(RBTree *rb, RBTreeNode *root, const char *op)
{
    if (root != rb->nil)
    {
        if (!strcmp(op, "pre"))
        {
            printf("(%i, %c)", root->key, root->color == RED ? 'R' : 'B');
            printRBTree(rb, root->left, op);
            printRBTree(rb, root->right, op);
        }
        else if (!strcmp(op, "in"))
        {
            printRBTree(rb, root->left, op);
            printf("(%i, %c)", root->key, root->color == RED ? 'R' : 'B');
            printRBTree(rb, root->right, op);
        }
        else if (!strcmp(op, "pos"))
        {
            printRBTree(rb, root->left, op);
            printRBTree(rb, root->right, op);
            printf("(%i, %c)", root->key, root->color == RED ? 'R' : 'B');
        }
        else
            fprintf(stderr, "Invalid option to print a Red-Black Tree!\n");
    }
}

RBTreeNode *searchRBTree(RBTree *rb, RBTreeNode *root, int key)
{
    if ((root == rb->nil) || (root->key == key))
        return root;

    if (key < root->key)
        return searchRBTree(rb, root->left, key);
    return searchRBTree(rb, root->right, key);
}

RBTreeNode *minRBTree(RBTree *rb, RBTreeNode *root)
{
    if ((root == rb->nil) || (root->left == rb->nil))
        return root;
    return minRBTree(rb, root->left);
}

RBTreeNode *maxRBTree(RBTree *rb, RBTreeNode *root)
{
    if ((root == rb->nil) || (root->right == rb->nil))
        return root;
    return maxRBTree(rb, root->right);
}

void LLRotationRBTree(RBTree *rb, RBTreeNode *node_x)
{
    // === Filho do node_y => Filho do node_x ===
    RBTreeNode *node_y = node_x->left;
    node_x->left = node_y->right;
    if (node_x->left != rb->nil)
        node_x->left->parent = node_x;

    // === Pai do node_x => Pai do node_y ===
    node_y->parent = node_x->parent;
    if (node_x->parent == rb->nil)
        rb->root = node_y;
    else if (node_x == node_x->parent->left)
        node_x->parent->left = node_y;
    else
        node_x->parent->right = node_y;

    // === Pai antigo do node_x => Pai novo (node_y) do node_x ===
    node_y->right = node_x;
    node_x->parent = node_y;
}

void RRRotationRBTree(RBTree *rb, RBTreeNode *node_x)
{
    // === Filho do node_y => Filho do node_x ===
    RBTreeNode *node_y = node_x->right;
    node_x->right = node_y->left;
    if (node_x->right != rb->nil)
        node_x->right->parent = node_x;

    // === Pai do node_x => Pai do node_y ===
    node_y->parent = node_x->parent;
    if (node_x->parent == rb->nil)
        rb->root = node_y;
    else if (node_x == node_x->parent->left)
        node_x->parent->left = node_y;
    else
        node_x->parent->right = node_y;

    // === Pai antigo do node_x => Pai novo (node_y) do node_x ===
    node_y->left = node_x;
    node_x->parent = node_y;
}

void insertRBTree(RBTree *rb, int key)
{
    RBTreeNode *node_y = rb->nil, *node_x = rb->root;
    while (node_x != rb->nil)
    {
        node_y = node_x;
        if (key == node_x->key)
            return;
        node_x = (key < node_x->key ? node_x->left : node_x->right);
    }
    RBTreeNode *new = newNode(rb, key);
    new->parent = node_y;
    if (node_y == rb->nil)
        rb->root = new;
    else if (key < node_y->key)
        node_y->left = new;
    else
        node_y->right = new;

    insertFixUpRBTree(rb, new);
}

void insertFixUpRBTree(RBTree *rb, RBTreeNode *new)
{
    while (new->parent->color == RED)
    {
        if (new->parent == new->parent->parent->left)
        {
            RBTreeNode *node_y = new->parent->parent->right;
            if (node_y->color == RED) // Case 1
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
                    RRRotationRBTree(rb, new);
                }
                // Case 3
                new->parent->color = BLACK;
                new->parent->parent->color = RED;
                LLRotationRBTree(rb, new->parent->parent);
            }
        }
        else
        {
            RBTreeNode *node_y = new->parent->parent->left;
            if (node_y->color == RED) // Case 1
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
                    LLRotationRBTree(rb, new);
                }
                // Case 3
                new->parent->color = BLACK;
                new->parent->parent->color = RED;
                RRRotationRBTree(rb, new->parent->parent);
            }
        }
    }

    rb->root->color = BLACK;
}

int heightNodeRBTree(RBTree *rb, RBTreeNode *root)
{
    if (root == rb->nil)
        return -1;
    int heightLeft = heightNodeRBTree(rb, root->left);
    int heightRight = heightNodeRBTree(rb, root->right);
    if (heightLeft > heightRight)
        return heightLeft + 1;
    return heightRight + 1;
}
