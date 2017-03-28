/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:39:59 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/23 13:40:11 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <stdlib.h>

# define BUF_SIZE 550

typedef struct point	

typedef struct		s_tetrimino
{
	coord	pos_1;
	coord	pos_2;
	coord	pos_3;
	coord	pos_4;
}					piece;

typedef struct		s_coord
{
	int	x = 0;
	int	y = 0;
}					coord;

int					open_file(char *file);
int					read_file(int fd, char *buf);
int					error_chk(int error_val);
piece				**tet_array(char *buf);

#endif
