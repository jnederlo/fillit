/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_shapes_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:16:51 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/22 19:17:00 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	shape_1(t_piece *tetrimino)
{
	if ((tetrimino->pos[0].y == 1 && tetrimino->pos[0].x == 2) &&
		(tetrimino->pos[1].y == 2 && tetrimino->pos[1].x == 1) &&
		(tetrimino->pos[2].y == 2 && tetrimino->pos[2].x == 2) &&
		(tetrimino->pos[3].y == 2 && tetrimino->pos[3].x == 3))
		return (1);
	return (0);
}

int	shape_2(t_piece *tetrimino)
{
	if ((tetrimino->pos[0].y == 1 && tetrimino->pos[0].x == 2) &&
		(tetrimino->pos[1].y == 2 && tetrimino->pos[1].x == 1) &&
		(tetrimino->pos[2].y == 2 && tetrimino->pos[2].x == 2) &&
		(tetrimino->pos[3].y == 3 && tetrimino->pos[3].x == 2))
		return (1);
	return (0);
}

int	shape_3(t_piece *tetrimino)
{
	if ((tetrimino->pos[0].y == 1 && tetrimino->pos[0].x == 1) &&
		(tetrimino->pos[1].y == 1 && tetrimino->pos[1].x == 2) &&
		(tetrimino->pos[2].y == 1 && tetrimino->pos[2].x == 3) &&
		(tetrimino->pos[3].y == 2 && tetrimino->pos[3].x == 2))
		return (1);
	return (0);
}

int	shape_4(t_piece *tetrimino)
{
	if ((tetrimino->pos[0].y == 1 && tetrimino->pos[0].x == 1) &&
		(tetrimino->pos[1].y == 2 && tetrimino->pos[1].x == 1) &&
		(tetrimino->pos[2].y == 2 && tetrimino->pos[2].x == 2) &&
		(tetrimino->pos[3].y == 3 && tetrimino->pos[3].x == 1))
		return (1);
	return (0);
}

int	shape_5(t_piece *tetrimino)
{
	if ((tetrimino->pos[0].y == 1 && tetrimino->pos[0].x == 1) &&
		(tetrimino->pos[1].y == 1 && tetrimino->pos[1].x == 2) &&
		(tetrimino->pos[2].y == 2 && tetrimino->pos[2].x == 1) &&
		(tetrimino->pos[3].y == 2 && tetrimino->pos[3].x == 2))
		return (1);
	return (0);
}
