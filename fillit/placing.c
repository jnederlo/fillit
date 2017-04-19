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

int		chk_map(grid *fillit_grid, coord *start, piece *tet_piece)
{
	int		i;
	int		diffx;
	int		diffy;
	coord	check;

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
		if (check.x > fillit_grid->smallest ||
			check.y > fillit_grid->smallest ||
			check.x < 1 || check.y < 1)
			return (-1);
		if (fillit_grid->pos[check.y - 1][check.x - 1] != '.')
			return (-1);
		i++;
	}
	return (1);
}

grid	*place(grid *fillit_grid, coord *grid_pos, piece *tet_piece)
{
	int		i;
	int		diffx;
	int		diffy;
	coord	place;

	i = 0;
	diffx = grid_pos[i].x - tet_piece->pos[i].x;
	diffy = grid_pos[i].y - tet_piece->pos[i].y;
	while (i < 4)
	{
		place = tet_piece->pos[i];
		place.x += diffx;
		place.y += diffy;
		fillit_grid->pos[place.y - 1][place.x - 1] = tet_piece->letter;
		i++;
	}
	return (fillit_grid);
}

void	clear_piece(grid *fillit_grid, piece *tet_piece)
{
	char	letter;
	coord	pos;

	pos.x = 1;
	pos.y = 1;
	letter = tet_piece->letter;
	while (pos.x <= fillit_grid->smallest ||
			pos.y <= fillit_grid->smallest)
	{
		pos.x = 1;
		while (pos.x <= fillit_grid->smallest)
		{
			if (fillit_grid->pos[pos.y - 1][pos.x - 1] == letter)
				fillit_grid->pos[pos.y - 1][pos.x - 1] = '.';
			pos.x++;
		}
		pos.y++;
	}
}

void	fillit(slider *total)
{
	grid	*fillit_grid;
	int		smallest;
	coord	start;
	coord	*next;

	start.x = 1;
	start.y = 1;
	smallest = smallest_square(total);
	fillit_grid = grid_init(smallest);
	next = get_next_pos(&start, fillit_grid);
	fillit_grid = solve(fillit_grid, next, total);
	print_grid(fillit_grid);
}
