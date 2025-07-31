/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:00:35 by cboucher          #+#    #+#             */
/*   Updated: 2025/07/30 15:35:31 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	extract_nb(int *nb_lines, int nb_lines_size, char *map)
{
	int	i;

	i = 0;
	*nb_lines = 0;
	while (nb_lines_size)
	{
		*nb_lines *= 10;
		*nb_lines += map[i] - '0';
		i++;
		nb_lines_size--;
	}
	return (*nb_lines);
}

int	check_number_of_lines(char *map, int *i)
{
	while (is_num(map[*i]))
	{
		if (is_num(map[*i]) && !is_printable(map[*i + 1]))
			return (0);
		(*i)++;
	}
	return (*i);
}
