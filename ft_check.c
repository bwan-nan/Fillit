/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:57:06 by cnotin            #+#    #+#             */
/*   Updated: 2018/12/10 15:26:52 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		countdiez(char *str)
{
	static int	i;
	int			diez_nb;

	diez_nb = 0;
	if (ft_strlen(str) == 16)
		i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			diez_nb++;
		i++;
	}
	return (diez_nb == 4 ? 0 : -1);
}

int		validtetri(char *line, t_piece **current_piece, int line_nb)
{
	int i;

	i = 0;
	if (ft_strlen(line) != 4 && line[4] != '\0')
		return (-1);
	i = 0;
	while (i < 4)
	{
		if (line[i] != '#' && line[i] != '.')
			return (-1);
		if (line[i] == '#')
		{
			if (get_index(current_piece, line_nb, i) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

int		delall(t_piece **stock, char **str)
{
	t_point *tmp_point;
	t_piece *tmp_piece;

	ft_strdel(str);
	while ((*stock))
	{
		tmp_piece = (*stock);
		while ((*stock)->piece)
		{
			tmp_point = (*stock)->piece;
			tmp_point->x = 0;
			tmp_point->y = 0;
			free(tmp_point);
			(*stock)->piece = (*stock)->piece->next;
		}
		tmp_piece->piece_nb = 0;
		(*stock) = (*stock)->next;
		free(tmp_piece);
	}
	return (-1);
}

int		tetrimino(char *line, char *str, t_piece **stock,
		t_piece **current_piece)
{
	static int piece_nb;

	if (ft_strlen(str) == 16)
		piece_nb = 1;
	if (line[0] != '\0' || countdiez(str) == -1)
		return (delall(stock, &str));
	piece_nb++;
	if (!(*current_piece = new_add_piece(stock, piece_nb)))
		return (-1);
	return (0);
}

int		checklines(t_piece **stock, const int fd)
{
	int				line_nb;
	char			*line;
	char			*str;
	t_piece			*current_piece;

	line_nb = 0;
	if (!(current_piece = new_add_piece(stock, 1)))
		return (-1);
	str = ft_strnew(0);
	while (get_next_line(fd, &line))
	{
		str = ft_strjoinf(str, line);
		if (++line_nb % 5 == 0)
		{
			if (tetrimino(line, str, stock, &current_piece) == -1)
				return (-1);
			line_nb = 0;
		}
		else if (validtetri(line, &current_piece, line_nb) == -1)
			return (delall(stock, &str));
		ft_strdel(&line);
	}
	if (tetricheck(str) == -1)
		return (delall(stock, &str));
	return (0);
}
