
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_chk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:16:51 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/22 19:17:00 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int usage(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit target_file\n");
		return (-1);
	}
	return (0);
}

int	error_chk(int error_val)
{
	if (error_val == -1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	return (0);
}

int	in_contact(piece *tetrimino)
{
	//int	i;

	//i = 0;
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
	/*
	while (i < 3)
	{
		if (tetrimino->pos[i + 1].x == tetrimino->pos[i].x &&
			tetrimino->pos[i + 1].y == tetrimino->pos[i].y + 1)
			i++;
		else if (tetrimino->pos[i + 1].y == tetrimino->pos[i].y &&
			tetrimino->pos[i + 1].x == tetrimino->pos[i].x + 1)
			i++;
		else if (tetrimino->pos[i + 1].y == tetrimino->pos[i].y &&
			tetrimino->pos[i + 1].x == tetrimino->pos[i].x - 1)
			i++;
		else 
			return (-1);
	}
	return (0);
	*/
}

int	buf_chk(char *buf)
{
	int	pos;
	int nb_newlines;
	int row;

	nb_newlines = 0;
	while (*buf)
	{
		row = 1;
		while (row < 5)
		{
			pos = -1;
			while (pos++ < 3)
			{
				if (!(*buf == '.' || *buf == '#'))
					return (-1);
				buf++;
			}
			if (*buf == '\n' ? nb_newlines = newline(buf, nb_newlines) : 0);
			else if (*buf)
				return (-1);
			buf++;
			row++;
		}
		nb_newlines = newline(buf, nb_newlines);
		if (*buf == '\0')
			return nb_newlines < 130 ? 1 : -1;
		buf++;
	}
	return (-1);
}

int	newline(char *buf, int nb_newlines)
{
	if (*buf == '\n')
		nb_newlines++;
	return (nb_newlines);
}

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
