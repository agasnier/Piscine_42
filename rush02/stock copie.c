/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 09:13:13 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/26 16:38:51 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/include/rush02.h"
#include <stdio.h>

//lecture de l'entrée (gerer les erreurs de dict avant tout ça) et stockage dans un char *str
char	*ft_stock(void)
{
	int		fd;
	int		t_read;
	char	tmp[1024];
	char	*str;
	int		i;

	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		return (NULL);
	t_read = read(fd, tmp, 1024);
	if (t_read == -1)
		return (NULL);
	tmp[t_read] = '\0';
	str = malloc((sizeof(char) * t_read) + 1);
	i = 0;
	while (tmp[i])
	{
		str[i] = tmp[i];
		i++;
	}
	str[i] = '\0';
	close(fd);
	return (str);
}

//imprime juste un tabelau dans un tableau
void	ft_puttab(char *dst, char *src, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

// parser la phrase et mettre le nombre dans le struct associé
int	ft_puttab_number(struct s_dict **paires, char *str)
{
	int i;
	int index;
	int j;

	i = 0;
	index = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i + j] >= '0' && str[i + j] <= '9')
				j++;
			paires[index]->number = malloc(sizeof(char) * (j + 1));
			if (paires[index]->number == NULL)
				return (1);
			ft_puttab(paires[index]->number, &str[i], j);
		}
		i += j;
		if (str[i] == '\n' && str[i + 1] != '\0')
			index++;
		i++;
	}
	return (0);
}

// parser la phrase et mettre le carac dans le struct associé
int	ft_puttab_carac(struct s_dict **paires, char *str)
{
	int i;
	int index;
	int j;

	i = 0;
	index = 0;
	while (str[i])
	{
		while (str[i] && str[i] != ':')
			i++;	
		if(str[i] == ':')
				i++;
		while (str[i] == ' ')
			i++;
		j = 0;
		while (str[i + j] && str[i + j] != '\n')
			j++;
		paires[index]->carac = malloc(sizeof(char) * (j + 1));
		if (paires[index]->carac == NULL)
			return (1);
		ft_puttab(paires[index]->carac, &str[i], j);
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i])
			i++;			
		index++;
		
	}
	return (0);
}



//creation du tableau de struc + gestion des mallocs NULL
struct	s_dict	**ft_struct(char *str)
{
	int			count;
	int			i;
	struct s_dict	**paires;

	count = 1;
	i = -1;
	while (str[++i] != '\0')
		if (str[i] == '\n')
			count++;
	paires = malloc(sizeof(struct s_dict *) * (count + 1));
	if (paires == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		paires[i] = malloc(sizeof(struct s_dict));
		if (paires[i] == NULL)
			return (NULL);
		i++;
	}
	paires[i] = NULL;
	if (ft_puttab_number(paires, str) == 1|| ft_puttab_carac(paires, str) == 1)
		return (NULL);
	return (paires);
}

//main de test
int	main(void)
{
	struct s_dict	**dict;
	char		*str;

	str = ft_stock();
	dict = ft_struct(str);
	int i;
	i = 0;
	while(dict[i] != NULL)
	{
		printf("Number: %s\n", dict[i]->number);
		printf("Caractere: %s\n\n", dict[i]->carac);
		i++;
	}
	return (0);
}
