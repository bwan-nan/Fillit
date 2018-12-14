/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:46:14 by cnotin            #+#    #+#             */
/*   Updated: 2018/12/13 15:15:12 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_delmap(char ***map)
{
	if (**map)
	{
		free(**map);
		(void)**map;
	}
}

char			**ft_block_map(char **map, int size)
{
	int pos_x;
	int pos_y;

	pos_y = 0;
	if (!(map = (char **)malloc(sizeof(char *) * size + 1)))
		return (0);
	while (pos_y < size)
	{
		if (!(map[pos_y] = (char *)malloc(sizeof(char) * size + 1)))
			return (0);
		pos_x = 0;
		while (pos_x < size)
		{
			map[pos_y][pos_x] = '.';
			pos_x++;
		}
		map[pos_y][pos_x] = '\0';
		pos_y++;
	}
	map[pos_y] = 0;
	return (map);
}

char			**ft_del_block(char **map, t_block **block,
				int size)
{
	int i;
	int pos_x;
	int pos_y;

	i = 0;
	pos_y = 0;
	while (pos_y < size)
	{
		pos_x = 0;
		while (pos_x < size)
		{
			if (map[pos_y][pos_x] == (*block)->c)
				map[pos_y][pos_x] = '.';
			pos_x++;
		}
		pos_y++;
	}
	return (map);
}

char			**ft_put_block(char **map,
				t_block **block, int x_vector, int y_vector)
{
	int i;
	int pos_x;
	int pos_y;

	i = 0;
	pos_y = 0;
	while (map[pos_y])
	{
		pos_x = 0;
		while (map[pos_y][pos_x])
		{
			if ((*block)->x[i] + x_vector == pos_x
					&& (*block)->y[i] + y_vector == pos_y)
			{
				map[pos_y][pos_x] = (*block)->c;
				i++;
			}
			pos_x++;
		}
		pos_y++;
	}
	return (map);
}

void			ft_display_map(char **map)
{
	int	i;

	if (map == NULL)
	{
		ft_putendl("error\n");
		return ;
	}
	i = 0;
	while (map[i] != '\0')
	{
		ft_putendl(map[i]);
		i++;
	}
}
