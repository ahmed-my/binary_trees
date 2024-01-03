#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree to measure the balance factor.
 *
 * Return: 0 if tree is NULL. Otherwise, return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: 0 if tree is NULL. Otherwise, return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t i = 0, j = 0;

		i = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		j = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((i > j) ? i : j);
	}
	return (0);
}
