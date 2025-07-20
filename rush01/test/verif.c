/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 202/07/20 12:32:38 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/20 16:47:44 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_verif_left(char **tab, int line)
{
	int i = 1;
	int comp = 0;
	char max = '0';

	while (i <= 4)
	{
		if (tab[line + 1][i] > max)
		{
			max = tab[line + 1][i];
			comp++;
		}
		i++;
	}
	if (comp + '0' != tab[line + 1][0])
		return (1);
	return (0);
}

int ft_verif_right(char **tab, int line)
{
	int i = 4;
	int comp = 0;
	char max = '0';

	while (i >= 1)
	{
		if (tab[line + 1][i] > max)
		{
			max = tab[line + 1][i];
			comp++;
		}
		i--;
	}
	if (comp + '0' != tab[line + 1][5])
		return (1);
	return (0);
}

int ft_verif_up(char **tab, int col)
{
	int i = 1;
	int comp = 0;
	char max = '0';

	while (i <= 4)
	{
		if (tab[i][col + 1] > max)
		{
			max = tab[i][col + 1];
			comp++;
		}
		i++;
	}
	if (comp + '0' != tab[0][col + 1])
		return (1);
	return (0);
}

int ft_verif_down(char **tab, int col)
{
	int i = 4;
	int comp = 0;
	char max = '0';

	while (i >= 1)
	{
		if (tab[i][col + 1] > max)
		{
			max = tab[i][col + 1];
			comp++;
		}
		i--;
	}
	if (comp + '0' != tab[5][col + 1])
		return (1);
	return (0);
}

int ft_col(char **tab, int line)
{
	int col;
        int i;
        int j;

        col = 1;
	while (col <= 4)
	{       
                i = 1;
		while (i <= line + 1)
		{
                        j = i + 1;
			while (j <= line + 1)
			{
				if (tab[i][col] == tab[j][col])
					return (0);
                                j++;
			}
                        i++;
		}
                col++;
	}
	return (1);
}

int ft_verif(char **tab, int line)
{
	int i = 0;

	if (ft_verif_left(tab, line) == 1 || ft_verif_right( tab, line) == 1)
		return (1);

	if (!ft_col(tab, line))
		return (1);

	if (line == 3)
	{
		while (i < 4)
		{
			if (ft_verif_up(tab, i) == 1 || ft_verif_down(tab, i) == 1)
				return (1);
			i++;
		}
	}
	return (0);
}