/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_chk_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:16:51 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/22 19:17:00 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file includes the error checking in tet_array.c and piece_config.c:
**
**		- valid_chk() checks that each tet has precisely 4 blocks, and that
**					each character is either a '#' or a '.'
**		- in_contact() checks to make sure that each block of tets must be
**					in contact with at least 1 other block on each of
**					it's 4 sides.
*/

#include "../includes/fillit.h"

int	valid_chk(char *buf)
{
	int pos;
	int column;
	int hashtag;

	pos = 0;
	hashtag = 0;
	while (pos < 18)
	{
		column = 0;
		while (column < 4)
		{
			if (!(buf[pos] == '.' || buf[pos] == '#'))
				return (-1);
			if (buf[pos] == '#')
				hashtag++;
			column++;
			pos++;
		}
		pos++;
	}
	if (hashtag != 4)
		return (-1);
	return (0);
}

int	in_contact(t_piece *tetrimino)
{
	if ((shape_1(tetrimino) == 1) || (shape_2(tetrimino) == 1) ||
		(shape_3(tetrimino) == 1) || (shape_4(tetrimino) == 1) ||
		(shape_5(tetrimino) == 1) || (shape_6(tetrimino) == 1) ||
		(shape_7(tetrimino) == 1) || (shape_8(tetrimino) == 1) ||
		(shape_9(tetrimino) == 1) || (shape_10(tetrimino) == 1) ||
		(shape_11(tetrimino) == 1) || (shape_12(tetrimino) == 1) ||
		(shape_13(tetrimino) == 1) || (shape_14(tetrimino) == 1) ||
		(shape_15(tetrimino) == 1) || (shape_16(tetrimino) == 1) ||
		(shape_17(tetrimino) == 1) || (shape_18(tetrimino) == 1) ||
		(shape_19(tetrimino) == 1))
		return (0);
	else
		return (-1);
}
