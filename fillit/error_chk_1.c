/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_chk_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:16:51 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/22 19:17:00 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file includes the error checking found in main.c:
**
**		- error_chk() to generically return "error".
**		- usage() to display usage if # args is not 2.
**		- buf_chk() checks that every tet is 4 lines of 4 char,
**					that each tet is seperated by a \n,
**					and that each file has a max of 26 tet and a min of 1.
*/

#include "fillit.h"

int	usage(int argc)
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

int	buf_chk(char *buf, int nb_newlines)
{
	int	pos;
	int row;

	while (*buf)
	{
		row = 0;
		while (++row < 5)
		{
			pos = -1;
			while (pos++ < 3)
			{
				if (!(*buf == '.' || *buf == '#'))
					return (-1);
				buf++;
			}
			nb_newlines = newline(buf, nb_newlines);
			if (*buf != '\n' && *buf)
				return (-1);
			buf++;
		}
		nb_newlines = newline(buf, nb_newlines);
		if (*buf == '\0')
			return (nb_newlines < 130 ? 1 : -1);
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

int	total_error(t_slider *total)
{
	if (total == NULL)
	{
		ft_putstr("error\n");
		return (-1);
	}
	return (0);
}
