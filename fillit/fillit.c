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

	if (start.x == -1 && start.y == -1)
		return (start);
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
	pos.x = - 1;
	pos.y = - 1;
	return (pos);
}

coord	get_next_coord(coord start, grid *fillit_grid)
{
	coord pos;

	if (start.x == -1 && start.y == -1)
		return (start);
	if (start.x < fillit_grid->smallest)
	{
		pos.x = start.x + 1;
		pos.y = start.y;
	}
	else if (start.x == fillit_grid->smallest && start.y < fillit_grid->smallest)
	{
		pos.x = 1;
		pos.y = start.y + 1;
	}
	pos.x = - 1;
	pos.y = - 1;
	return (pos);
}

int		chk_map(grid *fillit_grid, coord start, piece *tet_piece)
{
	int i;
	coord check;
	
	if (start.x == -1 && start.y == -1)
		return (-1);
	i = 0;
	while (i < 4)
	{
		check = tet_piece->pos[i];
		check.x += start.x - 1;
		check.y += start.y - 1;
		if (check.x - 1 >= fillit_grid->smallest ||
			check.y - 1 >= fillit_grid->smallest)
			return (-1);
		if (fillit_grid->pos[check.y - 1][check.x - 1] != '.')
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
	fillit_grid = (grid *)malloc(sizeof(grid)); //need to add checks after malloc.
	pos_array = (char **)malloc((sizeof(char *) * (size + 2)));
	while (i < size + 2) // WE CAN REMOVE MALLOC FOR SIZE + 2 
	{
		pos_row = (char *)malloc(sizeof(char) * (size + 2)); // WE CAN REMOVE MALLOC FOR SIZE + 2
		pos_array[i] = pos_row;
		i++;
	}
	i = 0;
	while (i < size + 2) // WE CAN REMOVE MALLOC FOR SIZE + 2
	{
		j = 0;
		while (j < size + 2) // WE CAN REMOVE MALLOC FOR SIZE + 2
		{
			pos_array[i][j] = '.';
			j++;
		}
		i++;
	}
	fillit_grid->pos = pos_array;
	fillit_grid->smallest = size;
	fillit_grid->last.x = -1;
	fillit_grid->last.y = -1;
	return (fillit_grid);
}

void	fillit(slider *total)
{
	grid	*fillit_grid;
	int		smallest;
	int		solve_check;
	coord	start;
	coord	next;

	start.x = 1;
	start.y = 1;
	smallest = smallest_square(total);
	fillit_grid = grid_init(smallest);
	next = get_next_pos(start, fillit_grid);
	solve_check = solve(fillit_grid, next, total);
	while (solve_check == -1)
	{
		//free grid pos (each line), then free struct.
		printf("SMALLEST: %i\n", fillit_grid->smallest);
		fillit_grid = grid_init(fillit_grid->smallest + 1);
		print_grid(fillit_grid);
		printf("SMALLEST: %i\n", fillit_grid->smallest);
		total->index = 0;
		printf("TOTAL SIZE: %i\nTOTAL INDEX: %i\n", total->size, total->index);
		solve_check = solve(fillit_grid, start, total);
		printf("SOLVE CHECK: %i\n", solve_check);
	}
	printf("AFTER SOLVE\n");
	print_grid(fillit_grid);
}

int		solve(grid *fillit_grid, coord next, slider *total)
{
	int check;
	static int test = 1;

	if (total->index == total->size) // index ==  size means we are on the 'next' piece after placing the final piece
		return (1); // we are done
	if (total->index == -1)
		return (-1); // we need to increase grid
	check = chk_map(fillit_grid, next, total->piece_array[total->index]);
	//check = 1;
	if (test == 1)
	{
		printf("CHK_MAP: %i\n", check);
		test = 0;
	}
	if (check == 1)
	{
		printf("CHK_MAP: %i\n", check);
		fillit_grid = place(fillit_grid, next, total->piece_array[total->index]); // place piece
		print_grid(fillit_grid);
		printf("NEXT: %i,%i\n", next.x, next.y);
		fillit_grid->last = next; // set fillit_grid->last to position of block that the placed piece started at
		total->index++;
		printf("INDEX: %i\n", total->index);
		next = get_next_pos(fillit_grid->last, fillit_grid);
		printf("NEXT: %i,%i\n", next.x, next.y);
		solve(fillit_grid, next, total);
	}	
	else if (check == -1)
	{
		//printf("CHK_MAP: %i\n", check);
		if (next.x == -1 && next.y == -1) // IF AT THE LAST POS
		{
			total->index--;
			if (total->index == -1) // IF AT LAST POS AND AT FIRST PIECE ALREADY
				return (-1);
				//solve(fillit_grid, next, total);
			clear_piece(fillit_grid, total->piece_array[total->index]); // clear last piece placed
		}
		if (fillit_grid->last.x == -1 && fillit_grid->last.y == -1) // IF NO PIECES HAVE BEEN PLACED
		{
			printf("LAST = -1\n");
			return (-1);
		}
		next = get_next_coord(next, fillit_grid);
		next = get_next_pos(next, fillit_grid);
		solve(fillit_grid, next, total);
	}
	return (1);
}