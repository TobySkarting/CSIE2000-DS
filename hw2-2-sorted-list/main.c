#include <stdio.h>
#include "sortedList.h"

int main()
{
	int opcode, key, data;
	node_ptr first = NULL;
	
	printf("1. insert\n2.delete\n3.search\n4.print\n");
	while (scanf("%d", &opcode) == 1)
	{
		switch (opcode)
		{
		case 1:
			scanf("%d%d", &key, &data);
			if (first == NULL)
				first = create_node(key, data);
			else
				insert_node(&first, create_node(key, data));
			break;
		case 3:
			scanf("%d%d", &key, &data);
			printf("pos: %d\n", search_node(first, key, data));
			break;
		case 4:
			print_list(first);
			break;
		default:
			break;
		}
	}
	return 0;
}
