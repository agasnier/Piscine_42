/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:21:58 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/30 19:55:10 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_logic(int size_input, char *map, char *charset, int *nb_lines_cols)
{
	map[size_input] = '\0';
	if (!parsing(map, charset, &nb_lines_cols[0], &nb_lines_cols[1]))
		write(1, "map error\n", 10);
	else if (!ft_resolve(map, charset, nb_lines_cols[0], \
nb_lines_cols[1]))
		write(1, "map error\n", 10);
}

int	ft_resolve(char *map, char *charset, int nb_lines, int nb_cols)
{
	int			max[3];
	t_heatmap	**structs;

	structs = ft_struct(nb_lines, nb_cols);
	if (structs == NULL)
		return (0);
	put_in(map, structs);
	ft_first_set(structs, charset);
	ft_find_it(structs, max);
	ft_put_cross(structs, max, charset);
	ft_display_map(structs);
	return (1);
}

void	ft_clean(char *map)
{
	int	i;

	i = 0;
	while (i < 32767)
	{
		map[i] = '\0';
		i++;
	}
}

void	ft_argv(int argc, char *argv[], char *charset, int *nb_lines_cols)
{
	int		i;
	char	map[32768];
	int		size_input;
	int		fd;

	i = 1;
	while (i < argc)
	{
		ft_clean(map);
		fd = open(argv[i], O_RDONLY);
		if (fd != -1)
		{
			size_input = read(fd, map, 32767);
			if (size_input == -1)
				write(1, "map error\n", 10);
			else
				ft_logic(size_input, map, charset, nb_lines_cols);
		}
		else
			write(1, "map error\n", 10);
		if (++i != argc)
			write(1, "\n", 1);
	}
}

int	main(int argc, char *argv[])
{
	char	charset[4];
	int		nb_lines_cols[2];
	char	map[32768];
	int		size_input;

	charset[3] = '\0';
	if (argc < 2)
	{
		size_input = read(0, map, 32767);
		if (size_input == -1)
			write(1, "map error\n", 10);
		else
			ft_logic(size_input, map, charset, nb_lines_cols);
	}
	else
		ft_argv(argc, argv, charset, nb_lines_cols);
	return (0);
}
