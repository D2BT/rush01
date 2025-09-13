/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.verif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdebraba <qdebraba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:38:27 by qdebraba          #+#    #+#             */
/*   Updated: 2025/09/13 16:43:42 by qdebraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	count_lines(int **a);

int	r_l(int **a, int **b, int r, int n)
{
	int	count;
	int	max;
	int	j;

	j = 0;
	max = 0;
	count = 0;
	while (j < n)
	{
		if (b[r][j] > max)
		{
			max = b[r][j];
			count++;
		}
		j++;
	}
	if (a[2][r] == count)
		return (1);
	return (0);
}

int	r_r(int **a, int **b, int r, int n)
{
	int	count;
	int	j;
	int	max;

	j = n - 1;
	max = 0;
	count = 0;
	while (j >= 0)
	{
		if (b[r][j] > max)
		{
			max = b[r][j];
			count++;
		}
		j--;
	}
	if (a[3][r] == count)
		return (1);
	return (0);
}

int	c_t(int **a, int **b, int c, int n)
{
	int	count;
	int	j;
	int	max;

	j = 0;
	max = 0;
	count = 0;
	while (j < n)
	{
		if (b[j][c] > max)
		{
			max = b[j][c];
			count++;
		}
		j++;
	}
	if (a[0][c] == count)
		return (1);
	return (0);
}

int	c_b(int **a, int **b, int c, int n)
{
	int	count;
	int	j;
	int	max;

	j = n - 1;
	max = 0;
	count = 0;
	while (j >= 0)
	{
		if (b[j][c] > max)
		{
			max = b[j][c];
			count++;
		}
		j--;
	}
	if (a[1][c] == count)
		return (1);
	return (0);
}

int	verif(int **tab, int **clues, int r, int c)
{
	int	result;
	int	n;

	n = count_lines(tab);
	if (c == 3)
	{
		result = r_l(tab, clues, r, n);
		if (result == 0)
			return (0);
		result = r_r(tab, clues, r, n);
		if (result == 0)
			return (0);
	}
	if (r == 3)
	{
		result = c_t(tab, clues, c, n);
		if (result == 0)
			return (0);
		result = c_b(tab, clues, c, n);
		if (result == 0)
			return (0);
	}
	return (1);
}
