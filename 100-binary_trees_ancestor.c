#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node,
 *         or NULL if no common ancestor was found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);
	return (find_ancestor(first, second, first->parent));
}

/**
 * find_ancestor - Helper function to find the lowest common
 * ancestor recursively.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 * @ancestor: A pointer to the potential ancestor node.
 *
 * Return: A pointer to the lowest common ancestor node,
 *         or NULL if no common ancestor was found.
 */
binary_tree_t *find_ancestor(const binary_tree_t *first,
const binary_tree_t *second, const binary_tree_t *ancestor)
{
	if (!ancestor)
		return (NULL);

	if (ancestor == first || ancestor == second)
		return ((binary_tree_t *)ancestor);

	binary_tree_t *left = find_ancestor(first, second, ancestor->left);
	binary_tree_t *right = find_ancestor(first, second, ancestor->right);

	if (left && right)
		return ((binary_tree_t *)ancestor);

	return (left ? left : right);
}
