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
	int		k;
	piece	*tetrimino;
	int		row;

	i = 0;
	k = 0;
	row = 1;
	while (i < 20)
	{
		if (buf[i] == '\n')
		{
			k = 0;
			i++;
		}
		if (buf[i] == '.')
		{
			i++;
			k++;
		}
		else if (buf[i] == '#')
		{
			tetrimino.pos_1 = {row, k};
			i++;
			k++;
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
		buf += 21;
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
