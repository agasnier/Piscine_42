/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:27:09 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/29 15:21:18 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"




/////////////////gerer les erreurs malloc///////////////
// si malloc se fait mal ca renvoit NULL, a gerer dans le main

t_heatmap **ft_struct(int line, int col)
{
	t_heatmap	**structs;
	int			i;

	structs = malloc(sizeof(t_heatmap *) * (line + 1));
	if (structs == NULL)
		return (NULL);

	i = 0;
	while (i < line)
	{
		structs[i] = malloc(sizeof(t_heatmap) * (col + 1));
		if (structs[i] == NULL)
			return (NULL);
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
	while(structs[i] != NULL)
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











