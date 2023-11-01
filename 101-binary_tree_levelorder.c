#include "binary_trees.h"
/**
 * binary_tree_levelorder - goes through a binary tree using
 *  level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: no return
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h;
	size_t i;

	if (tree == NULL || func == NULL)
		return;
	h = heightt(tree);
	for (i = 1; i <= h; i++)
		print_l(tree, i, func);
}

/**
 * heightt - calculates height of a binary tree
 * @tree: pointer to the root node
 * Return: height of a binary tree
 */
size_t heightt(const binary_tree_t *tree)
{
	size_t left_h = 0;
	size_t right_h = 0;

	if (tree == NULL)
		return (0);

	left_h = heightt(tree->left);
	right_h = heightt(tree->right);

	if (left_h > right_h)
		return (left_h + 1);
	return (right_h + 1);
}
/**
 * print_l - prints nodes at a level
 * @tree: pointer to the root node
 * @l: level of nodes
 * @func: function to call o each node
 * Return: no return
 */
void print_l(const binary_tree_t *tree, int l, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (l == 1)
		func(tree->n);
	else if (l > 1)
	{
		print_l(tree->left, l - 1, func);
		print_l(tree->right, l - 1, func);
	}
}
