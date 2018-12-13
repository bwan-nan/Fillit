/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:58:25 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/12/13 18:27:06 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					ft_count_block(char *str)
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			result++;
		i++;
	}
	return (result / 4);
}

static t_block		*ft_create_block(char *str, char letter)
{
	t_block		*new_block;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(new_block = (t_block *)malloc(sizeof(t_block))))
		return (NULL);
	else
	{
		while (i < 21)
		{
			if (str[i] == '#')
			{
				new_block->x[j] = i % 5;
				new_block->y[j] = i / 5;
				j++;
			}
			i++;
		}
		new_block->c = letter;
		new_block->next = NULL;
	}
	return (new_block);
}

static void			load_block(t_block **block, char *str, char letter)
{
	t_block *tmp;

	if (*block == NULL)
		*block = ft_create_block(str, letter);
	else
	{
		tmp = *block;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_block(str, letter);
	}
}

t_block				*launcher(char *str)
{
	t_block		*blocks_list;
	int			count;
	char		letter;
	int			i;

	blocks_list = NULL;
	count = ft_count_block(str);
	i = 0;
	letter = 65;
	while (count--)
	{
		load_block(&blocks_list, str + i, letter);
		letter++;
		i += 21;
	}
	return (blocks_list);
}

char				*ft_read(char *file_name, char **line, char *tmp, int len)
{
	int		fd;
	char	*str;

	str = NULL;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, line))
	{
		len = ft_strlen(*line);
		if (!str)
			str = ft_strdup(*line);
		else
		{
			tmp = str;
			str = ft_strjoin(str, *line);
			free(tmp);
			len = ft_strlen(str);
		}
		str[len] = '\n';
		str[len + 1] = '\0';
		ft_strdel(line);
	}
	close(fd);
	if (str == NULL)
		return ("error");
	return (str);
}
