#include <iostream>
using namespace std;

#include "flat.h"

void push_at(struct Node **head, int position, int bandwidth, int flat_id)
{
	struct Node *newNode = new Node();
	newNode->bandwidth = bandwidth;
	newNode->flat_id = flat_id;
	newNode->next = NULL;
	newNode->prev = NULL;
	if (position < 1)
	{
		cout << "\nposition should be >= 1.";
	}
	else if (position == 1)
	{
		newNode->next = (*head);
		*head = newNode;
	}
	else
	{
		Node *temp = *head;
		for (int i = 1; i < position - 1; i++)
		{
			if (temp != NULL)
			{
				temp = temp->next;
			}
		}
		if (temp != NULL)
		{
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next = newNode;
			if (newNode->next != NULL)
				newNode->next->prev = newNode;
		}
		else
		{
			cout << "\nThe previous node is null.";
		}
	}
}

void deleteNode(Node **head, Node *del)
{
	/* base case */
	if (*head == NULL || del == NULL)
		return;

	/* If node to be deleted is head node */
	if (*head == del)
		*head = del->next;

	/* Change next only if node to be
	deleted is NOT the last node */
	if (del->next != NULL)
		del->next->prev = del->prev;

	/* Change prev only if node to be
	deleted is NOT the first node */
	if (del->prev != NULL)
		del->prev->next = del->next;

	/* Finally, free the memory occupied by del*/
	free(del);
	return;
}

struct Node *traverseFlatList(struct Node *node, int key)
{
	struct Node *last;

	while (node != NULL)
	{
		if (node->flat_id == key)
		{
			return node;
		}
		last = node;
		node = node->next;
	}
	return NULL;
}

void makeFlatEmpty(struct Node *node, int key)
{
	struct Node *last;

	while (node != NULL)
	{
		if (node->flat_id == key)
		{
			node->bandwidth = 0;
		}
		last = node;
		node = node->next;
	}
}

int getFlatPos(struct Node *node, int key)
{
	struct Node *last;
	int pos = 0;
	while (node != NULL)
	{
		if (node->flat_id == key)
		{
			return pos;
		}
		pos = pos + 1;
		last = node;
		node = node->next;
	}
	return -1;
}

void displayList(struct Node *node)
{
	struct Node *last;

	while (node != NULL)
	{
		cout << "Flat" << node->flat_id << "(" << node->bandwidth << ")"
			 << "\t";
		last = node;
		node = node->next;
	}
	if (node == NULL)
		cout << "\n";
}

struct Node *combine(struct Node *first, struct Node *second)
{
	if (!first)
		return second;

	if (!second)
		return first;

	first->next = combine(first->next, second);
	first->next->prev = first;
	first->prev = NULL;
	return first;
}