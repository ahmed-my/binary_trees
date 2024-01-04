#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Check binary tree is valid binary search tree.
 * @tree: pointer to the root node of the tree
 * @lo: value of the smallest node visited.
 * @hi: value of the largest node visited.
 *
 * Return: 1 if the tree is a valid BST. Otherwise 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}
