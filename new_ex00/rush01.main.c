/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdebraba <qdebraba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:20:06 by qdebraba          #+#    #+#             */
/*   Updated: 2025/09/13 17:58:16 by qdebraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		**ft_malloc_tab(int n);
void	fill_tab(int **a, int n);
void	free_all(int **a, int **b, int n);
void	ft_read(char **argv, int **clues, int n);
int		cond(char **clues, int n);
int		resolve_tab(int **tab, int **clues, int l, int c);
void	ft_puttab(int **tab, int n);

int	ft_isdigit(char c)
{
	if (c >= '1' && c <= '9')
		return (1);
	else
		return (0);
}

int	catch_square(int number)
{
	int	i;

	i = 0;
	while ((i * i) <= number)
	{
		if (i * i == number)
			return (i);
		i++;
	}
	return (-1);
}

int	get_square(char **av)
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
	res = catch_square(res);
	return (res);
}

int	fill_and_resolve(int **a, int **b, char **av, int n)
{
	fill_tab(a, n);
	fill_tab(b, n);
	ft_read(av, a, n);
	ft_puttab(a, n);
	if (cond(av, n) == 1)
	{
		if (resolve_tab(b, a, 0, 0) == 0)
		{
			write(2, "Error\n", 6);
			free_all(a, b, n);
			return (1);
		}
	}
	ft_puttab(b, n);
	return (free_all(a, b, n), 0);
}

int	main(int ac, char **av)
{
	int	n;
	int	**a;
	int	**b;

	if (ac != 2)
		return (write(2, "Error\n", 6), 1);
	n = get_square(av);
	if (n < 0)
		return (write(2, "Error\n", 6), 1);
	if (n > 9)
		return (write(2, "We do not handle more than 9\n", 29), 1);
	a = ft_malloc_tab(n);
	if (!a)
		return (write(2, "Error with malloc\n", 18), 1);
	b = ft_malloc_tab(n);
	if (!b)
		return (write(2, "Error with malloc\n", 18), 1);
	fill_and_resolve(a, b, av, n);
	return (0);
}
