#include "lazyList.h"
#include <stdlib.h>
#include <stdio.h>

node_ptr create_node(int data)
{
	node_ptr a = (node_ptr)malloc(sizeof(node_type));
	a->data = data;
	a->next = NULL;
	return a;
}

node_ptr create_list()
{
	node_ptr first = create_node(0);
	insert_node(first, create_node(1));
	return first;
}

void insert_node(node_ptr node, node_ptr next)
{
	node->next = next;
	next->next = node;
}

void print_list(node_ptr first)
{
	node_ptr last = NULL;
	while (first != NULL)
	{
		if (last)
		{
			printf("%d", last->data);
			if (first->data < last->data)
				break;
			printf(",");
		}
		last = first;
		first = first->next;
	}
}

void print_list_n(node_ptr first, int count)
{
	node_ptr last = NULL;
	printf("[");
	while (first != NULL)
	{
		if (last)
		{
			if (!count)
				break;
			printf("%d", last->data);
			if (first->data < last->data)
				break;
			if (--count)
				printf(",");
		}
		last = first;
		first = first->next;
	}
	printf("]");
}

int make_fib(node_ptr first, int count)
{
	int created = 0;

	while (--count)
	{
		if (first->next->next == first)
		{
			first = first->next;
			--count;
			break;
		}
		first = first->next;
	}
 	while (count--)
	{
		first->next = create_node(first->data + first->next->data);
		first->next->next = first;
		first = first->next;
		++created;
	}
	return created;
}

