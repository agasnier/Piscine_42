/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 09:13:13 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/26 11:17:33 by elibouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

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
	
	tmp[t_read + 1] = '\0';


//creer un tableau avec malloc de la taille totale du document
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

int	ft_pars(char *str)
{
	int		i;
	struct	paire
	{
		char	*number;
		char	*carac;

	};

	struct paire	*dict;
	
	i = 0;
	while (str[i] != '\n')
	{
		printf("%c", str[i]);
		i++;
	}
	
	dict = (struct paire *)malloc(sizeof(struct paire));
	if (dict == NULL)
		return(1);

	dict[0].number = "1";
	dict[0].carac = "Alex";

	printf("%s\n", dict[0].number);
	printf("%s\n", dict[0].carac);



	return (0);
}

int	main(void)
{
	char *str;

	str = ft_stock();
	//printf("%s", str);
	ft_pars(str);



	return (0);
}
