/* 
   Source file : 'bst.c'
   Escrito por : Allan Cedric G.B. Alves da Silva
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#include "bst.h"

int emptyBST(BST *bst)
{
	return (bst->root == NULL);
}

int createBST(BST *bst)
{
	bst->root = NULL;
	return 1;
}

int insertRootBST(BST *bst, int value)
{
	if (!emptyBST(bst))
	{
		perror("This BST already has a ROOT! - 'insertRootBST()'");
		return 0;
	}

	bst->root = malloc(sizeof(node_t));

	if (!bst->root)
	{
		perror("Not enough memory to create a ROOT! - 'insertRootBST()'");
		exit(1);
	}

	bst->root->left = NULL;
	bst->root->right = NULL;
	bst->root->parent = NULL;
	bst->root->value = value;

	return 1;
}

int insertNodeBST(BST *bst, int value)
{
	if (emptyBST(bst))
		return insertRootBST(bst, value);

	node_t *newNode = malloc(sizeof(node_t));

	if (!newNode)
	{
		perror("Not enough memory to insert a new NODE! - 'insertNodeBST()'");
		exit(1);
	}

	node_t *current = bst->root;
	node_t *before = NULL;

	while (current != NULL)
	{
		before = current;
		if (value >= current->value)
			current = current->right;
		else
			current = current->left;
	}

	if (value >= before->value)
		before->right = newNode;
	else
		before->left = newNode;

	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = before;
	newNode->value = value;

	return 1;
}

void printBST(node_t *node, const char *op)
{
	if (!node)
		return;

	/* PRE-ORDER */
	if (!strcmp(op, "pre"))
	{
		printf("%i ", node->value);
		printBST(node->left, "pre");
		printBST(node->right, "pre");
	}
	/* IN-ORDER */
	else if (!strcmp(op, "in"))
	{
		printBST(node->left, "in");
		printf("%i ", node->value);
		printBST(node->right, "in");
	}
	/* POS-ORDER */
	else if (!strcmp(op, "pos"))
	{
		printBST(node->left, "pos");
		printBST(node->right, "pos");
		printf("%i ", node->value);
	}
	else
		perror("Not a valid argument for 'op' - 'printBST()'");
}

void destroyBST(BST *bst, node_t *node)
{
	if (!node || emptyBST(bst))
		return;

	destroyBST(bst, node->left);
	destroyBST(bst, node->right);
	free(node);
	node = NULL;
}

node_t *searchBST(node_t *node, int value)
{
	if (!node || node->value == value)
		return node;

	if (value >= node->value)
		return (searchBST(node->right, value));
	return (searchBST(node->left, value));
}

node_t *minValueBST(node_t *node)
{
	if (!node)
		return node;
	while (node->left)
		node = node->left;
	return node;
}

node_t *maxValueBST(node_t *node)
{
	if (!node)
		return node;
	while (node->right)
		node = node->right;
	return node;
}

int numNodesBST(node_t *node)
{
	if (!node)
		return 0;
	return (numNodesBST(node->left) + numNodesBST(node->right) + 1);
}

int heightBST(node_t *node)
{
	if (!node)
		return 0;
	int heightLeft = heightBST(node->left);
	int heightRight = heightBST(node->right);
	if (heightRight > heightLeft)
		return heightRight + 1;
	return heightLeft + 1;
}

int removeNodeBST(BST *bst, int value)
{
	node_t *nodeToRemove = searchBST(bst->root, value);
	if (!nodeToRemove)
		return 0;
	if (!nodeToRemove->left)
	{
		transplantSubtreeBST(nodeToRemove, nodeToRemove->right);
		free(nodeToRemove);
	}
	else if (!nodeToRemove->right)
	{
		transplantSubtreeBST(nodeToRemove, nodeToRemove->left);
		free(nodeToRemove);
	}
	else
	{
		node_t *nodeSucessor = minValueBST(nodeToRemove->right);
		nodeToRemove->value = nodeSucessor->value;
		transplantSubtreeBST(nodeSucessor, nodeSucessor->right);
		free(nodeSucessor);
		nodeSucessor = NULL;
	}
	nodeToRemove = NULL;
	return 1;
}

int transplantSubtreeBST(node_t *node, node_t *nodeChild)
{
	if (node->value < node->parent->value)
		node->parent->left = nodeChild;
	else
		node->parent->right = nodeChild;
	if (nodeChild)
		nodeChild->parent = node->parent;
	return 1;
}
