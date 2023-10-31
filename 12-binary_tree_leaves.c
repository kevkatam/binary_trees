#include "binary_trees.h"
/**
 * binary_tree_l - checks if a node is a leaf
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: 1 if it's a leaf
 */
int binary_tree_l(const binary_tree_t *tree)
{
	int i = 0;

	if (tree->left == NULL && tree->right == NULL)
		i = 1;
	return (i);
}
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_l(tree) == 1)
		return (1);

	return ((binary_tree_leaves(tree->left)) + (binary_tree_leaves(tree->right)));
}
