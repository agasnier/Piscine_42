/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:27:09 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/30 17:31:15 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_free_all(t_heatmap **structs)
{
	int	i;

	i = 0;
	while (structs[i] != NULL && structs)
	{
		free(structs[i]);
		i++;
	}
	free(structs);
}

t_heatmap	**ft_struct(int line, int col)
{
	t_heatmap	**structs;
	int			i;

	structs = malloc(sizeof(t_heatmap *) * (line + 1));
	if (structs == NULL)
	{
		ft_free_all(structs);
		return (NULL);
	}
	i = 0;
	while (i < line)
	{
		structs[i] = malloc(sizeof(t_heatmap) * (col + 1));
		if (structs[i] == NULL)
		{
			ft_free_all(structs);
			return (NULL);
		}
		i++;
	}
	structs[i] = NULL;
	return (structs);
}

void	put_in(char *str, t_heatmap **structs)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[k] != '\n')
		k++;
	k++;
	while (structs[i] != NULL)
	{
		j = 0;
		while (str[k] != '\n' && str[k] != '\0')
		{
			structs[i][j].map = str[k];
			j++;
			k++;
		}
		structs[i][j].map = '\0';
		k++;
		i++;
	}
}
