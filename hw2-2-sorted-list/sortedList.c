#include "sortedList.h"
#include <stdlib.h>

node_ptr create_node(int key, int data)
{
	node_ptr node = (node_ptr)malloc(sizeof(node_type));
	node->key = key;
	node->data = data;
	node->next = NULL;
	return node;
}

void insert_node(node_ptr * const first, node_ptr node)
{
	node_ptr now = *first, last = NULL;
	while (now)
	{
		if (now->key < node->key)
		{
			last = now;
			now = now->next;
		}
		else if (now->key == node->key)
		{
			do
			{
				if (now->data < node->data)
				{
					last = now;
					now = now->next;
				}
				else 
					break;
			} while (now && now->key == node->key);

			node->next = now;
			if (last)
				last->next = node;
			else
				*first = node;
			return;
		}
		else
		{
			node->next = now->next;
			now->next = node;
			return;
		}
	}
	last->next = node;
}

int search_node(node_ptr first, int key, int data)
{
	int pos = 1;
	while (first)
	{
		if (key < first->key)
			break;
		if (key == first->key && data == first->data)
			return pos;
		first = first->next;
		++pos;
	}
	return -1;
}

void print_list(node_ptr first)
{
	while (first)
	{
		printf("%d : %d\n", first->key, first->data);
		first = first->next;
	}
}

void delete_node(node_ptr *pnode)
{
	node_ptr node = *pnode;
	*pnode = node->next;
	free(node);
}

void delete(node_ptr *first, int key, int data)
{
	while (*first)
	{
		if (key < (*first)->key)
			break;
		if (key == (*first)->key && data == (*first)->data)
			delete_node(first);
		else
			first = &(*first)->next;
	}
}

void delete1(node_ptr *first, int key)
{
	while (*first)
	{
		if (key < (*first)->key)
			break;
		if (key == (*first)->key)
			delete_node(first);
		else
			first = &(*first)->next;
	}
}

void delete2(node_ptr *first, int data)
{
	while (*first)
	{
		if (data == (*first)->data)
			delete_node(first);
		else
			first = &(*first)->next;
	}
}
