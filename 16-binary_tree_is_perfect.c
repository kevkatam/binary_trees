#include "binary_trees.h"
/**
 * is_leaf - checks if a node is a leaf
 * @tree: pointer to the root of thr node to be checked
 * Return: 1 if it's a leaf 0 otherwise
 */
int is_leaf(const binary_tree_t *tree)
{
	int i = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		i = 1;

	return (i);
}
/**
 * is_parent - checks whether a node is parent
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if i'ts a parent 0 if not
 */
int is_parent(const binary_tree_t *tree)
{
	int j = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		j = 1;

	return (j);
}
/**
 * height - calculates the height of a binary tree
 * @tree: pointer tot the root node of the tree to calculate the height
 * Return: height of the tree
 */
size_t height(const binary_tree_t *tree)
{
	size_t left_h = 0;
	size_t right_h = 0;

	if (tree == NULL)
		return (0);

	left_h = height(tree->left);
	right_h = height(tree->right);

	if (left_h > right_h)
		return (left_h + 1);
	return (right_h + 1);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if it's perfect 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (height(tree->left) == height(tree->right))
	{
		if (height(tree->left) == 0)
			return (1);

		if (is_leaf(tree->left) && is_leaf(tree->right))
			return (1);

		if (is_parent(tree))
			return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}
	return (0);
}
