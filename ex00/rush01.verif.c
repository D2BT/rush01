/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.verif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejonsery <ejonsery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:38:27 by qdebraba          #+#    #+#             */
/*   Updated: 2024/09/15 19:29:40 by qdebraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	r_g(int a[4][4], int b[4][4], int r)
{
	int	count;
	int	max;
	int	j;

	j = 0;
	max = 0;
	count = 0;
	while (j < 4)
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

int	r_d(int a[4][4], int b[4][4], int r)
{
	int	count;
	int	j;
	int	max;

	j = 3;
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

int	c_h(int a[4][4], int b[4][4], int c)
{
	int	count;
	int	j;
	int	max;

	j = 0;
	max = 0;
	count = 0;
	while (j < 4)
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

int	c_b(int a[4][4], int b[4][4], int c)
{
	int	count;
	int	j;
	int	max;

	j = 3;
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

int	verif(int tab[4][4], int clues[4][4], int r, int c)
{
	int	result;

	if (c == 3)
	{
		result = r_g(tab, clues, r);
		if (result == 0)
			return (0);
		result = r_d(tab, clues, r);
		if (result == 0)
			return (0);
	}
	if (r == 3)
	{
		result = c_h(tab, clues, c);
		if (result == 0)
			return (0);
		result = c_b(tab, clues, c);
		if (result == 0)
			return (0);
	}
	return (1);
}
