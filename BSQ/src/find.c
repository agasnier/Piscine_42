/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:26:54 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/30 20:12:32 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_display_map(t_heatmap **structs)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (structs[i] != NULL)
	{
		j = 0;
		while (structs[i][j].map != '\0')
		{
			write(1, &structs[i][j].map, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	ft_free_all(structs);
}

int	ft_min(int left, int up, int cross)
{
	int	nbr;

	if (left < up)
		nbr = left;
	else
		nbr = up;
	if (cross < up && cross < left)
		nbr = cross;
	return (nbr);
}

void	ft_put_cross(t_heatmap **structs, int *max, char *charset)
{
	int	i;
	int	j;

	i = max[1];
	while (i >= (max[1] + 1) - max[0] && i >= 0)
	{
		j = max[2];
		while (j >= (max[2] + 1) - max[0] && j >= 0)
		{
			structs[i][j].map = charset[2];
			j--;
		}
		i--;
	}
}

int	*ft_find_it(t_heatmap **structs, int *max)
{
	int	i;
	int	j;

	i = 0;
	max[0] = 0;
	while (structs[i] != NULL)
	{
		j = 0;
		while (structs[i][j].map != '\0')
		{
			if (structs[i][j].heat > max[0])
			{
				max[0] = structs[i][j].heat;
				max[1] = i;
				max[2] = j;
			}
			j++;
		}
		i++;
	}
	return (max);
}

void	ft_first_set(t_heatmap **structs, char *charset)
{
	int	i;
	int	j;

	i = 0;
	while (structs[i] != NULL)
	{
		j = 0;
		while (structs[i][j].map != '\0')
		{
			if (structs[i][j].map != charset[0])
				structs[i][j].heat = 0;
			else if (i == 0 || j == 0)
				structs[i][j].heat = 1;
			else
				structs[i][j].heat = 1 + ft_min(structs[i][j - 1].heat, \
structs[i - 1][j].heat, structs[i - 1][j - 1].heat);
			j++;
		}
		i++;
	}
}
