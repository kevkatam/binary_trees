#include "binary_trees.h"
/**
 * binary_tree_d - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node
 */
size_t binary_tree_d(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	return (binary_tree_d(tree->parent) + 1);
}
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_d(tree));
}
