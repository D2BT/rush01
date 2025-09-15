/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdebraba <qdebraba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:23:32 by quentindebr       #+#    #+#             */
/*   Updated: 2025/09/15 13:45:04 by qdebraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	**ft_malloc_tab_clues(int n)
{
	int	i;
	int	**a;

	i = 0;
	a = malloc(sizeof(int *) * (5));
	if (!a)
		return (NULL);
	while (i < 4)
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
	a[4] = NULL;
	return (a);
}

void	fill_tab_clues(int **a, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
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

void	free_tab_clues(int **a)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(a[i]);
		i++;
	}
	free(a);
}