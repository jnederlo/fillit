/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 17:58:50 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/15 19:28:54 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

piece	**tet_array(char *buf)
{
	piece			**piece_array;
	unsigned int	size_array;

	size_array = count_pieces(buf);
	piece_array = (piece **)malloc(sizeof(piece *) * size_array);
	return (piece_array);
}

piece	*tet_piece(char *buf)
{
	int		i;
	int		column;
	piece	*tetrimino;
	int		row;
	int		piece_coord;

	i = 0;
	column = 0;
	row = 1;
	piece_coord = 0;
	while (i < 20)
	{
		if (buf[i] == '.')
		{
			i++;
			column++;
		}
		else if (buf[i] == '#')
		{
			piece_coord++;// Does This Work??
			tetrimino.member[piece_coord] = {row, column};//don't know what member would be
			i++;
			column++;
		}
		else if (buf[i] == '\n')
		{
			column = 0;
			i++;
			row++;
		}
	}
	return (tetrimino);
}


piece	*bit_init(piece *tetrimino)
{
	tetrimino = (piece *)malloc(sizeof(peice));
	ft_bzero(tetrimino, sizeof(piece));
	return (tetrimino);
}

int		count_pieces(char *buf)
{
	int count;
	int error;

	count = 0;
	error = 1;
	while (error)
	{
		// ERROR CHECK TO VERIFY PIECE
		buf += 21;// I think this should be 20 b/c buff starts at 0??
		if (*buf == '\n')
			count++;
		else if (*buf == '\0')
		{
			count++;
			return (count);
		}
	}
	return (-1); // RETURN ON ERROR
}
