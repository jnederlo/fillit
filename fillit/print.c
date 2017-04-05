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
		printf( BLUE "COLUMN		ROW	%c\n" RESET , total->piece_array[i]->letter);
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

void	print_grid(grid *fillit_grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < fillit_grid->smallest)
	{
		j = 0;
		while (j < fillit_grid->smallest)
		{
			ft_putchar(fillit_grid->pos[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
