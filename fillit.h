/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:51:25 by cnotin            #+#    #+#             */
/*   Updated: 2018/12/10 15:25:59 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef	struct			s_point
{
	int					x;
	int					y;
	struct s_point		*next;
}						t_point;

typedef struct			s_piece
{
	int					piece_nb;
	t_point				*piece;
	struct s_piece		*next;
}						t_piece;

int				get_next_line(const int fd, char **line);
int				checklines(t_piece **stock, const int fd);
int				get_index(t_piece **current_piece, int line_nb, int i);
t_piece			*new_add_piece(t_piece **stock, int piece_nb);
int				tetricheck(char *str);
int				put_tab(int x, t_piece *stock);

#endif
