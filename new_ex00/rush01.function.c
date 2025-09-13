/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdebraba <qdebraba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:14:57 by zbechtle          #+#    #+#             */
/*   Updated: 2025/09/13 18:09:26 by qdebraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static int	ft_isdigit_n(char c)
{
	printf("c vaut %c\n", c);
	if (c >= '1' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	cond(char **clues, int n)
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
		if (ft_isdigit_n(clues[1][i]) == 1)
			count_int++;
		if (!(ft_isdigit_n(clues[1][i]) == 1)
			|| (clues[1][i] == ' '))
			return (0);
		i++;
	}
	if ((count_int == n * n) && (count_1 == n))
		return (1);
	return (0);
}

void	ft_puttab(int **tab, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i != n)
	{
		j = 0;
		while (j != n)
		{
			ft_putchar(tab[i][j] + 48);
			if (j != n - 1)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			j++;
		}
		i++;
	}
}
