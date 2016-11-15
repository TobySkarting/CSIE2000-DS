#include <stdio.h>
#include "lazyList.h"

int main()
{
	char line[100];
	int input, created;
	node_ptr first = create_list();

	while (fgets(line, sizeof(line), stdin))
	{
		if (sscanf(line, "%*[^,],%d", &input) != 1)
			break;
		created = make_fib(first, input);
		print_list_n(first, input);
		printf(" create %d nodes\n", created);
	}
	return 0;
}
