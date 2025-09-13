/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdebraba <qdebraba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:14:57 by zbechtle          #+#    #+#             */
/*   Updated: 2025/09/13 14:48:27 by qdebraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	cond(char **clues)
{
	int	i;
	int	count_1;
	int	count_int;

	i = 0;
	count_1 = 0;
	count_int = 0;
	while (clues[1][i] != '\0')
	{
		if (clues[1][i] == '1')
			count_1++;
		if (clues[1][i] >= '1' && clues[1][i] <= '4')
			count_int++;
		if (!((clues[1][i] >= '1' && clues[1][i] <= '4')
			|| (clues[1][i] == ' ')))
			return (0);
		i++;
	}
	if ((count_int == 16) && (count_1 == 4))
		return (1);
	return (0);
}

void	ft_puttab(int tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i != 4)
	{
		j = 0;
		while (j != 4)
		{
			ft_putchar(tab[i][j] + 48);
			if (j != 3)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			j++;
		}
		i++;
	}
}
