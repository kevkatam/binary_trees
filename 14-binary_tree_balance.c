#include "binary_trees.h"
/**
 * binary_tree_b - finds height of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balnce factor
 */
size_t binary_tree_b(const binary_tree_t *tree)
{
	size_t left_h;
	size_t right_h;

	if (tree == NULL)
		return (0);

	left_h = binary_tree_b(tree->left);
	right_h = binary_tree_b(tree->right);

	if (left_h > right_h)
		return (left_h + 1);
	return (right_h + 1);
}
/**
 * binary_tree_h - function that calls binary_tree_b to get the height
 * @tree: pointer to the root node of the tree
 * Return: height of the tree
 */
size_t binary_tree_h(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);
	return (binary_tree_b(tree) - 1);
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((binary_tree_h(tree->left)) - (binary_tree_h(tree->right)));
}
