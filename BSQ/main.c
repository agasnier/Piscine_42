/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:21:58 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/29 15:31:35 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(void)
{
	char test[] = "..o.....\n........\n.....o..\n........\n...oo...\n........\n...o....\n........\n";
	int	line;
	int	col;
	

	//print du tableau de base
	printf("Tableau entree:\n%s\n\n", test);

	//fonction dans le utils.c	
	col = size_hor(test);
	line = size_vert(test);
	
///////////////////gestion erreur////////////////////
	//declaration prototype de la structure
	t_heatmap **structs;

	//creation de la structure
	structs = ft_struct(line, col);
	
	//remplissage de la structure par le schema de base
	put_in(test, structs);

	//remplissage de la structure tout court
	ft_first_set(structs);
	
	//trouver le nombre le plus grand
	int	max[3];
	ft_find_it(structs, max);
	
	//mettre les croix
	ft_put_cross(structs, max);
	
	
	

	
/////////////////////test de la fonction////////////////////////////////////	
	int	i;
	int	j;
	
	
	j = 0;	
	i = 0;
	while (structs[i] != NULL)
	{
		j = 0;
		while (structs[i][j].map != '\0')
		{
			printf("%c", structs[i][j].map);
			j++;
		}
		printf("%s", "\n");
		i++;
	}
///////////////////////////////////////////////////////////////////////////////		
	
	
	
	
/////////////////////test de la fonction////////////////////////////////////
	printf("%s", "\n\n");

	j = 0;
	i = 0;
	while (structs[i] != NULL)
	{
		j = 0;
		while (structs[i][j].map != '\0')
		{
			printf("%c ", structs[i][j].heat + '0');
			j++;
		}
		printf("%s", "\n\n");
		i++;
	}
	
///////////////////////////////////////////////////////////////////////////////

	return (0);
}
