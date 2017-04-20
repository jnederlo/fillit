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

int		smallest_square(t_slider *total)
{
	return (g_smallest_square[total->size - 1]);
}

t_grid	*grid_init(int size)
{
	int		i;
	int		j;
	t_grid	*f_grid;
	char	**pos_array;

	i = -1;
	f_grid = (t_grid *)malloc(sizeof(t_grid));
	pos_array = (char **)malloc((sizeof(char *) * (size)));
	while (i++ < size)
		pos_array[i] = (char *)malloc(sizeof(char) * (size));
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (j++ < size)
			pos_array[i][j] = '.';
	}
	f_grid->flag = 1;
	f_grid->pos = pos_array;
	f_grid->smallest = size;
	f_grid->last = coord_array_init(size);
	return (f_grid);
}

int		free_grid(t_grid *f_grid, int size)
{
	int smallest;
	int i;

	size = 0;
	smallest = f_grid->smallest;
	i = 0;
	free(f_grid->last);
	i = 0;
	while (i < smallest)
	{
		free(f_grid->pos[i]);
		i++;
	}
	free(f_grid->pos);
	free(f_grid);
	f_grid = NULL;
	return (smallest);
}
