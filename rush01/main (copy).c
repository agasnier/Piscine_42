/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:09:03 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/19 16:00:31 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void	ft_putgrid(char **a)
{
        int i = 0;
	while (a[0][i])
	{
		write(1, &a[0][i], 1);
		i++;
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
	while (j < taille * 2)
	{
		tab[0][i] = argv[1][j];
		i++;
		j += 2;
	}
        i = 1;
        while (j < (taille * 2) * 2)
        {
                tab[param - 1][i] = argv[1][j];
                i++;
                j += 2;
        }
	i = 1;
	while (j < (taille * 2) * 3)
        {
                tab[i][0] = argv[1][j];
                i++;
                j += 2;
        }
	i = 1;
	while (j < (taille * 2) * 4)
        {
                tab[i][param - 1] = argv[1][j];
                i++;
                j += 2;
        }


	printf("%s", "Ligne du haut\n");
	printf("%c\n", tab[0][1]);
	printf("%c\n", tab[0][2]);
	printf("%c\n", tab[0][3]);
        printf("%c\n", tab[0][4]);

	printf("%s", "Ligne du bas\n");
        printf("%c\n", tab[5][1]);
        printf("%c\n", tab[5][2]);
        printf("%c\n", tab[5][3]);
        printf("%c\n", tab[5][4]);

	printf("%s", "Ligne de gauche\n");
        printf("%c\n", tab[1][0]);
        printf("%c\n", tab[2][0]);
        printf("%c\n", tab[3][0]);
        printf("%c\n", tab[4][0]);

	printf("%s", "Ligne du bas\n");
        printf("%c\n", tab[1][5]);
        printf("%c\n", tab[2][5]);
        printf("%c\n", tab[3][5]);
        printf("%c\n", tab[4][5]);

	printf("%s", "\n\n\n");
        ft_putgrid(tab);
        printf("%s", "\n\n\n");

	return (0);
}
