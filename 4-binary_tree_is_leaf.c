#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: A pointer to the node to check.
 *
 * Return: 1 if the node is a leaf, 0 otherwise.
 * If node is NULL, return 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* check if the node is not NULL and has no left or right children */
	return (node != NULL && node->left == NULL && node->right == NULL);
}
