/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_manipulator.c                                 :+:      :+:    :+:   */
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

grid	*grid_init(int size)
{
	int		i;
	int		j;
	grid	*fillit_grid;
	char	**pos_array;
	char	*pos_row;

	i = -1;
	fillit_grid = (grid *)malloc(sizeof(grid));
	pos_array = (char **)malloc((sizeof(char *) * (size)));
	while (i++ < size)
	{
		pos_row = (char *)malloc(sizeof(char) * (size));
		pos_array[i] = pos_row;
	}
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (j++ < size)
			pos_array[i][j] = '.';
	}
	fillit_grid->pos = pos_array;
	fillit_grid->smallest = size;
	fillit_grid->last = coord_array_init(size);
	return (fillit_grid);
}

int		free_grid(grid *fillit_grid, int size)
{
	int smallest;
	int i;

	size = 0;
	smallest = fillit_grid->smallest;
	i = 0;
	free(fillit_grid->last);
	i = 0;
	while (i < smallest)
	{
		free(fillit_grid->pos[i]);
		i++;
	}
	free(fillit_grid->pos);
	free(fillit_grid);
	fillit_grid = NULL;
	return (smallest);
}
