/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:15:28 by cnotin            #+#    #+#             */
/*   Updated: 2018/12/12 20:08:25 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>


int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	*tmp;
	int		len;
	char	*str;
	t_block *blocks_list;

	line = NULL;
	str = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		ft_putendl("fillit source_file");
	if (ac == 2)
	{
		while (get_next_line(fd, &line))
		{
			if (!str)
			{
				len = ft_strlen(line);
				str = ft_memalloc(sizeof(char) * (len + 1));
				str = ft_strcpy(str, line);
				str[len] = '\n';
				str[len + 1] = '\0';
			}
			else
			{
				tmp = str;
				str = ft_strjoin(str, line);
				free(tmp);
				len = ft_strlen(str);
				tmp = str;
				str = ft_memalloc(sizeof(char) * (len + 1));
				str = ft_strcpy(str, tmp);
				free(tmp);
				str[len] = '\n';
				str[len + 1] = '\0';
			}
			ft_strdel(&line);
		}
		ft_putendl(str);
	//	printf("%zu\n", ft_strlen(str));
	//	printf("%d\n", ft_count_block(str));
		if (ft_check_file(str))
		{
			ft_putendl("\033[32mOK\033[0m");

			blocks_list = launcher(str);
			char **map = NULL;
			int l = 2;
			map = ft_block_map(map, l);
			while (backtracking(map, &blocks_list, 0, l) == 0)
			{
				l++;
				ft_delmap(&map);
				map = ft_block_map(map, l);
			}
			ft_putstr("\n\n\n");
			ft_display_map(map);
			ft_putchar('\n');
		}
		else
		{
			ft_putendl("\033[31merror\033[0m");
		}
	}
	close (fd);
	return (0);
}
