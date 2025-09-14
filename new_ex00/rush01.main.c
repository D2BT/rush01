/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindebrabant <quentindebrabant@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:20:06 by qdebraba          #+#    #+#             */
/*   Updated: 2025/09/14 15:42:09 by quentindebr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		**ft_malloc_tab(int n);
int		**ft_malloc_tab_clues(int n);
void	fill_tab(int **a, int n);
void	fill_tab_clues(int **a, int n);
void	free_all(int **a, int **b, int n);
void	ft_read(char **argv, int **clues, int n);
int		cond(char **clues, int n);
int		resolve_tab(int **tab, int **clues, int l, int c);
void	ft_puttab(int **tab);

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	get_tab_size(char **av)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (av[1][i])
	{
		if (ft_isdigit(av[1][i]) == 1)
			res++;
		i++;
	}
	if (res % 4 == 0)
		return (res / 4);
	return (-1);
}

int	fill_and_resolve(int **a, int **b, char **av, int n)
{
	fill_tab_clues(a, n);
	fill_tab(b, n);
	ft_read(av, a, n);
	if (cond(av, n) == 1)
	{
		if (resolve_tab(b, a, 0, 0) == 0)
		{
			write(2, "Error\n", 6);
			free_all(a, b, n);
			return (1);
		}
		ft_puttab(b);
	}
	else
		write(2, "Error condition\n", 16);
	return (free_all(a, b, n), 0);
}

int	main(int ac, char **av)
{
	int	n;
	int	**a;
	int	**b;

	if (ac != 2)
		return (write(2, "Error number of args\n", 21), 1);
	n = get_tab_size(av);
	if (n < 0)
		return (write(2, "You need to put a square number of int\n", 39), 1);
	if (n > 9)
		return (write(2, "We do not handle more than 9\n", 29), 1);
	a = ft_malloc_tab_clues(n);
	if (!a)
		return (write(2, "Error with malloc\n", 18), 1);
	b = ft_malloc_tab(n);
	if (!b)
		return (write(2, "Error with malloc\n", 18), 1);
	fill_and_resolve(a, b, av, n);
	return (0);
}
