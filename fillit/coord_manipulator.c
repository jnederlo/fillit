/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_manipulator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:39:59 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/23 13:40:11 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

coord	*coord_init(int x, int y)
{
	coord *pos;

	pos = (coord *)malloc(sizeof(coord));
	if (pos == NULL)
		return (NULL);
	pos->x = x;
	pos->y = y;
	return (pos);
}

coord	*get_next_pos(coord *start, grid *f_grid)
{
	int		x;
	int		y;
	int		check;
	coord	*pos;

	if (start->x == -1 && start->y == -1)
		return (start);
	pos = coord_init(-1, -1);
	check = 0;
	x = start->x;
	y = start->y;
	while (x <= f_grid->smallest || y <= f_grid->smallest)
	{
		if (check)
			x = 1;
		while (x <= f_grid->smallest)
		{
			if (f_grid->pos[y - 1][x - 1] == '.')
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

coord	*get_next_coord(coord *start, grid *f_grid)
{
	coord *pos;

	if (start->x == -1 && start->y == -1)
		return (start);
	pos = coord_init(-1, -1);
	if (start->x < f_grid->smallest)
	{
		pos->x = start->x + 1;
		pos->y = start->y;
		pos = get_next_pos(pos, f_grid);
		return (pos);
	}
	else if (start->x == f_grid->smallest &&
		start->y < f_grid->smallest)
	{
		pos->x = 1;
		pos->y = start->y + 1;
		pos = get_next_pos(pos, f_grid);
		return (pos);
	}
	return (pos);
}

coord	*coord_array_init(int size)
{
	int		i;
	coord	*coord_array;
	coord	coord_row;

	i = 0;
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
