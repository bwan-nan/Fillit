/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:07:07 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/12/13 18:19:34 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				get_y_vector(t_block **block, int to_y)
{
	return (to_y - (*block)->y[0]);
}

int				get_x_vector(t_block **block, int to_x)
{
	return (to_x - (*block)->x[0]);
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
		if (i > size - 1 || j > size - 1 || map[i][j] != '.'
				|| i < 0 || j < 0)
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
	while (position != size * size)
	{
		y = position / size;
		x = position % size;
		if (is_placeable(map, block, x, y) != 1)
			return (backtracking(map, block, position + 1, size));
		else if (is_placeable(map, block, x, y))
		{
			map = ft_put_block(map, block, get_x_vector(block, x),
					get_y_vector(block, y));
			if (backtracking(map, &((*block)->next), 0, size))
				return (1);
			map = ft_del_block(map, block, size);
		}
		position += 1;
	}
	return (0);
}
