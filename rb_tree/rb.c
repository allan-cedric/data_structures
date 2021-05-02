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

void transplantSubtreeRBTree(RBTree *rb, RBTreeNode *node_u, RBTreeNode *node_v)
{
    if (node_u->parent == rb->nil)
        rb->root = node_v;
    else if (node_u == node_u->parent->left)
        node_u->parent->left = node_v;
    else
        node_u->parent->right = node_v;
    node_v->parent = node_u->parent;
}

void deleteRBTree(RBTree *rb, int key)
{
    RBTreeNode *node_z = searchRBTree(rb, rb->root, key);
    if (node_z == rb->nil)
        return;

    RBTreeNode *node_y = node_z, *node_x;
    rbtree_node_color node_y_origin_color = node_y->color;

    if (node_z->left == rb->nil)
    {
        node_x = node_z->right;
        transplantSubtreeRBTree(rb, node_z, node_z->right);
    }
    else if (node_z->right == rb->nil)
    {
        node_x = node_z->left;
        transplantSubtreeRBTree(rb, node_z, node_z->left);
    }
    else
    {
        node_y = minRBTree(rb, node_z->right);
        node_y_origin_color = node_y->color;
        node_x = node_y->right;
        if (node_y->parent == node_z)
            node_x->parent = node_y;
        else
        {
            transplantSubtreeRBTree(rb, node_y, node_y->right);
            node_y->right = node_z->right;
            node_y->right->parent = node_y;
        }
        transplantSubtreeRBTree(rb, node_z, node_y);
        node_y->left = node_z->left;
        node_y->left->parent = node_y;
        node_y->color = node_z->color;
    }
    if (node_y_origin_color == BLACK)
        deleteFixUpRBTree(rb, node_x);
    free(node_z);
}

void deleteFixUpRBTree(RBTree *rb, RBTreeNode *node_x)
{
    RBTreeNode *node_w;
    while ((node_x != rb->root) && (node_x->color == BLACK))
    {
        if (node_x == node_x->parent->left)
        {
            node_w = node_x->parent->right;
            if (node_w->color == RED) // Case 1
            {
                node_w->color = BLACK;
                node_x->parent->color = RED;
                RRRotationRBTree(rb, node_x->parent);
                node_w = node_x->parent->right;
            }
            if ((node_w->left->color == BLACK) && (node_w->right->color == BLACK)) // Case 2
            {
                node_w->color = RED;
                node_x = node_x->parent;
            }
            else
            {
                if (node_w->right->color == BLACK) // Case 3
                {
                    node_w->left->color = BLACK;
                    node_w->color = RED;
                    LLRotationRBTree(rb, node_w);
                    node_w = node_x->parent->right;
                }
                // Case 4
                node_w->color = node_x->parent->color;
                node_x->parent->color = BLACK;
                node_w->right->color = BLACK;
                RRRotationRBTree(rb, node_x->parent);
                node_x = rb->root;
            }
        }
        else
        {
            node_w = node_x->parent->left;
            if (node_w->color == RED) // Case 1
            {
                node_w->color = BLACK;
                node_x->parent->color = RED;
                LLRotationRBTree(rb, node_x->parent);
                node_w = node_x->parent->left;
            }
            if ((node_w->left->color == BLACK) && (node_w->right->color == BLACK)) // Case 2
            {
                node_w->color = RED;
                node_x = node_x->parent;
            }
            else
            {
                if (node_w->left->color == BLACK) // Case 3
                {
                    node_w->left->color = BLACK;
                    node_w->color = RED;
                    RRRotationRBTree(rb, node_w);
                    node_w = node_x->parent->left;
                }
                // Case 4
                node_w->color = node_x->parent->color;
                node_x->parent->color = BLACK;
                node_w->left->color = BLACK;
                LLRotationRBTree(rb, node_x->parent);
                node_x = rb->root;
            }
        }
    }
    node_x->color = BLACK;
}
