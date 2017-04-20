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

t_coord	*coord_init(int x, int y)
{
	t_coord *pos;

	pos = (t_coord *)malloc(sizeof(t_coord));
	if (pos == NULL)
		return (NULL);
	pos->x = x;
	pos->y = y;
	return (pos);
}

t_coord	*get_next_pos(t_coord *start, t_grid *f_grid)
{
	int		x;
	int		y;
	int		check;
	t_coord	*pos;

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
				return (coord_init(x, y));
			x++;
		}
		check = 1;
		y++;
	}
	return (pos);
}

t_coord	*get_next_coord(t_coord *start, t_grid *f_grid)
{
	t_coord *pos;

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

t_coord	*coord_array_init(int size)
{
	int		i;
	t_coord	*coord_array;
	t_coord	coord_row;

	i = 0;
	coord_array = (t_coord *)malloc(sizeof(t_coord) * size);
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
