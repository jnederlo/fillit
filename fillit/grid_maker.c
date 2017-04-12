/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:39:59 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/23 13:40:11 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		smallest_square(slider *total)
{
	return (g_smallest_square[total->size - 1]);
}

coord	*coord_init(int x, int y)
{
	coord *pos;

	pos = (coord *)malloc(sizeof(coord)); //need to add malloc protection.
	if (pos == NULL)
		return (NULL);
	pos->x = x;
	pos->y = y;
	return (pos);
}

coord	*get_next_pos(coord *start, grid *fillit_grid)
{
	int x;
	int y;
	int check;
	coord *pos;

	pos = coord_init(-1, -1);
	if (start->x == -1 && start->y == -1)
		return (start);
	check = 0;
	x = start->x;
	y = start->y;
	while (x <= fillit_grid->smallest || y <= fillit_grid->smallest)
	{
		if (check) // MAKE SURE LOOP RUNS ONCE BEFORE SETTING x = 1
			x = 1;
		while (x <= fillit_grid->smallest)
		{
			if (fillit_grid->pos[y - 1][x - 1] == '.')
			{
				pos->x = x;
				pos->y = y;
				return (pos);
			}
			x++;
		}
		check = 1;
		y++;
	}
	return (pos);
}

coord	*get_next_coord(coord *start, grid *fillit_grid)
{
	coord *pos;

	pos = coord_init(-1, -1);
	if (start->x == -1 && start->y == -1)
		return (start);
	if (start->x < fillit_grid->smallest)
	{
		pos->x = start->x + 1;
		pos->y = start->y;
		return (pos);
	}
	else if (start->x == fillit_grid->smallest && start->y < fillit_grid->smallest)
	{
		pos->x = 1;
		pos->y = start->y + 1;
		return (pos);
	}
	return (pos);
}

grid	*grid_init(int size)
{
	int i;
	int j;
	grid *fillit_grid;
	char **pos_array;
	char *pos_row;

	i = 0;
	j = 0;
	fillit_grid = (grid *)malloc(sizeof(grid));
	if (fillit_grid == NULL)
		return (NULL);
	pos_array = (char **)malloc((sizeof(char *) * (size)));
	if (pos_array == NULL)
		return (NULL);
	while (i < size)
	{
		pos_row = (char *)malloc(sizeof(char) * (size));
		if (pos_row == NULL)
			return (NULL);
		pos_array[i] = pos_row;
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			pos_array[i][j] = '.';
			j++;
		}
		i++;
	}
	fillit_grid->pos = pos_array;
	fillit_grid->smallest = size;
	fillit_grid->last = coord_array_init(size);
	return (fillit_grid);
}

coord	*coord_array_init(int size)
{
	int i;
	coord *coord_array;
	coord coord_row;
	
	i = size;
	coord_array = (coord *)malloc(sizeof(coord) * size);
	if (coord_array == NULL)
			return (NULL);
	while (i < size)
	{
		coord_row.x = -1;
		coord_row.y = -1;
		coord_array[i] = coord_row;
		i++;
	}
	return (coord_array);
}