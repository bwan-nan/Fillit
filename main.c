/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:11:32 by cnotin            #+#    #+#             */
/*   Updated: 2018/12/10 14:11:45 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	t_piece	*stock;
	t_piece *current_piece;

	stock = NULL;
	fd = open(argv[argc - 1], O_RDONLY);
	if (checklines(&stock, fd) == -1)
		ft_putendl("nopino");
	current_piece = stock;
	while (stock)
	{
		while (stock->piece)
		{
			printf(" x = %d\n", (stock)->piece->x);
			printf(" y = %d\n", (stock)->piece->y);
			printf(" piece_nb = %d\n", (stock->piece_nb));
			stock->piece = stock->piece->next;
		}
		stock = stock->next;
	}
	return (0);
}
