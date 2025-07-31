/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:51:22 by cboucher          #+#    #+#             */
/*   Updated: 2025/07/30 15:34:49 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_dup(char *charset)
{
	int	i;
	int	j;

	i = 0;
	while (charset[i])
	{
		j = 0;
		while (charset[j])
		{
			if (charset[i] == charset[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_charset(char *map, int *i)
{
	int	j;

	j = 0;
	if (map[*i + 3] != '\n')
		return (0);
	while (j < 3)
	{
		if (is_printable(map[*i + j]))
			j++;
		else
			return (0);
	}
	return (1);
}

int	check_line(char *map, int *i, int *nb_cols, char *charset)
{
	int	j;
	int	cmp_cols;

	cmp_cols = 0;
	while (map[*i] != '\n' && map[*i] != '\0')
	{
		j = 0;
		while (map[*i] != charset[j])
		{
			if (!charset[++j])
				return (0);
		}
		(*i)++;
		cmp_cols++;
	}
	if (*nb_cols == 0)
		*nb_cols = cmp_cols;
	if (*nb_cols != cmp_cols || cmp_cols < 1)
		return (0);
	if (map[*i] == '\n')
		(*i)++;
	else
		return (0);
	return (1);
}

int	check_first_line(char *charset, char *map, int *i, int *nb_lines)
{
	if (!extract_nb(nb_lines, check_number_of_lines(map, i), map))
		return (0);
	if (!check_charset(map, i))
		return (0);
	charset[0] = map[(*i)++];
	charset[1] = map[(*i)++];
	charset[2] = map[(*i)++];
	if (is_dup(charset))
		return (0);
	(*i)++;
	return (1);
}

int	parsing(char *map, char *charset, int *nb_lines, int *nb_cols)
{
	int		i;
	int		j;

	i = 0;
	if (!check_first_line(charset, map, &i, nb_lines))
		return (0);
	*nb_cols = 0;
	j = 1;
	while (map[i])
	{
		if (!check_line(map, &i, nb_cols, charset))
			return (0);
		if (j++ > *nb_lines)
			return (0);
	}
	if (j <= *nb_lines)
		return (0);
	return (1);
}
