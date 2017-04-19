/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:39:59 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/23 13:40:11 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // NEED TO REMOVE THIS
#include "fillit.h"

grid		*solve(grid *fillit_grid, coord *next, slider *total)
{
	int check;
	int solve;
	int flag;

	flag = 1;
	solve = 1;
	while (solve == 1)
	{
		check = chk_map(fillit_grid, next, total->piece_array[total->index]);
		if (check == 1)
		{
			fillit_grid = place(fillit_grid, next, total->piece_array[total->index]);
			fillit_grid->last[total->index].x = next->x;
			fillit_grid->last[total->index].y = next->y;
			next = get_next_pos(coord_init(1, 1), fillit_grid);
			total->index++;
		}
		else if (check == -1)
		{
			if (fillit_grid->last[0].x == -1 && fillit_grid->last[0].y == -1 &&
				next->x == -1 && next->y == -1)
			{
				fillit_grid = grid_init(free_grid(fillit_grid, total->size) + 1);
				total->index = 0;
				next = get_next_pos(coord_init(1, 1), fillit_grid);
				flag = 0;
			}
			else if (next->x == -1 && next->y == -1)
			{
				fillit_grid->last[total->index].x = -1;
				fillit_grid->last[total->index].y = -1;
				total->index--;
				if (total->index == -1)
				{
					fillit_grid = grid_init(free_grid(fillit_grid, total->size) + 1);
					total->index = 0;
					next = get_next_pos(coord_init(1, 1), fillit_grid);
					flag = 0;
				}
				else
				{
					clear_piece(fillit_grid, total->piece_array[total->index]);
					next = &(fillit_grid->last[total->index]);
				}
			}
			if (flag == 1)
			{
				next = get_next_coord(next, fillit_grid);
				next = get_next_pos(next, fillit_grid);
			}
			flag = 1;
		}
		if (total->index == total->size)
			solve = 0;
	}
	return (fillit_grid);
}