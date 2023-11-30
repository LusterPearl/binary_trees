#include "binary_trees.h"

# define QUEUE_SIZE 1024

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue;
	int front, rear;
	const binary_tree_t *current;

	if (!tree || !func)
		return;

	/* Use an array as a simple queue */
	queue = malloc(sizeof(binary_tree_t *) * QUEUE_SIZE);
	front = 0;
	rear = 0;

	/* Enqueue the root node */
	queue[rear++] = tree;

	/* Traverse the tree using level-order transversla */
	while (front < rear)
	{
		current = queue[front++];

		/* call the function for the current node */
		func(current->n);

		/* Enqueue the left child if it exists */
		if (current->left)
			queue[rear++] = current->left;

		if (current->right)
			queue[rear++] = current->right;
	}

	/* Free the allocated queue */
	free(queue);
}
