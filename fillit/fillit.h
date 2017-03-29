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

typedef struct		s_coord
{
	int	x;
	int	y;
}					coord;

typedef struct		s_tetrimino
{
	coord pos[4];
}					piece;

typedef struct		s_tetarray
{
	piece	**piece_array;
	int		size;
}					slider;

int					open_file(char *file);
int					read_file(int fd, char *buf);
int					error_chk(int error_val);
slider				*tet_array(char *buf);
void				test_print(slider *total);
int					count_pieces(char *buf);
piece				*tet_piece(char *buf);
piece				*piece_init(piece *tetrimino);

#endif
