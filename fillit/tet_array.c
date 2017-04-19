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

/*
** This file includes functions to create space for the pieces and the array
** of strucs of pieces, and to count the number of pieces in the struct array.
*/

#include "fillit.h"

slider	*tet_array(char *buf)
{
	slider			*total;
	piece			**piece_array;
	int				i;

	total = (slider *)malloc(sizeof(slider));
	if (!total)
		return (0);
	total->size = count_pieces(buf);
	if (total->size == -1)
		return (NULL);
	piece_array = (piece **)malloc(sizeof(piece *) * total->size);
	if (!piece_array)
		return (0);
	i = 0;
	while (i < total->size)
	{
		piece_array[i] = tet_piece(buf, i + 65);
		if (piece_array[i] == 0)
			return (0);
		i++;
		buf += 21;
	}
	total->piece_array = piece_array;
	return (total);
}

piece	*tet_piece(char *buf, char letter)
{
	int		i;
	int		j;
	piece	*tetrimino;

	i = -1;
	j = 0;
	tetrimino = (piece *)malloc(sizeof(piece));
	if (!tetrimino)
		return (0);
	tetrimino = piece_init(tetrimino);
	tetrimino = piece_set(tetrimino, buf, i, j);
	if (tetrimino == 0)
		return (0);
	tetrimino->letter = letter;
	return (tetrimino);
}

int		count_pieces(char *buf)
{
	int count;
	int error;

	count = 0;
	error = 1;
	while (error != -1)
	{
		if ((error = valid_chk(buf)) == -1)
			return (-1);
		buf += 20;
		if (*buf == '\n')
		{
			count++;
			buf += 1;
		}
		else if (*buf == '\0')
		{
			count++;
			return (count);
		}
	}
	return (-1);
}
