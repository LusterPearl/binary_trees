#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node.
 * @node: A pointer to the node to find the uncle
 *
 * Return: A pointer to the uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* check if the node is NULL or its parent is NULL */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Use the binary_tree_sibling function to get the uncle */
	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
