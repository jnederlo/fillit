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

grid		*solve(grid *f_grid, coord *next, slider *total)
{
	int check;
	
	while (total->index != total->size)
	{
		if ((check = chk_map(f_grid, next, total->piece_array[total->index])) == 1)
			next = solve_place(f_grid, next, total);
		else if (check == -1)
		{
			if (f_grid->last[0].x == -1 && f_grid->last[0].y == -1 &&
				next->x == -1 && next->y == -1 && (f_grid = solve_new(f_grid, total)))
				next = get_next_pos(coord_init(1, 1), f_grid);
			else if (next->x == -1 && next->y == -1)
			{
				f_grid->last[total->index] = *coord_init(-1, -1);
				if (--total->index == -1 && (f_grid = solve_new(f_grid, total)))
					next = get_next_pos(coord_init(1, 1), f_grid);
				else
					next = solve_clear_piece(f_grid, next, total);
			}
			if (f_grid->flag == 1)
				next = get_next_coord(next, f_grid);
		}
	}
	return (f_grid);
}


coord	*solve_place(grid *f_grid, coord *next, slider *total)
{
	f_grid = place(f_grid, next, total->piece_array[total->index]);
	f_grid->last[total->index].x = next->x;
	f_grid->last[total->index].y = next->y;
	next = get_next_pos(coord_init(1, 1), f_grid);
	total->index++;
	return (next);
}

grid	*solve_new(grid *f_grid, slider *total)
{
	f_grid = grid_init(free_grid(f_grid, total->size) + 1);
	total->index = 0;
	f_grid->flag = 0;
	return (f_grid);
}

coord	*solve_clear_piece(grid *f_grid, coord *next, slider *total)
{
	clear_piece(f_grid, total->piece_array[total->index]);
	next = &(f_grid->last[total->index]);
	return (next);
}