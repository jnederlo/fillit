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

#include "../includes/fillit.h"

t_grid	*solve(t_grid *f_grid, t_coord *next, t_slider *total)
{
	int	check;

	while (total->index != total->size)
	{
		if ((check = chk_map(f_grid, next, total->p_array[total->index])) == 1)
			next = solve_place(f_grid, next, total);
		else if (check == -1)
		{
			if (f_grid->last[0].x == -1 && f_grid->last[0].y == -1 &&
				next->x == -1 && next->y == -1 &&
				(f_grid = solve_n(f_grid, total)))
				next = get_next_pos(coord_init(1, 1), f_grid);
			else if (next->x == -1 && next->y == -1)
			{
				f_grid->last[total->index] = *coord_init(-1, -1);
				if (--total->index == -1 && (f_grid = solve_n(f_grid, total)))
					next = get_next_pos(coord_init(1, 1), f_grid);
				else
					next = solve_clear(f_grid, next, total);
			}
			if (f_grid->flag == 1)
				next = get_next_coord(next, f_grid);
		}
	}
	return (f_grid);
}

t_coord	*solve_place(t_grid *f_grid, t_coord *next, t_slider *total)
{
	f_grid = place(f_grid, next, total->p_array[total->index]);
	f_grid->last[total->index].x = next->x;
	f_grid->last[total->index].y = next->y;
	next = get_next_pos(coord_init(1, 1), f_grid);
	total->index++;
	return (next);
}

t_grid	*solve_n(t_grid *f_grid, t_slider *total)
{
	f_grid = grid_init(free_grid(f_grid, total->size) + 1);
	total->index = 0;
	f_grid->flag = 0;
	return (f_grid);
}

t_coord	*solve_clear(t_grid *f_grid, t_coord *next, t_slider *total)
{
	clear_piece(f_grid, total->p_array[total->index]);
	next = &(f_grid->last[total->index]);
	return (next);
}
