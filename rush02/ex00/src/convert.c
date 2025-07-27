/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:13:59 by amartel           #+#    #+#             */
/*   Updated: 2025/07/27 18:51:49 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"


int	ft_strlen(char *str)
{
	if (*str == 0)
		return (0);
	return (ft_strlen(str + 1) + 1);
}


void ft_convert_int_to_char(char *str, int i, struct s_dict **dict)
{
	int	size;
	size = ft_strlen(str);
	if (size == 2 && str[0] == '1')
		return (ft_print_aplha_num(str, dict));
	if (*str == 0)
		return ;
	tmp[0] = str[(size + i% size)];
	ft_print_aplha_num(tmp, dict);
	return (ft_convert_int_to_char(str + 1, i + 1, dict));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
	{
		i++;
	}
	if (s1[i] != s2[i])
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}

void	ft_print_aplha_num(char *c, struct s_dict **dict)
{
	int i;	
	i = 0;
	while (dict[i] != NULL && i < 10)
	{
		if (ft_strcmp(dict[i]->number, c) == 0)
		{
			write(1, dict[i]->carac, ft_strlen(dict[i]->carac));
		}
		i++;
	}
}
