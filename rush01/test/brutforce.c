/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brutforce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:21:22 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/20 15:48:58 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_swap(char *a, char *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

char	**tab_sol()
{
	int i;
	int j;
	int len;

	len = 4;

	char **sol;
	
	sol = (char **)malloc(sizeof(char *) * 24);
	i = 0;
	while (i < 24)
	{
		sol[i] = (char *)malloc(sizeof(char) * len);
		j = 0;
		while(j < len)
		{
			sol[i][j] = '0';
			j++;
		}
		i++;
	}
	return (sol);
}

void	ft_brutforce(char **sol, char *pattern, int d, int *ptr)
{
	int i;
	int j;
	i = 0;
	if (d == 4 - 1)
	{
		j = 0;
		while (j < 4)
		{
			sol[*ptr][j] = pattern[j];
			j++;
		}
		*ptr += 1;
	}


	else
	{
		i = d;
		while (i <= 4 - 1)
		{
			ft_swap(&pattern[d], &pattern[i]);
			ft_brutforce(sol, pattern, d + 1, ptr);
			ft_swap(&pattern[d], &pattern[i]);
			i++;
		}
	}
}
