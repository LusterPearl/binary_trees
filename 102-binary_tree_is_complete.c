#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_complete(tree, 0, count_nodes(tree), 0));
}

/**
 * is_complete - Helper function to recursively check if a binary tree
 * @tree: Pointer to the root node of the tree to check
 * @index: Current index of the node in the tree
 * @node_count: Total number of nodes in the tree
 * @level: Level of the current node
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree,
int index, int node_count, int level)
{
	/* An empty tree is complete */
	if (!tree)
		return (1);

	/* If the index of the current node is greater  */
	if (index >= node_count)
		return (0);

	/* Check recursively for the left and right subtrees */
	return (is_complete(tree->left, 2 * index + 1, node_count, level + 1)
&& is_complete(tree->right, 2 * index + 2, node_count, level + 1));
}

/**
 * count_nodes - Helper function to count the total number of node
 * @tree: Pointer to the root node of the tree
 *
 * Return: Total number of nodes
 */
int count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}
