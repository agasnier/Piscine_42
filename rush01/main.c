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

//verificiation de l'entrée
int	ft_entry(char *argv[])
{
	int i;

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

//creation du tableau + remplissage de zero
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
		
//pas obligatoire ............
		j = 0;
		while(j < len)
		{
			tab[i][j] = ' ';
			j++;
		}
		i++;
	}
	return (tab);
}

//ajout des parametres dans le tableau
void	ft_param(char **tab, char **argv, int len)
{
	int i;
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


//affichage du tableau
void	ft_putgrid(char **tab, int len)
{
	int i;
	int j;

	j = 0;
	while (j < len)
	{
	i = 0;
		while (i < len)
		{
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
	//parsing de argv pour empecher les erreurs
	if (argc != 2)
		return (1);
	if (ft_entry(argv) == 1)
		return (1);


	//dimension du tableau + creation de celui-ci
	int len = 4;
	len += 2;
	char **tab = ft_init(len);
	ft_param(tab, argv, len);



	//remplissage des solutions
	char	sol[] = "1234";

	int h = 0;
	while (sol[h] != '\0')
	{
		tab[1][h + 1] = sol[h];
		h++;
	}

	//comptage des solutions pour verification
	int f = 0;
	int ctr = 0;
	char max = '0';

	while (sol[f] != '\0')
	{
		if (sol[f] > max)
		{
			max = sol[f];
			ctr++;
		}
		f++;
	}


	printf("\n\n%d\n\n", ctr);


	//affichage du tableau
    ft_putgrid(tab, len);

	printf("%s", "\n\n");



	return (0);
}