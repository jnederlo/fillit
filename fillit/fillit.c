/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:39:59 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/23 13:40:11 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		smallest_square(slider *total)
{
	return (g_smallest_square[total->size - 1]);
}

//int		check_map(grid *fillit_grid, coord pos, piece *tet_piece)
//{
//	
//}

/*coord	get_next_pos(grid *fillit_grid)
{
	int x;
	int y;
	int i;
	int j;
	coord pos;

	x = 1;
	y = 1;
	i = 0;
	j = 0;
	while (i < fillit_grid->dimension && j < fillit_grid->dimension)
	{
		if (fillit_grid->pos[i][j] == '.')
		{
			pos.x = i + 1;
			pos.x = j + 1;
		}
		j++;
	}
	return (pos);
}
*/

grid	*grid_init(int size) // NEED TO MALLOC WORST CASE INSTEAD OF SMALLEST
{
	int i;
	int j;
	grid *fillit_grid;
	char **pos_array;
	char *pos_row;
	
	i = 0;
	j = 0;
	fillit_grid = (grid *)malloc(sizeof(grid));
	pos_array = (char **)malloc((sizeof(char *) * (size + 2)));
	while (i < size + 2)
	{
		// MALLOC EACH ROW OF POS_ARRAY
		pos_row = (char *)malloc(sizeof(char) * (size + 2));
		pos_array[i] = pos_row;
		i++;
	}
	i = 0;
	while (i < size + 2)
	{
		j = 0;
		while (j < size + 2)
		{
			pos_array[i][j] = '.';
			j++;
		}
		i++;
	}
	fillit_grid->pos = pos_array;
	fillit_grid->smallest = size;
	return (fillit_grid);
}

void	fillit(slider *total)
{
	grid	*fillit_grid;
	int		size;

	size = smallest_square(total);
	fillit_grid = grid_init(size);
	print_grid(fillit_grid);
	//place();
}
