/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindebrabant <quentindebrabant@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:50:52 by qdebraba          #+#    #+#             */
/*   Updated: 2025/09/14 15:48:25 by quentindebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		cond(char **clues);
void	ft_puttab(int **tab, int n);
int		verif(int **a, int **b, int r, int c);
int		count_lines(int **a);

int	is_valide(int **tab, int r, int c, int num)
{
	int	i;
	int	n;

	i = 0;
	n = count_lines(tab);
	while (i != n)
	{
		if (tab[i][c] == num)
			return (0);
		i++;
	}
	i = 0;
	while (i != n)
	{
		if (tab[r][i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	resolve_tab(int **tab, int **clues, int r, int c)
{
	int	i;
	int	n;

	i = 1;
	n = count_lines(tab);
	if (r == n)
		return (1);
	if (c == n)
		return (resolve_tab(tab, clues, r + 1, 0));
	while (i <= n)
	{
		if (is_valide(tab, r, c, i))
		{
			tab[r][c] = i;
			if (verif(clues, tab, r, c) == 1)
			{
				if (resolve_tab(tab, clues, r, c + 1) == 1)
					return (1);
			}
			tab[r][c] = 0;
		}
		i++;
	}
	return (0);
}

void	ft_read(char **argv, int **clues, int n)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (i < 4)
	{
		j = 0;
		while (j < n)
		{
			if (argv[1][c] != ' ')
			{
				clues[i][j] = argv[1][c] - 48;
				j++;
			}
			c++;
		}
		i++;
	}
}

int	catch_square(int number)
{
	int i;
	
	i = 0;
	while (i * i <= number)
	{
		if (i * i == number)
			return (i);
		i++;
	}
	return (-1);
}
