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

# define BUF_SIZE 567
# define RESET	"\033[0m"
# define BLUE	"\033[34m"
# define GREEN	"\033[32m"
# define BOLDRED	"\033[1m\033[31m"
# define BOLDCYAN    "\033[1m\033[36m"

static const int g_smallest_square[26] = {2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7,
		 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11};

typedef struct		s_coord
{
	int	x;
	int	y;
}					coord;

typedef struct		s_tetrimino
{
	coord	pos[4];
	char	letter;
}					piece;

typedef struct		s_tetarray
{
	piece	**piece_array;
	int		size;
	int		index;
}					slider;

typedef struct		s_grid 	// AN ARRAY OF POSITIONS AS 'EMPTY' OR 'FILLED'
{
	int			smallest;
	char		**pos;
	coord		*last;
}					grid;

int					open_file(char *file);
int					read_file(int fd, char *buf);
int					error_chk(int error_val);
slider				*tet_array(char *buf);
void				test_print(slider *total);
int					count_pieces(char *buf);
piece				*tet_piece(char *buf, char letter);
piece				*piece_init(piece *tetrimino);
piece				*piece_set(piece *tetrimino, char *buf, int i, int j);
int					buf_chk(char *buf);
int					valid_chk(char *buf);
int					usage(int argc);
int					newline(char *buf, int nb_newlines);
int					in_contact(piece *tetriminio);
int					smallest_square(slider *total);
coord				*get_next_pos(coord *start, grid *fillit_grid);
coord				*get_next_coord(coord *start, grid *fillit_grid);
int					chk_map(grid *fillit_grid, coord *start, piece *tet_piece);
grid				*place(grid *fillit_grid, coord *grid_pos, piece *tet_piece);
void				clear_piece(grid *fillit_grid, piece *tet_piece);
grid				*grid_init(int size);
coord				*coord_array_init(int size);
void				fillit(slider *total);
int					solve(grid *fillit_grid, coord *next, slider *total);
void				print_grid(grid *fillit);
int					shape_1(piece *tetrimino);
int					shape_2(piece *tetrimino);
int					shape_3(piece *tetrimino);
int					shape_4(piece *tetrimino);
int					shape_5(piece *tetrimino);
int					shape_6(piece *tetrimino);
int					shape_7(piece *tetrimino);
int					shape_8(piece *tetrimino);
int					shape_9(piece *tetrimino);
int					shape_10(piece *tetrimino);
int					shape_11(piece *tetrimino);
int					shape_12(piece *tetrimino);
int					shape_13(piece *tetrimino);
int					shape_14(piece *tetrimino);
int					shape_15(piece *tetrimino);
int					shape_16(piece *tetrimino);
int					shape_17(piece *tetrimino);
int					shape_18(piece *tetrimino);
int					shape_19(piece *tetrimino);
piece				*piece_min(piece *tetrimino);

#endif
