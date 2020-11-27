/* 
   Source file : 'bst.c'
   Escrito por : Allan Cedric G.B. Alves da Silva
   Profile : Aluno de graduação do curso de Ciência da Computação (UFPR)
   GRR : 20190351
*/

#include "bst.h"

int emptyBST(BST *root)
{
	return (root == NULL);
}

BST *createBST()
{
	return NULL;
}

BST *newNode(int key)
{
	BST *node = malloc(sizeof(BST));
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

BST *insertNodeBST(BST *root, int key)
{
	if (!root)
		return newNode(key);
	if (key < root->key)
	{
		root->left = insertNodeBST(root->left, key);
		root->left->parent = root;
	}
	else
	{
		root->right = insertNodeBST(root->right, key);
		root->right->parent = root;
	}
	return root;
}

void printBST(BST *root, const char *op)
{
	if (!root)
		return;

	/* PRE-ORDER */
	if (!strcmp(op, "pre"))
	{
		printf("%i ", root->key);
		printBST(root->left, "pre");
		printBST(root->right, "pre");
	}
	/* IN-ORDER */
	else if (!strcmp(op, "in"))
	{
		printBST(root->left, "in");
		printf("%i ", root->key);
		printBST(root->right, "in");
	}
	/* POS-ORDER */
	else if (!strcmp(op, "pos"))
	{
		printBST(root->left, "pos");
		printBST(root->right, "pos");
		printf("%i ", root->key);
	}
	else
		perror("Not a valid argument for 'op' - 'printBST()'");
}

BST *destroyBST(BST *root)
{
	if (!root)
		return root;

	destroyBST(root->left);
	destroyBST(root->right);
	free(root);
	root = NULL;
	return root;
}

BST *searchBST(BST *root, int key)
{
	if (!root || root->key == key)
		return root;

	if (key >= root->key)
		return (searchBST(root->right, key));
	return (searchBST(root->left, key));
}

BST *minKeyBST(BST *root)
{
	if (!root || !root->left)
		return root;
	return minKeyBST(root->left);
}

BST *maxKeyBST(BST *root)
{
	if (!root || !root->right)
		return root;
	return maxKeyBST(root->right);
}

int numNodesBST(BST *root)
{
	if (!root)
		return 0;
	return (numNodesBST(root->left) + numNodesBST(root->right) + 1);
}

int heightBST(BST *root)
{
	if (!root)
		return 0;
	int heightLeft = heightBST(root->left);
	int heightRight = heightBST(root->right);
	if (heightRight > heightLeft)
		return heightRight + 1;
	return heightLeft + 1;
}

BST *removeNodeBST(BST *root, int key)
{
	BST *nodeToRemove = searchBST(root, key);
	if (!nodeToRemove)
		return root;
	if (!nodeToRemove->left)
		root = transplantSubtreeBST(root, nodeToRemove, nodeToRemove->right);
	else if (!nodeToRemove->right)
		root = transplantSubtreeBST(root, nodeToRemove, nodeToRemove->left);
	else
	{
		BST *nodeSucessor = minKeyBST(nodeToRemove->right);

		if (nodeSucessor->parent != nodeToRemove)
		{
			root = transplantSubtreeBST(root, nodeSucessor, nodeSucessor->right);
			nodeSucessor->right = nodeToRemove->right;
			nodeSucessor->right->parent = nodeSucessor;
		}
		root = transplantSubtreeBST(root, nodeToRemove, nodeSucessor);
		nodeSucessor->left = nodeToRemove->left;
		nodeSucessor->left->parent = nodeSucessor;
	}
	free(nodeToRemove);
	nodeToRemove = NULL;
	return root;
}

BST *transplantSubtreeBST(BST *root, BST *node, BST *nodeChild)
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
