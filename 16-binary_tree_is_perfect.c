#include "binary_trees.h"

/**
 * perfect_height - Measures the height of a tree if it is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: The height of the tree if it is perfect, or -1 if it is not
 */
static int perfect_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	if (tree->left == NULL || tree->right == NULL)
		return (-1);

	left_height = perfect_height(tree->left);
	right_height = perfect_height(tree->right);

	if (left_height == -1 || right_height == -1 || left_height != right_height)
		return (-1);

	return (left_height + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (perfect_height(tree) == -1)
		return (0);

	return (1);
}
