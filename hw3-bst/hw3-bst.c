#include <stdio.h>
#include "bst.h"

int main()
{
	int num;
	p_bst_t bst = CreateEmptyBst();

	while (scanf("%d", &num) != EOF)
	{
		if (bst->root == NULL)
			bst->root = CreateNode(num);
		else if (Search(bst->root, num) != NULL)
			Remove(&bst->root, num);
		else
			Add(bst->root, num);
		PrintList(bst);
	}

	return 0;
}

