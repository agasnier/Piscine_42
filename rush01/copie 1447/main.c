/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:36:10 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/20 14:18:22 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_entry(char *argv[]);
char	**ft_init(int len);
void	ft_param(char **tab, char **argv, int len);
int		ft_resolve(char **tab);
void	ft_putgrid(char **tab, int len);

int	main(int argc, char *argv[])
{
	int		len;
	char	**tab;

	len = 4;
	len += 2;
	if (argc != 2 || ft_entry(argv) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	tab = ft_init(len);
	ft_param(tab, argv, len);
	if (ft_resolve(tab) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_putgrid(tab, len);
	return (0);
}
