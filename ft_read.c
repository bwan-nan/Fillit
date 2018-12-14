/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwan-nan <bwan-nan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:58:25 by bwan-nan          #+#    #+#             */
/*   Updated: 2018/12/14 15:59:18 by bwan-nan         ###   ########.fr       */
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
	int			k;

	i = 0;
	k = 0;
	if (!(new_block = (t_block *)malloc(sizeof(t_block))))
		return (NULL);
	while (i < 21)
	{
		if (str[i] == '#')
		{
			new_block->x[k] = i % 5;
			new_block->y[k] = i / 5;
			k++;
		}
		i++;
	}
	new_block->c = letter;
	new_block->next = NULL;
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

t_block				*launcher(t_block **blocks_list, char *str)
{
	int			count;
	char		letter;
	int			i;

	count = ft_count_block(str);
	i = 0;
	letter = 65;
	while (count--)
	{
		load_block(blocks_list, str + i, letter);
		letter++;
		i += 21;
	}
	return (*blocks_list);
}

char				*ft_read(int *fd)
{
	char	*str;
	char	*tmp;
	char	*line;

	str = NULL;
	tmp = NULL;
	line = NULL;
	if (*fd == -1)
		return ("error");
	while (get_next_line(*fd, &line))
	{
		if (!str)
			str = ft_strdupendl(line);
		else
		{
			tmp = str;
			str = ft_strjoinendl(str, line);
			free(tmp);
		}
		ft_strdel(&line);
	}
	if (str == NULL)
		return ("error");
	return (str);
}
