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

#include "fillit.h"

int	smallest_square(slider *total)
{
	int smallest;

	smallest = 1;
	if (total->size == 1)
		smallest = 2;
	else if (total->size == 2)
		smallest = 3;
	else if (total->size == 3)
		smallest = 4;
	else if (total->size == 4)
		smallest = 4;
	else if (total->size == 5)
		smallest = 5;
	else if (total->size == 6)
		smallest = 5;
	else if (total->size == 7)
		smallest = 6;
	else if (total->size == 8)
		smallest = 6;
	return (smallest);
}

//int	check_map()
//{
//
//}

grid	*grid_init(int smallest)
{

}
