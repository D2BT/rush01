/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdebraba <qdebraba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:50:52 by qdebraba          #+#    #+#             */
/*   Updated: 2025/09/13 17:55:35 by qdebraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		cond(char **clues);
void	ft_puttab(int **tab, int n);
int		verif(int **a, int **b, int r, int c);
int		count_lines(int **a);

int	is_valide(int **tab, int l, int c, int num)
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
		if (tab[l][i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	resolve_tab(int **tab, int **clues, int l, int c)
{
	int	i;
	int	n;

	i = 1;
	n = count_lines(tab);
	if (l == n)
		return (1);
	if (c == n)
		return (resolve_tab(tab, clues, l + 1, 0));
	while (i < n)
	{
		if (is_valide(tab, l, c, i))
		{
			tab[l][c] = i;
			if (verif(clues, tab, l, c) == 1)
			{
				if (resolve_tab(tab, clues, l, c + 1) == 1)
					return (1);
			}
			tab[l][c] = 0;
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
	while (i < n)
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

/* int	main(int argc, char **argv)
{
	int	a[4][4];
	int	b[4][4];

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	remplir(a);
	remplir(b);
	ft_read(argv, a);
	if (cond(argv) == 1)
	{
		if (resolve_tab(b, a, 0, 0) == 0)
		{
			write(2, "Error\n", 6);
			return (1);
		}
	}
	ft_puttab(b);
	return (0);
} */
