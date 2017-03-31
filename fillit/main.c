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
	char	*file;
	int		fd;
	char	*buf;
	int		bytes_read;
	int		close_return;
	slider	*total;

	if (argc != 2)
		return (0);
	file = argv[1];
	fd = open_file(file);
	if (error_chk(fd) == -1)
		return (0);
	buf = ft_strnew(BUF_SIZE);
	bytes_read = read_file(fd, buf);
	if (error_chk(bytes_read) == -1)
		return (0);
	if (error_chk(buf_chk(buf)) == -1)
		return (0);
	total = tet_array(buf);
	if (total == NULL)
	{
		ft_putstr("error\n");
		return (-1);
	}
	free(buf);
	test_print(total);
	close_return = close(fd);
	if (error_chk(close_return) == -1)
		return (0);
	return (0);
}
