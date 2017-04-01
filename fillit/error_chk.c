
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

// ADDED THIS FUNCTION HERE
int	in_contact(piece *tetrimino)
{
	int	i;
	int	pos;

	i = 1;
	pos = 1;
	while (pos < 5)
	{
		if (tetrimino->pos[i].x == tetrimino->pos[i].x + 1
			|| tetrimino->pos[i].y == tetrimino->pos[i].y +1
			|| tetrimino->pos[i].y == tetrimino->pos[i].y - 1)
			return (0);
		else 
			return (-1);
		pos++;
		i++;
	}
	return (0);
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
