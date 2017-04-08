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

int		chk_map(grid *fillit_grid, coord *start, piece *tet_piece)
{
	int i;
	coord check;
	
	if (start->x == -1 && start->y == -1)
		return (-1);
	i = 0;
	while (i < 4)
	{
		check = tet_piece->pos[i];
		check.x += start->x - 1;
		check.y += start->y - 1;
		if (check.x - 1 >= fillit_grid->smallest ||
			check.y - 1 >= fillit_grid->smallest)
			return (-1);
		if (fillit_grid->pos[check.y - 1][check.x - 1] != '.')
			return (-1);
		i++;
	}
	return (1);
}

grid	*place(grid *fillit_grid, coord *grid_pos, piece *tet_piece)
{
	int i;
	coord place;

	i = 0;
	while (i < 4)
	{
		place = tet_piece->pos[i];
		place.x += grid_pos->x - 1;
		place.y += grid_pos->y - 1;
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
	fillit_grid = (grid *)malloc(sizeof(grid)); //need to add checks after malloc.
	pos_array = (char **)malloc((sizeof(char *) * (size)));
	while (i < size) // WE CAN REMOVE MALLOC FOR SIZE + 2 
	{
		pos_row = (char *)malloc(sizeof(char) * (size)); // WE CAN REMOVE MALLOC FOR SIZE + 2
		pos_array[i] = pos_row;
		i++;
	}
	i = 0;
	while (i < size) // WE CAN REMOVE MALLOC FOR SIZE + 2
	{
		j = 0;
		while (j < size) // WE CAN REMOVE MALLOC FOR SIZE + 2
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

void	fillit(slider *total)
{
	grid	*fillit_grid;
	int		smallest;
	int		solve_check;
	coord	*start;
	coord	*next;

	start = coord_init(1, 1);
	smallest = smallest_square(total);
	fillit_grid = grid_init(smallest);
	next = get_next_pos(start, fillit_grid);
	solve_check = solve(fillit_grid, next, total);
	while (solve_check == -1)
	{
		//free grid pos (each line), then free struct.
		fillit_grid = grid_init(fillit_grid->smallest + 1);
		print_grid(fillit_grid);
		total->index = 0;
		solve_check = solve(fillit_grid, start, total);
	}
	printf("\n");
	print_grid(fillit_grid);
}

int		solve(grid *fillit_grid, coord *next, slider *total)
{
	int check;

	if (total->index == total->size) // index ==  size means we are on the 'next' piece after placing the final piece
		return (1); // we are done
	if (total->index == -1)
		return (-1); // we need to increase grid
	check = chk_map(fillit_grid, next, total->piece_array[total->index]);
	if (check == 1)
	{
		fillit_grid = place(fillit_grid, next, total->piece_array[total->index]); // place piece
		printf("\n");
		print_grid(fillit_grid);
		fillit_grid->last[total->index].x = next->x; // set fillit_grid->last to position of block that the placed piece started at
		fillit_grid->last[total->index].y = next->y;
		next = get_next_pos(&(fillit_grid->last[total->index]), fillit_grid);
		total->index++;
		solve(fillit_grid, next, total);
	}	
	else if (check == -1)
	{
		if (next->x == -1 && next->y == -1) // IF AT THE LAST POS
		{
			total->index--;
			if (total->index == -1) // IF AT LAST POS AND AT FIRST PIECE ALREADY
				return (-1);
			clear_piece(fillit_grid, total->piece_array[total->index]); // clear last piece placed
			next = &(fillit_grid->last[total->index]);
			printf("\n");
			print_grid(fillit_grid);
		}
		else if (fillit_grid->last[total->index].x == -1 && fillit_grid->last[total->index].y == -1) // IF NO PIECES HAVE BEEN PLACED
			return (-1);
		
		next = get_next_coord(next, fillit_grid);
		next = get_next_pos(next, fillit_grid);
		solve(fillit_grid, next, total);
	}
	return (1);
}