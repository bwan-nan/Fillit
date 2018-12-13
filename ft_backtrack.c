/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:07:07 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/12/13 09:33:33 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int		get_y_vector(t_block **block, int from_y)
{
	return (from_y - (*block)->y[0]);
}

static int		get_x_vector(t_block **block, int from_x)
{
	return (from_x - (*block)->x[0]);
}

static int		is_placeable(char **map, t_block **elem, int x, int y)
{
	int			k;
	int			i;
	int			j;
	int			size;
	
	k = 0;
	size = ft_strlen(map[0]);
	while (k < 4)
	{
		i = (*elem)->y[k] + get_y_vector(elem, y);
		j = (*elem)->x[k] + get_x_vector(elem, x);
		if (i > size - 1 || j > size - 1 || map[i][j] != '.')
		   return (0);	
		k++;
	}
	return (1);
}

int				backtracking(char **map, t_block **block,
				int position, int size)
{
	int					x;
	int					y;

	if (*block == NULL)
		return (1);
	y = position / size;
	x = position % size;
	printf("passing with : Position = %d, size = %d, letter = %c\n", position, size, (*block)->c);
	ft_display_map(map);
	while (position != size * size)
	{
		y = position / size;
		x = position % size;
		if (is_placeable(map, block, x, y) != 1)
			return (backtracking(map, block, position + 1, size));
		else if (is_placeable(map, block, x, y))
		{
			map = ft_put_block(map, block, get_x_vector(block, x), get_y_vector(block, y));
			ft_display_map(map);
			if (backtracking(map, &((*block)->next), 0, size))
				return (1);
			map = ft_del_block(map, block, size);
		}
		position += 1;
	}
	return (0);
}	
