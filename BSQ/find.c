/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:26:54 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/29 16:40:58 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"




int	ft_min(int left, int up, int cross)
{
	int	nbr;

	if (left < up)
		nbr = left;
	else
		nbr = up;
	if (cross < up)
		nbr = cross;
	return (nbr);
}

void	ft_put_cross(t_heatmap **structs, int *max)
{
	int	i;
	int	j;

	i = max[1];
	while (i >= 0)
	{
		j = max[2];
		while (j >= 0)
		{
			structs[i][j].map = 'X';
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




void	ft_first_set(t_heatmap **structs)
{	
	int	i;
	int	j;

	i = 0;
	while (structs[i] != NULL)
	{
		j = 0;
		while (structs[i][j].map != '\0')
		{
			if (structs[i][j].map != '.')
				structs[i][j].heat = 0;
			else if (i == 0 || j == 0)
				structs[i][j].heat = 1;
			else
				structs[i][j].heat = 1 + ft_min(structs[i][j - 1].heat, structs[i - 1][j].heat, structs[i - 1][j - 1].heat);
			j++;
		}
		i++;
	}
}
