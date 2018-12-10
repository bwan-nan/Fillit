/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnotin <cnotin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:46:54 by cnotin            #+#    #+#             */
/*   Updated: 2018/12/10 12:46:57 by cnotin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_contact(char *str, int check, int i, int j)
{
	if (str[i + 1] == '#' && j < 15)
		check++;
	if (str[i + 4] == '#' && j < 12)
		check++;
	if (str[i - 1] == '#' && j > 0)
		check++;
	if (str[i - 4] == '#' && j > 3)
		check++;
	return (check);
}

int		tetricheck(char *str)
{
	int i;
	int j;
	int check;

	i = 0;
	while (str[i])
	{
		check = 0;
		j = 0;
		while (j < 16)
		{
			if (str[i] == '#')
				check = check_contact(str, check, i, j);
			j++;
			i++;
		}
		if (check != 6 && check != 8)
			return (-1);
	}
	return (0);
}
