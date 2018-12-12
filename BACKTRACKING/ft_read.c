/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 00:32:36 by cnotin            #+#    #+#             */
/*   Updated: 2018/12/12 19:16:21 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_count_block(char *str)
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







/*
   void 	ft_set_block(t_block **tmp, char *str)
   {
   int i;
   int j;

   i = 0;
   j = 0;
   while (str[i])
   {
   if (str[i] == '#')
   {
   (*tmp)->x[j] = i % 5;
   (*tmp)->y[j] = i / 5;
   j++;
   }
   i++;
   }
   }

   t_block 	*ft_stock_block(char *str)
   {
   int count_block;
   int i;
   char letter;
   t_block *stock;
   t_block *tmp;

   i = 0;
   letter = 'A';
   count_block = ft_count_block(str);
   if (!(stock = (t_block *)malloc(sizeof(t_block))))
   return (NULL);
   tmp = stock;
   while (count_block > 0)
   {
   tmp->c = letter;
   ft_set_block(&tmp, ft_strsub(str, 0 + i, 20));
   if (!(tmp->next = (t_block *)malloc(sizeof(t_block))))
   return (NULL);
   tmp= tmp->next;
   count_block--;
   letter++;
   i += 21;
   }
   tmp->next = NULL;
   return (stock);
   }

   char *ft_red(char *str)
   {
   int i;
   int fd;
   char buf;
   char *ret;

   i = 0;
   fd = open(str, O_RDONLY);
   while (read(fd, &buf, 1))
   i++;
   if (i > 546 || i < 20)
   {
   ft_putendl("error");
   exit (0);
   }
   ret = ft_strnew(i);
   i = 0;
   close(fd);
   fd = open(str, O_RDONLY);
   while (read(fd, &buf, 1))
   ret[i++] = buf;
close(fd);
return (ret);
}
*/
