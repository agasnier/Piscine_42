/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:59:29 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/28 16:25:19 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>


int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}


char	*ft_cpy(char *str)
{
	int	i;
	char *cpy;

	
	cpy = malloc(sizeof(char) * (ft_str_len(str) + 1));
	i = 0;
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';

	return (cpy);


}



struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str *structs;
	//struct s_stock_str	*t_stock_str;

	structs = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (structs == NULL)
		return (NULL);
	structs[ac].str = 0;
	

	i = 0;
	while (i < ac)
	{
		structs[i].size = ft_str_len(av[i]);
		structs[i].str = av[i];
		structs[i].copy = ft_cpy(av[i]);
		i++;
	}

	return (structs);
}


