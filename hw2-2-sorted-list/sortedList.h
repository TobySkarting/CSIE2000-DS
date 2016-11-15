#ifndef _T_SORTEDLIST_H_
#define _T_SORTEDLIST_H_

typedef struct node
{
	int key;
	int data;
	struct node *next;
} node_type, *node_ptr;

node_ptr create_node(int key, int data);
void insert_node(node_ptr *first, node_ptr node);
int search_node(node_ptr first, int key, int data);
void print_list(node_ptr first);


#endif // !_T_SORTEDLIST_H_