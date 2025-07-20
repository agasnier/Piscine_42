/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:36:10 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/20 13:43:00 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_entry(char *argv[]);
char	**ft_init(int len);
void	ft_param(char **tab, char **argv, int len);
void	ft_resolve(char **tab);
void	ft_putgrid(char **tab, int len);

int	main(int argc, char *argv[])
{
	int	len;
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
	ft_resolve(tab);
	ft_putgrid(tab, len);
}
