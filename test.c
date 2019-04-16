
#include <stdio.h>

int	main(int argc, char **argv)
{
	int i = atoi(argv[1]);
	signed char j;
	int k = 0;

	j = (signed char)i;
	k = (int)j;
	printf ("i : %d| j : %d | k : %d", i, j, k);
	return(0);
}
