#ifndef _T_SORTEDLIST_H_
#define _T_SORTEDLIST_H_

typedef struct node
{
	int key;
	int data;
	struct node *next;
} node_type, *node_ptr;

node_ptr create_node(int key, int data);
void insert_node(node_ptr * const first, node_ptr node);
int search_node(node_ptr first, int key, int data);
void print_list(node_ptr first);
void delete(node_ptr *first, int key, int data);
void delete1(node_ptr *first, int key);
void delete2(node_ptr *first, int data);

#endif // !_T_SORTEDLIST_H_