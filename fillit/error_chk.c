
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
			pos = 0;
			while (pos < 4)
			{
				if (!(*buf == '.' || *buf == '#'))
					return (-1);
				buf++;
				pos++;
			}
			if (*buf == '\n')
				nb_newlines++;
			else if (*buf)
				return (-1);
			buf++;
			row++;
		}
		if (*buf == '\n')
			nb_newlines++;
		else if (*buf == '\0')
		{
			if (nb_newlines < 130)
				return (1);
			return (-1);
		}
		buf++;
	}
	return (-1);
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
