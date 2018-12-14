/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:42:19 by cnotin            #+#    #+#             */
/*   Updated: 2018/12/14 16:11:40 by bwan-nan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "fillit.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct			s_block
{
	char				c;
	int					x[4];
	int					y[4];
	struct s_block		*next;
}						t_block;

int						ft_check_file(char *str);
t_block					*launcher(t_block **blocks_list, char *str);
t_block					*ft_stock_block(char *str);
char					**ft_block_map(int size);
void					ft_display_map(char **map);
void					ft_delmap(char **map);
int						backtracking(char **map, t_block *block,
						int position, int size);
void					ft_put_block(char **map, t_block *block,
						int x_vector, int y_vector);
void					ft_del_block(char **map, t_block **block,
						int size);
void					del_lst(t_block *lst);
int						ft_count_block(char *file_name);
char					*ft_read(int *fd);
int						get_y_vector(t_block *block, int to_y);
int						get_x_vector(t_block *block, int to_x);
#endif
