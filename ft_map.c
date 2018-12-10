/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:46:14 by cnotin            #+#    #+#             */
/*   Updated: 2018/12/10 14:14:12 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*new_add_piece(t_piece **stock, int piece_nb)
{
	t_piece		*current_piece;
	t_piece		*new_piece;

	current_piece = (*stock);
	if ((*stock) != NULL)
	{
		while (current_piece->next)
			current_piece = current_piece->next;
	}
	if (!(new_piece = (t_piece*)ft_memalloc(sizeof(t_piece))))
		return (NULL);
	new_piece->piece_nb = piece_nb;
	new_piece->next = NULL;
	if ((*stock) == NULL)
		(*stock) = new_piece;
	else
		current_piece->next = new_piece;
	return (new_piece);
}

void		set_index(t_piece **current_piece, t_point **buf_point,
			int line_nb, int i)
{
	(*buf_point)->x = i - (*current_piece)->piece->x;
	(*buf_point)->y = line_nb - (*current_piece)->piece->y - 1;
}

int			get_index(t_piece **current_piece, int line_nb, int i)
{
	t_point		*buf_piece;
	t_point		*buf_point;

	buf_piece = (*current_piece)->piece;
	if ((*current_piece)->piece != NULL)
	{
		while (buf_piece->next)
			buf_piece = buf_piece->next;
	}
	if (!(buf_point = (t_point*)malloc(sizeof(t_point))))
		return (-1);
	if ((*current_piece)->piece == NULL)
	{
		buf_point->x = i;
		buf_point->y = line_nb - 1;
	}
	else
		set_index(current_piece, &buf_point, line_nb, i);
	buf_point->next = NULL;
	if ((*current_piece)->piece == NULL)
		(*current_piece)->piece = buf_point;
	else
		buf_piece->next = buf_point;
	return (0);
}
