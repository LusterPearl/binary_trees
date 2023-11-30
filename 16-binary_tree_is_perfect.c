#include "binary_trees.h"

/**
 * tree_is_perfect - Check if a binary tree is perfect or  not.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree->left && tree->right)
	{
		left = 1 + tree_is_perfect(tree->left);
		right = 1 + tree_is_perfect(tree->right);
		if (right == left && right != 0 && left != 0)
			return (right);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * binary_tree_is_perfect - perfect or not a tree
 * @tree: tree to check
 * Return: 1 is it is or 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		result = tree_is_perfect(tree);
		if (result != 0)
		{
			return (1);
		}
		return (0);
	}
}
