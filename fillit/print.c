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
		printf( BOLDCYAN "\nPiece %i:\n\n" RESET , i + 1);
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

void	print_grid(grid *fillit)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < fillit->dimension)
	{
		j = 0;
		while (j < fillit->dimension)
		{
			ft_putchar(fillit->pos[i][j].pos);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
