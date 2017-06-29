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
# include "../libft/libft.h"
# include <stdlib.h>

# define BUF_SIZE 567

static const int g_smallest_square[26] = {2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7,
	8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11};

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_tetrimino
{
	t_coord	pos[4];
	char	letter;
}				t_piece;

typedef struct	s_tetarray
{
	t_piece	**p_array;
	int		size;
	int		index;
}				t_slider;

typedef struct	s_grid
{
	int			smallest;
	char		**pos;
	t_coord		*last;
	int			flag;
}				t_grid;

int				open_file(char *file);
int				read_file(int fd, char *buf);
int				error_chk(int error_val);
t_slider		*tet_array(char *buf);
void			test_print(t_slider *total);
int				count_pieces(char *buf);
t_piece			*tet_piece(char *buf, char letter);
t_piece			*piece_init(t_piece *tetrimino);
t_piece			*piece_set(t_piece *tetrimino, char *buf, int i, int j);
int				buf_chk(char *buf, int nb_newlines);
int				valid_chk(char *buf);
int				usage(int argc);
int				total_error(t_slider *total);
int				newline(char *buf, int nb_newlines);
int				in_contact(t_piece *tetriminio);
int				smallest_square(t_slider *total);
t_coord			*get_next_pos(t_coord *start, t_grid *f_grid);
t_coord			*get_next_coord(t_coord *start, t_grid *f_grid);
int				chk_map(t_grid *f_grid, t_coord *start, t_piece *tet_piece);
t_grid			*place(t_grid *f_grid, t_coord *grid_pos, t_piece *tet_piece);
void			clear_piece(t_grid *f_grid, t_piece *tet_piece);
t_grid			*grid_init(int size);
t_coord			*coord_init(int x, int y);
t_coord			*coord_array_init(int size);
int				free_grid(t_grid *f_grid, int size);
void			fillit(t_slider *total);
t_grid			*solve(t_grid *f_grid, t_coord *next, t_slider *total);
t_coord			*solve_place(t_grid *f_grid, t_coord *next, t_slider *total);
t_grid			*solve_n(t_grid *f_grid, t_slider *total);
t_coord			*solve_clear(t_grid *f_grid, t_coord *next, t_slider *total);
void			print_grid(t_grid *fillit);
int				shape_1(t_piece *tetrimino);
int				shape_2(t_piece *tetrimino);
int				shape_3(t_piece *tetrimino);
int				shape_4(t_piece *tetrimino);
int				shape_5(t_piece *tetrimino);
int				shape_6(t_piece *tetrimino);
int				shape_7(t_piece *tetrimino);
int				shape_8(t_piece *tetrimino);
int				shape_9(t_piece *tetrimino);
int				shape_10(t_piece *tetrimino);
int				shape_11(t_piece *tetrimino);
int				shape_12(t_piece *tetrimino);
int				shape_13(t_piece *tetrimino);
int				shape_14(t_piece *tetrimino);
int				shape_15(t_piece *tetrimino);
int				shape_16(t_piece *tetrimino);
int				shape_17(t_piece *tetrimino);
int				shape_18(t_piece *tetrimino);
int				shape_19(t_piece *tetrimino);
t_piece			*piece_min(t_piece *tetrimino);

#endif
