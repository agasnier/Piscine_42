/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 09:13:13 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/27 12:57:19 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rush02.h"

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

int	ft_puttab_number(struct s_dict **paires, char *str)
{
	int	i;
	int	index;
	int	j;

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

int	ft_puttab_carac(struct s_dict **paires, char *str)
{
	int	i;
	int	index;
	int	j;

	i = 0;
	index = 0;
	while (str[i])
	{
		while (str[i] && str[i - 1] != ':')
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

struct	s_dict	**ft_struct(char *str)
{
	int				count;
	int				i;
	struct s_dict	**paires;

	count = 0;
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
	if (ft_puttab_number(paires, str) == 1 || ft_puttab_carac(paires, str) == 1)
		return (NULL);
	return (paires);
}

void	ft_putchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
