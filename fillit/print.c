#include "fillit.h"
#include <stdio.h>

void	test_print(slider *total)
{
	int	size;
	int	i;
	int	j;

	size = total->size;
	i = 0;
	while (size--)
	{
		j = 0;
		printf( BOLDRED "\nPiece %i:\n\n" RESET , i + 1);
		printf( BLUE "COLUMN		ROW\n" RESET );
		printf( BLUE "---------------------\n" RESET);
		while (j < 4)
		{
			printf("%i \t\t%i\n", total->piece_array[i]->pos[j].x,
			total->piece_array[i]->pos[j].y);
			j++;
		}
		i++;
	}
}