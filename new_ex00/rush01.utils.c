/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdebraba <qdebraba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:41:15 by qdebraba          #+#    #+#             */
/*   Updated: 2025/09/13 17:52:29 by qdebraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	**ft_malloc_tab(int n)
{
	int	i;
	int	**a;

	i = 0;
	a = malloc(sizeof(int *) * n);
	if (!a)
		return (NULL);
	while (i < n)
	{
		a[i] = malloc(sizeof(int) * n);
		if (!a[i])
		{
			while (i != 0)
				free(a[--i]);
			free(a);
			return (NULL);
		}
		i++;
	}
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

	i = 0;
	while (a[i])
		i++;
	return (i);
}

void	free_tab(int **a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(a[i]);
		i++;
	}
	free(a);
}

void	free_all(int **a, int **b, int n)
{
	free_tab(a, n);
	free_tab(b, n);
}
