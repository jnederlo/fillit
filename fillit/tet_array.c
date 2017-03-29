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
	printf ("RETURN\n");
	total = (slider *)malloc(sizeof(slider));
	total->size = size_array;
	piece_array = (piece **)malloc(sizeof(piece *) * size_array);
	head = piece_array;
	while (size_array--)
	{
		*piece_array = tet_piece(buf); //NEED TO MOVE BUF TO THE NEXT PIECE
		piece_array++;
	}
	total->piece_array = head;
	return (total);
}

piece	*tet_piece(char *buf)
{
	int		i;
	int		column;
	piece	*tetrimino;
	int		row;
	int		j;

	i = 0;
	column = 1;
	row = 1;
	j = 0;
	tetrimino = (piece *)malloc(sizeof(piece));
	tetrimino = piece_init(tetrimino);
	while (i < 19)
	{
		if (buf[i] == '.')
		{
			i++;
			column++;
		}
		else if (buf[i] == '#')
		{
			tetrimino->pos[j].x = row;
			tetrimino->pos[j].y = column;
			j++;
			i++;
			column++;
		}
		else if (buf[i] == '\n')
		{
			column = 1;
			i++;
			row++;
		}
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
	while (error)
	{
//		printf("count: %i\n", count);
//		printf("buf: %s\n", buf);
		// ERROR CHECK TO VERIFY PIECE
		buf += 19;// I think this should be 20 b/c buff starts at 0??
//		printf(buf);
		if (*buf == '\n')
			count++;
		if (*buf == '\0')
		{
			count++;
			return (count);
		}
	}
	return (-1); // RETURN ON ERROR
}
