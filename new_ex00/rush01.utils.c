/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdebraba <qdebraba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:41:15 by qdebraba          #+#    #+#             */
/*   Updated: 2025/09/15 13:45:29 by qdebraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_isdigit(int c);
int		catch_square(int number);
void	free_tab_clues(int **a);

int	**ft_malloc_tab(int n)
{
	int	i;
	int	**a;

	i = 0;
	a = malloc(sizeof(int *) * (n + 1));
	if (!a)
		return (NULL);
	while (i < n)
	{
		a[i] = malloc(sizeof(int) * (n + 1));
		if (!a[i])
		{
			while (i != 0)
				free(a[--i]);
			free(a);
			return (NULL);
		}
		a[i][n] = -1;
		i++;
	}
	a[n] = NULL;
	return (a);
}

void	fill_tab(int **a, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			a[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	count_lines(int **a)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (a[i] != NULL)
	{
		j = 0;
		while (a[i][j] != -1)
		{
			j++;
			count++;
		}
		i++;
	}
	return (catch_square(count));
}

void	free_tab(int **a, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		free(a[i]);
		i++;
	}
	free(a);
}

void	free_all(int **a, int **b, int n)
{
	free_tab_clues(a);
	free_tab(b, n);
}
