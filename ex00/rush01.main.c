/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdebraba <qdebraba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:50:52 by qdebraba          #+#    #+#             */
/*   Updated: 2025/09/13 14:56:24 by qdebraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		cond(char **clues);

void	ft_puttab(int tab[4][4]);

int		verif(int a[4][4], int b[4][4], int r, int c);

void	remplir(int tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	is_valide(int tab[4][4], int l, int c, int num)
{
	int	i;

	i = 0;
	while (i != 4)
	{
		if (tab[i][c] == num)
			return (0);
		i++;
	}
	i = 0;
	while (i != 4)
	{
		if (tab[l][i] == num)
			return (0);
		i++;
	}
	return (1);
}

int	resolve_tab(int tab[4][4], int clues[4][4], int l, int c)
{
	int	i;

	i = 1;
	if (l == 4)
		return (1);
	if (c == 4)
		return (resolve_tab(tab, clues, l + 1, 0));
	while (i < 5)
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

//cette fonction met les arguments de argv dans un tableau de 4*4
void	ft_read(char **argv, int clues[4][4])
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
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

int	main(int argc, char **argv)
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
}
