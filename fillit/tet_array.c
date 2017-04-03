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
#include <stdio.h>

slider	*tet_array(char *buf)
{
	slider			*total;
	piece			**piece_array;
	piece			**head;
	int				size_array;

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
		*piece_array = tet_piece(buf);
		// ADDED THIS RETURN HERE
		///*
		if (*piece_array == 0)
			return (0);
		//*/
		piece_array++;
		buf += 21;
	}
	total->piece_array = head;
	return (total);
}

piece	*tet_piece(char *buf)
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
	// ADDED THIS RETURN HERE
	///*
	if (tetrimino == 0)
		return (0);
	//*/
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
	// ADDED in_contact ERROR CHECK HERE
	/*
	if (in_contact(tetrimino) == -1)
	{
		printf("in_contact is returning: %i\n", in_contact(tetrimino));
		return (0);
	}
	//*/
	
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
		buf += 19;
		if (*buf == '\n')
		{
			count++;
			buf += 2;
		}
		else if (*buf == '\0')
		{
			count++;
			return (count);
		}
	}
	return (-1);
}
