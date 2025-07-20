/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:59:41 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/20 14:01:50 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_entry(char *argv[])
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (i % 2 == 0)
		{
			if (argv[1][i] < '1' || argv[1][i] > '4')
				return (1);
		}
		else
		{
			if (argv[1][i] != ' ')
				return (1);
		}
		i++;
	}
	if (i != 31)
		return (1);
	return (0);
}

char	**ft_init(int len)
{
	char	**tab;
	int		i;
	int		j;

	tab = (char **)malloc(sizeof(char *) * len);
	i = 0;
	while (i < len)
	{
		tab[i] = (char *)malloc(sizeof(char) * len);
		j = 0;
		while (j < len)
		{
			tab[i][j] = ' ';
			j++;
		}
		i++;
	}
	return (tab);
}

void	ft_param(char **tab, char **argv, int len)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	len -= 2;
	while (j < (len * 2) * 4)
	{
		if (j < len * 2)
			tab[0][i] = argv[1][j];
		if (j >= len * 2 && j < (len * 2) * 2)
			tab[len + 1][i - len] = argv[1][j];
		if (j >= (len * 2) * 2 && j < (len * 2) * 3)
			tab[i - len * 2][0] = argv[1][j];
		if (j >= (len * 2) * 3 && j < (len * 2) * 4)
			tab[i - len * 3][len + 1] = argv[1][j];
		i++;
		j += 2;
	}
}
