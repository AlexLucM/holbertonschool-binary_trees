#include "binary_trees.h"

/**
* tree_height - eturns the height of a binary tree
*
* @tree: pointer to the tree
*
* Return: height of the tree, 0 if NULL or otherwise
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
* binary_tree_is_perfect - checks if a binary tree is perfect
*
* @tree: pointer to the root node of the tree
*
* Return: 1 if perfect, 0 if not or if tree is NULL
*/
int binary_tree_is_perfect(const binary_tree_t *tree)

{
	if (tree == NULL)
	return (0);

	if (tree->left == NULL && tree->right == NULL)
	return (1);

	if (tree->left == NULL || tree->right == NULL)
	return (0);

	if (tree_height(tree->left) != tree_height(tree->right))
	return (0);

	return (binary_tree_is_perfect(tree->left) &&
	binary_tree_is_perfect(tree->right));
}
