#include "binary_trees.h"
/**
 * depth - calculates the depth of a binary tree
 * @tree: pointer to the root node of tree
 * Return: depth of a binary tree
 */
size_t depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	return (depth(tree->parent) + 1);
}
/**
 * binary_depth - calls the depth function
 * @tree: pointer to root node
 * Return: depth of a binary tree
 */
size_t binary_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (depth(tree));
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	                             const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (binary_depth(first) < binary_depth(second))
		return (binary_trees_ancestor(first, second->parent));

	if (binary_depth(first) > binary_depth(second))
		return (binary_trees_ancestor(first->parent, second));

	return (binary_trees_ancestor(first->parent, second->parent));
}
