/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:16:51 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/22 19:17:00 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// need to compile with ft_putstr.c, ft_putchar.c, ft_strnew.c, ft_bzero.c
// BUF_SIZE is defined in the header as 1024.

#include "fillit.h"

int	main()
{
	int		fd;
	char	*buf;
//	size_t	read_bytes;

	fd = open("example_fillit", O_RDONLY);
	if (fd == -1)
		ft_putstr("error\n"); //this is probably wrong.
	buf = ft_strnew(BUF_SIZE);
	ft_bzero(buf, BUF_SIZE);
	if (!(read(fd, buf, BUF_SIZE)))
		return -1;
	while (*buf)
	{
		write (1, buf, 1);
		buf++;
	}
	close(fd); //need to add error checking.
	return (0);
}
