#ifndef _T_LAZYLIST_H_

typedef struct node
{
	int data;
	struct node *next;
} node_type, *node_ptr;

node_ptr create_node(int data);
node_ptr create_list();
void insert_node(node_ptr node, node_ptr next);
void print_list(node_ptr first);
void print_list_n(node_ptr first, int count);
int make_fib(node_ptr first, int count);

#endif // !_T_LAZYLIST_H_
