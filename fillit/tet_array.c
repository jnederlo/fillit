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
	piece			**head;
	int				size_array;
	char			letter;

	letter = 65;
	size_array = count_pieces(buf);
	if (size_array == -1)
		return (NULL);
	total = (slider *)malloc(sizeof(slider));
	if (!total)
		return (0);
	total->size = size_array;
	piece_array = (piece **)malloc(sizeof(piece *) * size_array);
	if (!piece_array)
		return (0);
	head = piece_array;
	while (size_array--)
	{
		*piece_array = tet_piece(buf, letter);
		if (*piece_array == 0)
			return (0);
		letter++;
		piece_array++;
		buf += 21;
	}
	total->piece_array = head;
	return (total);
}

piece	*tet_piece(char *buf, char letter)
{
	int		i;
	int		j;
	piece	*tetrimino;

	i = 0;
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
