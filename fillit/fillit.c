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
	int smallest;

	smallest = 1;
	if (total->size == 1)
		smallest = 2;
	else if (total->size == 2)
		smallest = 3;
	else if (total->size == 3)
		smallest = 4;
	else if (total->size == 4)
		smallest = 4;
	else if (total->size == 5)
		smallest = 5;
	else if (total->size == 6)
		smallest = 5;
	else if (total->size == 7)
		smallest = 6;
	else if (total->size == 8)
		smallest = 6;
	return (smallest);
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
	pos_array = (char **)malloc(sizeof(char *) * smallest);
	while (i < smallest)
	{
		// MALLOC EACH ROW OF POS_ARRAY
		pos_row = (char *)malloc(sizeof(char) * smallest);
		pos_array[i] = pos_row;
		i++;
	}
	i = 0;
	while (i < smallest)
	{
		while (j < smallest)
		{
			pos_array[i][j] = '.';
			ft_putchar('.');
			j++;
		}
		ft_putchar('\n');
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
}
