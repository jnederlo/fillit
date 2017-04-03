/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 17:58:50 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/15 19:28:54 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file includes functions to inialize each piece's coords to 0
** (in piece_init()), then it will set each piece to the correct coords
** (in piece_set()), then it will set each min row and column to 1 in each
** piece (in piece_min())
*/

#include "fillit.h"

piece	*piece_init(piece *tetrimino)
{
	coord	xy;
	int		i;

	i = 0;
	while (i < 4)
	{
		xy.x = 0;
		xy.y = 0;
		tetrimino->pos[i] = xy;
		i++;
	}
	return (tetrimino);
}

piece	*piece_set(piece *tetrimino, char *buf, int i, int j)
{
	int		column;
	int		row;

	column = 1;
	row = 1;
	while (i < 19)
	{
		if (buf[i] == '.')
			column++;
		else if (buf[i] == '#')
		{
			tetrimino->pos[j].x = column;
			tetrimino->pos[j].y = row;
			j++;
			column++;
		}
		else if (buf[i] == '\n')
		{
			column = 1;
			row++;
		}
		i++;
	}
	tetrimino = piece_min(tetrimino);
	if (in_contact(tetrimino) == -1)
		return (0);
	return (tetrimino);
}

piece	*piece_min(piece *tetrimino)
{
	int	row;
	int	i;

	row = 1;
	i = 0;
	while (row++ < tetrimino->pos[0].y)
			i++;
	tetrimino->pos[0].y = tetrimino->pos[0].y - i;
	tetrimino->pos[1].y = tetrimino->pos[1].y - i;
	tetrimino->pos[2].y = tetrimino->pos[2].y - i;
	tetrimino->pos[3].y = tetrimino->pos[3].y - i;

	while (tetrimino->pos[0].x > 1 && tetrimino->pos[1].x > 1
		&& tetrimino->pos[2].x > 1 && tetrimino->pos[3].x > 1)
		{
			tetrimino->pos[0].x = tetrimino->pos[0].x - 1;
			tetrimino->pos[1].x = tetrimino->pos[1].x - 1;
			tetrimino->pos[2].x = tetrimino->pos[2].x - 1;
			tetrimino->pos[3].x = tetrimino->pos[3].x - 1;
		}
	return (tetrimino);
}


