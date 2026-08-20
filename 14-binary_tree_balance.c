#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
static size_t height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? 1 + height(tree->left) : 0;
	height_r = tree->right ? 1 + height(tree->right) : 0;

	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the
 * balance factor
 *
 * Return: The balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_l, height_r;

	if (tree == NULL)
		return (0);

	height_l = tree->left ? (int)height(tree->left) : -1;
	height_r = tree->right ? (int)height(tree->right) : -1;

	return (height_l - height_r);
}
