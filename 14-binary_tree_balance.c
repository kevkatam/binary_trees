#include "binary_trees.h"
/**
 * binary_tree_b - finds balnce factor
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balnce factor
 */
int binary_tree_b(const binary_tree_t *tree)
{
	int b;

	if (tree == NULL)
		return (0);

	b = (binary_tree_b(tree->left) - binary_tree_b(tree->right)) + 1;

	return (b);
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: measures the balance factor of a binary tree
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_b(tree) - 1);
}
