#include <stdio.h>
#include "lazyList.h"

int main()
{
	int input, created;
	node_ptr first = create_list();

	while (scanf("%d", &input) == 1)
	{
		created = make_fib(first, input);
		print_list_n(first, input);
		printf(" create %d nodes\n", created);
	}
	printf("\nend.\n");
	return 0;
}
