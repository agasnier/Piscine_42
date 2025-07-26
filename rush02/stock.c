/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 09:13:13 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/26 11:56:26 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//open,read
#include <fcntl.h>

//close
#include <unistd.h>

//malloc
#include <stdlib.h>

//printf
#include <stdio.h>

char	*ft_stock(void)
{
//declaration variable
	int		fd;
	int		t_read;
	char	tmp[1024];
	char	*str;
	int		i;
	
//ouvre le document, retourne (-1) si erreur
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		return (NULL);

//read --> donne la taille lu en octet jusqu'a la limite (ici 1024 octets)
//stocke ce aui est lu dans le tmp[]

	////////////////////////////////////
//Faire une boucle au cas ou buffer trop petit avec while t_read > 0
	//////////////////////////////////
	t_read = read(fd, tmp, 1024);
	if (t_read == - 1)
		return (NULL);
	
	tmp[t_read] = '\0';


//creer un str avec malloc de la taille totale du document
	str = malloc((sizeof(char) * t_read) + 1);

//remplissage du tableau avec tmp
	i = 0;
	while (tmp[i])
	{
		str[i] = tmp[i];
		i++;
	}
	str[i] = '\0';
	
//ferme le document ouvert
	close(fd);

//retourner le tableau cree
	return (str);
}

struct dict **ft_pars(struct dict **paires, char *str)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (str[i])
	{
		while (str[i] >= '0' && str[i] <= '9')
			printf("%c\n", str[i]);
		while (str[i] >= '!' && str[i] <= '~')
			printf("%c\n", str[i]);



		i++;
	}


	return (paires);
}

struct dict	**ft_struct(char *str)
{
// count le nombre de paires
	int	count;
	int	i;

	count = 0;
	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}

	printf("Nombre de paires: %d\n\n", count);

//creer le tableau de strucs
	struct	dict
	{
		char	*number;
		char	*carac;

	};

	struct dict **paires;
	
	paires = malloc((sizeof(struct dict *) * count) + 1);
	if (paires == NULL)
		return(NULL);
	paires[count] = NULL;

	ft_pars(paires, str);

	return (paires);
}

int	main(void)
{
	char *str;

	str = ft_stock();
	printf("\nImpression du dict:\n%s\n", str);
	ft_struct(str);



	return (0);
}
