/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_shapes_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:16:51 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/22 19:17:00 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	shape_16(piece *tetrimino)
{
	if ((tetrimino->pos[1].y == 1 && tetrimino->pos[1].x == 2) &&
		(tetrimino->pos[2].y == 1 && tetrimino->pos[2].x == 3) &&
		(tetrimino->pos[3].y == 1 && tetrimino->pos[3].x == 4) &&
		(tetrimino->pos[4].y == 2 && tetrimino->pos[4].x == 4))
		return (1);
	return (0);
}

int	shape_17(piece *tetrimino)
{
	if ((tetrimino->pos[1].y == 1 && tetrimino->pos[1].x == 2) &&
		(tetrimino->pos[2].y == 2 && tetrimino->pos[2].x == 2) &&
		(tetrimino->pos[3].y == 2 && tetrimino->pos[3].x == 3) &&
		(tetrimino->pos[4].y == 2 && tetrimino->pos[4].x == 4))
		return (1);
	return (0);
}

int	shape_18(piece *tetrimino)
{
	if ((tetrimino->pos[1].y == 1 && tetrimino->pos[1].x == 2) &&
		(tetrimino->pos[2].y == 1 && tetrimino->pos[2].x == 3) &&
		(tetrimino->pos[3].y == 2 && tetrimino->pos[3].x == 3) &&
		(tetrimino->pos[4].y == 2 && tetrimino->pos[4].x == 4))
		return (1);
	return (0);
}

int	shape_19(piece *tetrimino)
{
	if ((tetrimino->pos[1].y == 1 && tetrimino->pos[1].x == 1) &&
		(tetrimino->pos[2].y == 2 && tetrimino->pos[2].x == 1) &&
		(tetrimino->pos[3].y == 2 && tetrimino->pos[3].x == 2) &&
		(tetrimino->pos[4].y == 3 && tetrimino->pos[4].x == 2))
		return (1);
	return (0);
}