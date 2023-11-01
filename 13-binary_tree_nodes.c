#include "binary_trees.h"
/**
 * binary_tree_n - checks whether a root is node
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: 1 if it's a node
 */
int binary_tree_n(const binary_tree_t *tree)
{
	int i = 0;

	if (tree != NULL && (tree->left != NULL || tree->right != NULL))
		i = 1;

	return (i);
}
/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes_l = 0;
	size_t nodes_r = 0;

	if (binary_tree_n(tree) == 1)
	{
		nodes_l = binary_tree_nodes(tree->left);
		nodes_r = binary_tree_nodes(tree->right);
		return ((nodes_l + nodes_r) + 1);
	}
	return (0);
}
