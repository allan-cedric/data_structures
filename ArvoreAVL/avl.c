/* 
   Source file : 'avl.c'
   Escrito por : Allan Cedric G.B. Alves da Silva
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#include "avl.h"

int emptyAVL(AVL *root)
{
	return (root == NULL);
}

AVL *createAVL()
{
	return NULL;
}

AVL *newNode(int key)
{
	AVL *node = malloc(sizeof(AVL));
	if (!node)
	{
		perror("Not enough memory to create a new node! - 'newNode()'");
		exit(1);
	}
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node->key = key;
	return node;
}

AVL *insertNodeAVL(AVL *root, int key)
{
	if (!root)
		return newNode(key);
	if (key < root->key)
	{
		root->left = insertNodeAVL(root->left, key);
		root->left->parent = root;
	}
	else if (key > root->key)
	{
		root->right = insertNodeAVL(root->right, key);
		root->right->parent = root;
	}
	return root;
}

void printAVL(AVL *root, const char *op)
{
	if (!root)
		return;

	/* PRE-ORDER */
	if (!strcmp(op, "pre"))
	{
		printf("%i ", root->key);
		printAVL(root->left, "pre");
		printAVL(root->right, "pre");
	}
	/* IN-ORDER */
	else if (!strcmp(op, "in"))
	{
		printAVL(root->left, "in");
		printf("%i ", root->key);
		printAVL(root->right, "in");
	}
	/* POS-ORDER */
	else if (!strcmp(op, "pos"))
	{
		printAVL(root->left, "pos");
		printAVL(root->right, "pos");
		printf("%i ", root->key);
	}
	else
		perror("Not a valid argument for 'op' - 'printAVL()'");
}

AVL *destroyAVL(AVL *root)
{
	if (!root)
		return root;

	destroyAVL(root->left);
	destroyAVL(root->right);
	free(root);
	root = NULL;
	return root;
}

AVL *searchAVL(AVL *root, int key)
{
	if (!root || root->key == key)
		return root;

	if (key > root->key)
		return (searchAVL(root->right, key));
	return (searchAVL(root->left, key));
}

AVL *minKeyAVL(AVL *root)
{
	if (!root || !root->left)
		return root;
	return minKeyAVL(root->left);
}

AVL *maxKeyAVL(AVL *root)
{
	if (!root || !root->right)
		return root;
	return maxKeyAVL(root->right);
}

int numNodesAVL(AVL *root)
{
	if (!root)
		return 0;
	return (numNodesAVL(root->left) + numNodesAVL(root->right) + 1);
}

int heightAVL(AVL *root)
{
	if (!root)
		return -1;
	int heightLeft = heightAVL(root->left);
	int heightRight = heightAVL(root->right);
	if (heightRight > heightLeft)
		return heightRight + 1;
	return heightLeft + 1;
}

AVL *removeNodeAVL(AVL *root, int key)
{
	AVL *nodeToRemove = searchAVL(root, key);
	if (!nodeToRemove)
		return root;
	if (!nodeToRemove->left)
		root = transplantSubtreeAVL(root, nodeToRemove, nodeToRemove->right);
	else if (!nodeToRemove->right)
		root = transplantSubtreeAVL(root, nodeToRemove, nodeToRemove->left);
	else
	{
		AVL *nodeSucessor = minKeyAVL(nodeToRemove->right);

		if (nodeSucessor->parent != nodeToRemove)
		{
			root = transplantSubtreeAVL(root, nodeSucessor, nodeSucessor->right);
			nodeSucessor->right = nodeToRemove->right;
			nodeSucessor->right->parent = nodeSucessor;
		}
		root = transplantSubtreeAVL(root, nodeToRemove, nodeSucessor);
		nodeSucessor->left = nodeToRemove->left;
		nodeSucessor->left->parent = nodeSucessor;
	}
	free(nodeToRemove);
	nodeToRemove = NULL;
	return root;
}

AVL *transplantSubtreeAVL(AVL *root, AVL *node, AVL *nodeChild)
{
	if (!node->parent)
		root = nodeChild;
	else if (node == node->parent->left)
		node->parent->left = nodeChild;
	else
		node->parent->right = nodeChild;
	if (nodeChild)
		nodeChild->parent = node->parent;
	return root;
}
