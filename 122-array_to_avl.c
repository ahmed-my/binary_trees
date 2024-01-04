#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: pointer to the first element of the array to be converted.
 * @size: number of elements in @array.
 *
 * Return: pointer or NULL upon failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
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
			if (avl_insert(&tree, array[n]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
