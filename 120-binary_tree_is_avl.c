#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - height of a binary tree to measure.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: 0 if tree is NULL, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t i = 0, j = 0;

		i = tree->left ? 1 + height(tree->left) : 1;
		j = tree->right ? 1 + height(tree->right) : 1;
		return ((i > j) ? i : j);
	}
	return (0);
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: pointer to the root node of the tree to check.
 * @lo: value of the smallest node visited
 * @hi: value of the largest node visited
 *
 * Return: 1 if the tree is a valid AVL tree. Otherwise 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t left_height, right_height, difference;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		left_height = height(tree->left);
		right_height = height(tree->right);
		difference = left_height > right_height ?
left_height - right_height : right_height - left_height;
		if (difference > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
