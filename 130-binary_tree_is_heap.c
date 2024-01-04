#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - check max value
 * @tree: pointer to the root
 * Return: 1 if all nodes are max, Otherwise 0
 *
 **/
int check_max(const binary_tree_t *tree)
{
	int temp_1 = 1, temp_2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		temp_1 = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		temp_2 = check_max(tree->right);
	}
	return (temp_1 && temp_2);
}
/**
 * binary_tree_is_heap - checks if a binary tree is heap
 * @tree: pointer to the node
 * Return: 1 in case BTS. Otherwise 0
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int temp;

	if (!tree)
		return (0);

	temp = binary_tree_is_complete(tree);
	if (!temp)
		return (0);
	return (check_max(tree));
}
