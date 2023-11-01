#include "binary_trees.h"
/**
 * binary_tree_f - checks if a root is a leaf
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if it's a leaf
 */
int binary_tree_f(const binary_tree_t *tree)
{
	int i = 0;

	if (tree->left == NULL && tree->right == NULL)
		i = 1;

	return (i);
}
/**
 * binary_tree_p - checks if root is a parent
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if it's a parent
 */
int binary_tree_p(const binary_tree_t *tree)
{
	int j = 0;

	if (tree->left != NULL || tree->right != NULL)
		j = 1;

	return (j);
}
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if it's full 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (binary_tree_f(tree) == 1)
		return (1);
	if (binary_tree_p(tree) == 1)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	return (0);
}
