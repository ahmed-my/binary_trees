#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right child
 * @parent: A pointer to the node to insert in the right child
 * @value: The value to store in the new node.
 *
 * Return: NULL if parent or an error occurs.Otherwise pointer to the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);
}

