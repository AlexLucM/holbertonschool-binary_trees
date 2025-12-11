#include "binary_trees.h"

/**
* tree_height - measures height of a binary tree
*
* @tree : pointer to the root node
*
* Return: height of the tree or 0 if NULL
*/
static size_t tree_height(const binary_tree_t *tree)

{
size_t left, right;

	if (tree == NULL)
	return (0);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	return ((left > right ? left : right) + 1);
}

/**
* binary_tree_balance - measures the balance factor of a binary tree
*
* @tree : pointer to the root node of the tree to measure the balance
* factor of
*
* Return: balance factor or 0 if tree is NULL
*/
int binary_tree_balance(const binary_tree_t *tree)

{
	if (tree == NULL)
	return (0);

	return (tree_height(tree->left) - tree_height(tree->right));
}
