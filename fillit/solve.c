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

	solve = 1;
	while (solve == 1)
	{
		check = chk_map(fillit_grid, next, total->piece_array[total->index]);
		if (check == 1)
		{
			fillit_grid = place(fillit_grid, next, total->piece_array[total->index]); // place piece
			fillit_grid->last[total->index].x = next->x; // set fillit_grid->last to position of block that the placed piece started at
			fillit_grid->last[total->index].y = next->y;
			next = get_next_pos(coord_init(1, 1), fillit_grid);
			total->index++;
		}
		else if (check == -1)
		{
			if (fillit_grid->last[0].x == -1 && fillit_grid->last[0].y == -1 &&
				next->x == -1 && next->y == -1) // IF NO PIECES HAVE BEEN PLACED
			{
				fillit_grid = grid_init(free_grid(fillit_grid, total->size) + 1);
				total->index = 0;
				next = get_next_pos(coord_init(1, 1), fillit_grid);
			}
			else if (next->x == -1 && next->y == -1) // IF AT THE LAST POS
			{
	//			printf("total->index: %i\n", total->index);
				fillit_grid->last[total->index].x = -1;
				fillit_grid->last[total->index].y = -1;
				total->index--;
				if (total->index == -1) // IF AT LAST POS AND AT FIRST PIECE ALREADY
				{
					fillit_grid = grid_init(free_grid(fillit_grid, total->size) + 1);
					total->index = 0;
					next = get_next_pos(coord_init(1, 1), fillit_grid);
				}
				else
				{
					clear_piece(fillit_grid, total->piece_array[total->index]); // clear last piece placed
					next = &(fillit_grid->last[total->index]);
		//			printf("\n");
		//			print_grid(fillit_grid);
				}
			}
			next = get_next_coord(next, fillit_grid);
			next = get_next_pos(next, fillit_grid);
		}
		if (total->index == total->size) // index ==  size means we are on the 'next' piece after placing the final piece
			solve = 0; // we are done
	}
	next = free_coord(next);
	return (fillit_grid);
}

// grid		*solve(grid *fillit_grid, coord *next, slider *total)
// {
// 	int check;
	
// 	check = chk_map(fillit_grid, next, total->piece_array[total->index]);
// 	if (check == 1)
// 	{
// 	//	printf("total->index: %i\n", total->index);
// 		fillit_grid = place(fillit_grid, next, total->piece_array[total->index]); // place piece
// //		printf("\n");
// //		print_grid(fillit_grid);
// 		fillit_grid->last[total->index].x = next->x; // set fillit_grid->last to position of block that the placed piece started at
// 		fillit_grid->last[total->index].y = next->y;
// 		next = get_next_pos(coord_init(1, 1), fillit_grid);
// 		total->index++;
// 		if (total->index == total->size) // index ==  size means we are on the 'next' piece after placing the final piece
// 			return (fillit_grid); // we are done
// 		else
// 			fillit_grid = solve(fillit_grid, next, total);
// 	}	
// 	else if (check == -1)
// 	{
// 		if (fillit_grid->last[0].x == -1 && fillit_grid->last[0].y == -1 &&
// 				next->x == -1 && next->y == -1) // IF NO PIECES HAVE BEEN PLACED
// 		{
// 			fillit_grid = grid_init(free_grid(fillit_grid, total->size) + 1);
// 			total->index = 0;
// 			next = get_next_pos(coord_init(1, 1), fillit_grid);
// 			fillit_grid = solve(fillit_grid, next, total);
// 			return (fillit_grid);
// 		}
// 		else if (next->x == -1 && next->y == -1) // IF AT THE LAST POS
// 		{
// //			printf("total->index: %i\n", total->index);
// 			fillit_grid->last[total->index].x = -1;
// 			fillit_grid->last[total->index].y = -1;
// 			total->index--;
// 			if (total->index == -1) // IF AT LAST POS AND AT FIRST PIECE ALREADY
// 			{
// 				fillit_grid = grid_init(free_grid(fillit_grid, total->size) + 1);
// 				total->index = 0;
// 				next = get_next_pos(coord_init(1, 1), fillit_grid);
// 				fillit_grid = solve(fillit_grid, next, total);
// 				return (fillit_grid);
// 			}
// 			clear_piece(fillit_grid, total->piece_array[total->index]); // clear last piece placed
// 			next = &(fillit_grid->last[total->index]);
// //			printf("\n");
// //			print_grid(fillit_grid);
// 		}
// 		next = get_next_coord(next, fillit_grid);
// 		next = get_next_pos(next, fillit_grid);
// 		fillit_grid = solve(fillit_grid, next, total);
// 	}
// 	return (fillit_grid);
// }