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

#include "fillit.h"

grid		*solve(grid *fillit_grid, coord *next, slider *total)
{
	int check;
	int solve;

	solve = 1;
	while (solve)
	{
		if ((check = chk_map(fillit_grid, next, total->piece_array[total->index])) == 1)
			next = solve_place(fillit_grid, next, total);
		else if (check == -1)
		{
			fillit_grid->flag = 1;
			if (fillit_grid->last[0].x == -1 && fillit_grid->last[0].y == -1 &&
				next->x == -1 && next->y == -1)
			{
				fillit_grid = solve_new_grid(fillit_grid, total);
				next = get_next_pos(coord_init(1, 1), fillit_grid);
			}
			else if (next->x == -1 && next->y == -1)
			{
				fillit_grid->last[total->index] = *coord_init(-1, -1);
				if (--total->index == -1)
				{
					fillit_grid = solve_new_grid(fillit_grid, total);
					next = get_next_pos(coord_init(1, 1), fillit_grid);
				}
				else
					next = solve_clear_piece(fillit_grid, next, total);
			}
			if (fillit_grid->flag == 1)
				next = get_next_coord(next, fillit_grid);
		}
		if (total->index == total->size)
			solve = 0;
	}
	return (fillit_grid);
}


coord	*solve_place(grid *fillit_grid, coord *next, slider *total)
{
	fillit_grid = place(fillit_grid, next, total->piece_array[total->index]);
	fillit_grid->last[total->index].x = next->x;
	fillit_grid->last[total->index].y = next->y;
	next = get_next_pos(coord_init(1, 1), fillit_grid);
	total->index++;
	return (next);
}

grid	*solve_new_grid(grid *fillit_grid, slider *total)
{
	fillit_grid = grid_init(free_grid(fillit_grid, total->size) + 1);
	total->index = 0;
	fillit_grid->flag = 0;
	return (fillit_grid);
}

coord	*solve_clear_piece(grid *fillit_grid, coord *next, slider *total)
{
	clear_piece(fillit_grid, total->piece_array[total->index]);
	next = &(fillit_grid->last[total->index]);
	return (next);
}