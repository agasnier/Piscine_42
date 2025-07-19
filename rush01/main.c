/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:09:03 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/19 16:50:43 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void	ft_putgrid(char **tab, int len)
{
	int i;
	int j = 0;
	while (j < len)
	{
	i = 0;
		while (i < len)
		{
			if (!(tab[j][i]))
			write(1, " ", 1);	
			write(1, &tab[j][i], 1);
			write(1, " ", 1);
			i++;
		}
	write(1, "\n", 1);
	j++;
	}
}


int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	/*"col1top col2top col3top col4top col1bottom col2bottom col3bottom 
	 * col4bottom row1left row2left row3left row4left row1right row2right row3right row4right"*/

	int taille = 4;
	int param = taille + 2;

	char	**tab = (char **)malloc(sizeof(char *)*param);
	int	t = 0;
	while (t < param)
	{
		tab[t] = (char *)malloc(sizeof(char)*param);
		t++;
	}




	int	i = 1;
	int 	j = 0;
	
while (j < (taille * 2) * 4)
{	
	if (j < taille * 2)
		tab[0][i] = argv[1][j];

        if (j >= taille * 2 && j < (taille * 2) * 2)
		tab[param - 1][i - taille] = argv[1][j];

	if (j >= (taille * 2) * 2 && j < (taille * 2) * 3)
		tab[i - taille * 2][0] = argv[1][j];

	if (j >= (taille * 2) * 3 && j < (taille * 2) * 4)
		tab[i - taille * 3][param - 1] = argv[1][j];
i++;
j += 2;
}
	printf("%s", "\n\n\n");
        ft_putgrid(tab, param);
        printf("%s", "\n\n\n");

	return (0);
}
