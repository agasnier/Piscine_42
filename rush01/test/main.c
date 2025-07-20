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
char	**tab_sol();
void	ft_brutforce(char **sol, char *pattern, int d, int len, int *ptr);
int		print_sol(char **tab, char **sol, int line);
int		ft_verif(char **tab, int line);
void	ft_putgrid(char **tab);


int	print_sol(char **tab, char **sol, int line)
{
	int i;
	if (line == 4)
		return (1);

	i = 0;
while (i < 24)
{
	int j = 0;
	while (j < 4)
	{
		tab[line + 1][j + 1] = sol[i][j];
		j++;
	}

	if (ft_verif(tab, line) == 0)
	{
		if (print_sol(tab, sol, line + 1) == 1)
			return (1);
	}
	j = 1;
	while (j <= 4)
		tab[line + 1][j++] = ' ';

	i++;
}

	return (0);
}

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
	
	
	
	char pattern[] = "1234";
	char **sol = tab_sol();
	int comp = 0;
	int *ptr = &comp;
	ft_brutforce(sol, pattern, 0, len - 2, ptr);
	if (print_sol(tab, sol, 0) == 0)
		write(1, "Error\n", 6);
	else	
		ft_putgrid(tab);


	return (0);
}
