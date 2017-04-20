/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:16:51 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/22 19:17:00 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** BUF_SIZE is defined in the header as 1024.
*/

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		nb_newlines;
	char	*buf;
	slider	*total;

	if (usage(argc) == -1)
		return (0);
	fd = open_file(argv[1]);
	if (error_chk(fd) == -1)
		return (0);
	buf = ft_strnew(BUF_SIZE);
	if (error_chk(read_file(fd, buf)) == -1)
		return (0);
	nb_newlines = 0;
	if (error_chk(buf_chk(buf, nb_newlines)) == -1)
		return (0);
	total = tet_array(buf);
	if (total_error(total) == -1)
		return (0);
	free(buf);
	fillit(total);
	if (error_chk(close(fd)) == -1)
		return (0);
	return (0);
}
