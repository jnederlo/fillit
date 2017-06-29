/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnederlo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:39:59 by jnederlo          #+#    #+#             */
/*   Updated: 2017/03/23 13:40:11 by jnederlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	print_grid(t_grid *fillit_grid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < fillit_grid->smallest)
	{
		j = 0;
		while (j < fillit_grid->smallest)
		{
			ft_putchar(fillit_grid->pos[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
