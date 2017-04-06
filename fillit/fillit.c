/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
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

coord	get_next_pos(coord start, grid *fillit_grid)
{
	int x;
	int y;
	int check;
	coord pos;

	check = 0;
	x = start.x;
	y = start.y;
	while (x <= fillit_grid->smallest || y <= fillit_grid->smallest)
	{
		if (check) // MAKE SURE LOOP RUNS ONCE BEFORE SETTING x = 1
			x = 1;
		while (x <= fillit_grid->smallest)
		{
			if (fillit_grid->pos[y - 1][x - 1] == '.')
			{
				pos.x = x;
				pos.y = y;
				return (pos);
			}
			x++;
		}
		check = 1;
		y++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}

int		chk_map(coord start, grid *fillit_grid, piece *tet_piece)
{
	int i;
	coord check;

	i = 0;
	while (i < 4)
	{
		check = tet_piece->pos[i];
		check.x += start.x;
		check.y += start.y;
		if (check.x > fillit_grid->smallest ||
			check.y > fillit_grid->smallest)
			return (-1);
		if (fillit_grid->pos[check.y - 2][check.x - 2] != '.')
			return (-1);
		i++;
	}
	return (1);
}

grid	*place(grid *fillit_grid, coord grid_pos, piece *tet_piece)
{
	int i;
	coord place;

	i = 0;
	while (i < 4)
	{
		place = tet_piece->pos[i];
		place.x += grid_pos.x - 1;
		place.y += grid_pos.y - 1;
		fillit_grid->pos[place.y - 1][place.x - 1] = tet_piece->letter;
		i++;
	}
	return (fillit_grid);
}

void	clear_piece(grid *fillit_grid, piece *tet_piece)
{
	char letter;
	coord pos;

	pos.x = 1;
	pos.y = 1;
	letter = tet_piece->letter;
	while (pos.x <= fillit_grid->smallest || pos.y <= fillit_grid->smallest)
	{
		pos.x = 1;
		while (pos.x <= fillit_grid->smallest)
		{
			if(fillit_grid->pos[pos.y - 1][pos.x - 1] == letter)
				fillit_grid->pos[pos.y - 1][pos.x - 1] = '.';
			pos.x++;
		}
		pos.y++;
	}
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
	pos_array = (char **)malloc((sizeof(char *) * (size + 2)));
	while (i < size + 2)
	{
		pos_row = (char *)malloc(sizeof(char) * (size + 2));
		pos_array[i] = pos_row;
		i++;
	}
	i = 0;
	while (i < size + 2)
	{
		j = 0;
		while (j < size + 2)
		{
			pos_array[i][j] = '.';
			j++;
		}
		i++;
	}
	fillit_grid->pos = pos_array;
	fillit_grid->smallest = size;
	return (fillit_grid);
}

void	fillit(slider *total)
{
	grid	*fillit_grid;
	int		size;
	coord	start;
	coord	next;

	start.x = 1;
	start.y = 1;
	size = smallest_square(total);
	fillit_grid = grid_init(size);
	next = get_next_pos(start, fillit_grid);
	printf("chk_map: %i\n", chk_map(next, fillit_grid, total->piece_array[3]));
	printf("\nget_next_pos: %i,%i\n", next.x, next.y);
	print_grid(fillit_grid);
	fillit_grid = place(fillit_grid, next, total->piece_array[3]);
	next = get_next_pos(next, fillit_grid);
	printf("chk_map: %i\n", chk_map(next, fillit_grid, total->piece_array[3]));
	printf("\nget_next_pos: %i,%i\n", next.x, next.y);
	print_grid(fillit_grid);
	fillit_grid = place(fillit_grid, next, total->piece_array[0]);
	next = get_next_pos(next, fillit_grid);
	printf("chk_map: %i\n", chk_map(next, fillit_grid, total->piece_array[3]));
	printf("\nget_next_pos: %i,%i\n", next.x, next.y);
	print_grid(fillit_grid);
	fillit_grid = place(fillit_grid, next, total->piece_array[2]);
	next = get_next_pos(next, fillit_grid);
	printf("chk_map: %i\n", chk_map(next, fillit_grid, total->piece_array[3]));
	printf("\nget_next_pos: %i,%i\n", next.x, next.y);
	fillit_grid = place(fillit_grid, next, total->piece_array[1]);
	print_grid(fillit_grid);
}
