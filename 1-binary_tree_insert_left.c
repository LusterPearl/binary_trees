#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another
 * @parent: A pointer to the node to insert the left-child in
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the created node, or NULL on failure or if parent
 * is NULL, if parent already has a left-child, the new node take it place
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	/* allocate memory for the new node */
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
	/* check if parent is NULL */
	if (parent == NULL)
		return (NULL);

	/* check if parent is NULL */
	if (new_node == NULL)
		return (NULL);

	/* Set the values for the new node */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = parent->left;
	new_node->right = NULL;

	/* if parent already as left child, update it parent to the new node */
	if (parent->left != NULL)
		parent->left->parent = new_node;

	/* set the new node as the left-child of the parent */
	parent->left = new_node;

	/* Return a pointer to the created node */
	return (new_node);
}
