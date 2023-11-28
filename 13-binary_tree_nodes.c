#include "binary_trees.h"

/**
 * binary_tree_nodes - Count nodes with at least 1 child in a binary tree
 * @tree: A pointer to the root node of the tree to count the nodes
 *
 * Return: The number of nodes with at least 1 child. if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	/* if the current node has at least 1 child, return 1 */
	if (tree->left != NULL || tree->right != NULL)
		nodes += 1;

	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	return (nodes);
}
