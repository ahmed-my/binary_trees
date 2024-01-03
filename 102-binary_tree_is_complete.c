#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: binary tree node for the new node to contain.
 *
 * Return: NULL if an error occurs. Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: binary tree node to print and push.
 * @head: double pointer to the head of the queue.
 * @tail: double pointer to the tail of the queue.
 *
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new_node;

	new_node = create_node(node);
	if (new_node == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new_node;
	*tail = new_node;
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to traverse.
 *
 * Return: 0 if the tree is NULL or not complete. Otherwise, 1.
 *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flagged = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flagged == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flagged = 1;
		if (head->node->right != NULL)
		{
			if (flagged == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flagged = 1;
		pop(&head);
	}
	return (1);
}
