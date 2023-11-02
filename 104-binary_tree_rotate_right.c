#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a rightr rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	new = tree->left;

	if (new->right != NULL)
	{
		tree->left = new->right;
		new->right->parent = tree;
	}
	else
	{
		tree->left = NULL;
	}
	new->right = tree;
	new->parent = tree->parent;
	tree->parent = new;
	return (new);
}
