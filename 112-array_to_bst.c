#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from an array.
 * @array: pointer to the first element of the array to be converted.
 * @size: number of elements in @array.
 *
 * Return: pointer or NULL upon failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t n, m;

	if (array == NULL)
		return (NULL);

	for (n = 0; n < size; n++)
	{
		for (m = 0; m < n; m++)
		{
			if (array[m] == array[n])
				break;
		}
		if (m == n)
		{
			if (bst_insert(&tree, array[n]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
