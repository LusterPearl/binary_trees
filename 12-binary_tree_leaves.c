#include "binary_trees.h"

/**
 * binary_tree_leaves - Count the leaves in a binary tree
 * @tree: A pointer to the root node of the tree to count the leaves
 *
 * Return: The number of leaves in the tree. If tree is NULL, return 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	/* check if tree is NULL */
	if (tree == NULL)
		return (0);

	/* if the current node is a leaf, return 1 */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Recursively count the leaves in the left and right subtrees */
	leaves += binary_tree_leaves(tree->left);
	leaves += binary_tree_leaves(tree->right);

	return (leaves);
}
