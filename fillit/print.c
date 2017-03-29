#include "fillit.h"
#include <stdio.h>

void	test_print(slider *total)
{
	int size;
	int i;

	size = total->size;
	i = 0;
	while (size--)
	{
		printf("Piece %i: %i,%i\n", i, total->size,
			 total->size);
		i++;
	//	total->piece_array++;
	}
}