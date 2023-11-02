#include "binary_trees.h"
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_bst(tree));
}
/**
 * binary_tree_leaf - checks if binary tree is a leaf
 * @tree: pointer to the root node
 * Return: 1 if it's a leaf 0 otherwisw
 */
int binary_tree_leaf(const binary_tree_t *tree)
{
	int i = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		i = 1;
	return (i);
}
/**
 * check_appropriate - checks if a node has a value higher or lower than
 * its grand parent
 * @tree: node to check
 * Return: 1 if the node is appropriate 0 otherwise
 */
int check_appropriate(const binary_tree_t *tree)
{
	const binary_tree_t *parnt;
	const binary_tree_t *grandpa;

	if (tree == NULL || tree->parent == NULL ||
			tree->parent->parent == NULL)
		return (1);

	parnt = tree->parent;
	grandpa = parnt->parent;

	while (parnt != NULL && grandpa != NULL)
	{
		if (parnt->n < grandpa->n && tree->n >= grandpa->n)
			return (0);

		if (parnt->n > grandpa->n && tree->n <= grandpa->n)
			return (0);
		parnt = parnt->parent;
		grandpa = parnt->parent;
	}
	return (1);
}
/**
 * binary_tree_bst - checks if binary tree is bst
 * @tree: pointer to root node
 * Return: 1 if it's bst
 */
int binary_tree_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);
	if (binary_tree_leaf(tree) == 1)
		return (1);

	if (tree->left != NULL && tree->left->n >= tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n <= tree->n)
		return (0);
	if (!check_appropriate(tree->left) || !check_appropriate(tree->right))
		return (0);

	return (binary_tree_bst(tree->left) && binary_tree_bst(tree->right));
}
