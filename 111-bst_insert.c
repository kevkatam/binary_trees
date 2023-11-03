#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	return (is_present(tree, value));
}
/**
 * is_present - checks if a node is already present in the tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to check and insert
 * Return: pointer to the inserted node
 */
bst_t *is_present(bst_t **tree, int value)
{
	if ((*tree)->n > value)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
		{
			return (is_present(&((*tree)->left), value));
	}
	}
	if ((*tree)->n < value)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		else
		{
			return (is_present(&((*tree)->right), value));
		}
	}
	return (NULL);
}
