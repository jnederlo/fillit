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
	int	smallest_square[26] = {2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7,
		 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11};
	return (smallest_square[total->size - 1]);
}

//int	check_map()
//{
//
//}

grid	*grid_init(int smallest) // NEED TO MALLOC WORST CASE INSTEAD OF SMALLEST
{
	int i;
	int j;
	grid *fillit_grid;
	char **pos_array;
	char *pos_row;
	
	i = 0;
	j = 0;
	fillit_grid = (grid *)malloc(sizeof(grid));
	pos_array = (char **)malloc(sizeof(char *) * smallest + 2);
	while (i < smallest)
	{
		// MALLOC EACH ROW OF POS_ARRAY
		pos_row = (char *)malloc(sizeof(char) * smallest + 2);
		pos_array[i] = pos_row;
		i++;
	}
	i = 0;
	while (i < smallest)
	{
		j = 0;
		while (j < smallest)
		{
			pos_array[i][j] = '.';
			j++;
		}
		i++;
	}
	fillit_grid->pos = pos_array;
	fillit_grid->dimension = smallest;
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
