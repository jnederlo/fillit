/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:39:59 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/23 13:40:11 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		chk_map(t_grid *f_grid, t_coord *start, t_piece *tet_piece)
{
	int		i;
	int		diffx;
	int		diffy;
	t_coord	check;

	f_grid->flag = 1;
	if (start->x == -1 && start->y == -1)
		return (-1);
	i = 0;
	diffx = start->x - tet_piece->pos[i].x;
	diffy = start->y - tet_piece->pos[i].y;
	while (i < 4)
	{
		check = tet_piece->pos[i];
		check.x += diffx;
		check.y += diffy;
		if (check.x > f_grid->smallest || check.y > f_grid->smallest
			|| check.x < 1 || check.y < 1)
			return (-1);
		if (f_grid->pos[check.y - 1][check.x - 1] != '.')
			return (-1);
		i++;
	}
	return (1);
}

t_grid	*place(t_grid *f_grid, t_coord *grid_pos, t_piece *tet_piece)
{
	int		i;
	int		diffx;
	int		diffy;
	t_coord	place;

	i = 0;
	diffx = grid_pos[i].x - tet_piece->pos[i].x;
	diffy = grid_pos[i].y - tet_piece->pos[i].y;
	while (i < 4)
	{
		place = tet_piece->pos[i];
		place.x += diffx;
		place.y += diffy;
		f_grid->pos[place.y - 1][place.x - 1] = tet_piece->letter;
		i++;
	}
	return (f_grid);
}

void	clear_piece(t_grid *f_grid, t_piece *tet_piece)
{
	char	letter;
	t_coord	pos;

	pos.x = 1;
	pos.y = 1;
	letter = tet_piece->letter;
	while (pos.x <= f_grid->smallest ||
			pos.y <= f_grid->smallest)
	{
		pos.x = 1;
		while (pos.x <= f_grid->smallest)
		{
			if (f_grid->pos[pos.y - 1][pos.x - 1] == letter)
				f_grid->pos[pos.y - 1][pos.x - 1] = '.';
			pos.x++;
		}
		pos.y++;
	}
}

void	fillit(t_slider *total)
{
	t_grid	*f_grid;
	int		smallest;
	t_coord	start;

	start.x = 1;
	start.y = 1;
	smallest = smallest_square(total);
	f_grid = grid_init(smallest);
	f_grid = solve(f_grid, &start, total);
	print_grid(f_grid);
}
