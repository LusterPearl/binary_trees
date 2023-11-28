#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child
 * @parent: A pointer to the node to insert the right-child
 * @value: The value to store in the new node
 *
 * Return: A pointer to the created, node, or NULL
 * If parent already has a right-child
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	/* allocate memory for the new node */
	binary_tree_t *new_node;

	/* Check if parent is NULL */
	if (parent == NULL)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));
	/* Check if memory allocation was successful */
	if (new_node == NULL)
		return (NULL);

	/* Set the values for the new node */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = parent->right;

	/* if parent already has a right child */
	if (parent->right != NULL)
		parent->right->parent = new_node;

	/* Set the new node as the right-child of the parent */
	parent->right = new_node;

	/* Return a pointet to the created node */
	return (new_node);
}
