/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:15:28 by cnotin            #+#    #+#             */
/*   Updated: 2018/12/13 18:56:35 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		do_we_expand_it(t_block **blocks_list)
{
	t_block		*elem;
	int			a;
	int			b;
	int			c;
	int			count;

	count = 0;
	elem = *blocks_list;
	while (elem)
	{
		a = elem->x[0];
		b = elem->x[1];
		c = elem->x[2];
		if (a == b && a == c)
			count++;
		a = elem->y[0];
		b = elem->y[1];
		c = elem->y[2];
		if (a == b && a == c)
			count++;
		elem = elem->next;
	}
	if (count > 0)
		return (1);
	return (0);
}

static void		solver(char *str, t_block **blocks_list)
{
	char	**map;
	int		map_width;

	map = NULL;
	if (ft_check_file(str))
	{
		*blocks_list = launcher(str);
		if (ft_find_next_sqrt(ft_count_block(str) * 4) ==
			ft_sqrt(ft_count_block(str) * 4) &&
			do_we_expand_it(blocks_list) == 1 && ft_count_block(str) > 7)
			map_width = ft_find_next_sqrt(ft_count_block(str) * 4) + 1;
		else
			map_width = ft_find_next_sqrt(ft_count_block(str) * 4);
		map = ft_block_map(map, map_width);
		while (backtracking(map, blocks_list, 0, map_width) == 0)
		{
			map_width++;
			ft_delmap(&map);
			map = ft_block_map(map, map_width);
		}
		ft_display_map(map);
	}
	else
		ft_putendl("error");
}

int				main(int ac, char **av)
{
	char	*line;
	char	*str;
	char	*tmp;
	int		fd;
	t_block *blocks_list;

	line = NULL;
	str = NULL;
	tmp = NULL;
	if (ac != 2)
		ft_putendl("./fillit source_file");
	else
	{
		fd = open(av[1], O_RDONLY);
		str = ft_read(&fd, &line, tmp);
		close(fd);
		if (ft_strcmp(str, "error") == 0)
		{
			ft_putendl("error");
			return (-1);
		}
		solver(str, &blocks_list);
		free(blocks_list);
	}
	return (0);
}
