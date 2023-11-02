#include "binary_trees.h"
/**
 * binary_tree_s - calculates size of a binary tree
 * @tree: pointer to the root node
 * Return: numberof nodes in a tree
 */
size_t binary_tree_s(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_s(tree->left) + binary_tree_s(tree->right) + 1);
}
/**
 * binary_tree_complet - checks if the binary tree is complete
 * @tree: root node of the tree
 * @indx: index of a node
 * @nodes: size of the tree
 * Return: 1 if it's complete 0 otherwise
 */
int binary_tree_complet(const binary_tree_t *tree, int indx, int nodes)
{
	if (tree == NULL)
		return (1);

	if (indx >= nodes)
		return (0);

	return (binary_tree_complet(tree->left, (2 * indx) + 1, nodes)
		&& binary_tree_complet(tree->right, (2 * indx) + 2, nodes));
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if it's complete 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t nodes;

	if (tree == NULL)
		return (0);

	nodes = binary_tree_s(tree);

	return (binary_tree_complet(tree, 0, nodes));
}
