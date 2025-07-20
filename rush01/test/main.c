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

int	ft_entry(char *argv[]);
char	**ft_init(int len);
void	ft_param(char **tab, char **argv, int len);
char	**tab_sol();
void	ft_brutforce(char **sol, char *pattern, int d, int len, int *ptr);
int	ft_verif(char **sol, char **tab, int line, int col);
void	ft_putgrid(char **tab, int len);


void	print_sol(char **tab, char **sol, int line, int num)
{
	int j;
	j = 0;
	num += 1;
	if (ft_verif(sol, tab, line, 0) == 0)
	{
		j = 0;
		while (j < 4)
		{
			tab[line + 1][j + 1] = sol[num][j];
			printf("\n%s\n", sol[num]);
			j++;
		}
		print_sol(tab, sol, line + 1, num);
	}
	else if (num < 24)
	{
		printf("%s", "num < 24");
		print_sol(tab, sol, line, num + 1);
	}
	else if (num == 24)
	{
		printf("%s", "num = 24");
		num = 0;
		print_sol(tab, sol, line - 1, num + 1);
	}
	return;
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
	
	ft_putgrid(tab, len);
	
	printf("verif: %d\n", ft_verif(sol, tab, 1, 0));

	
	printf("sol: %s\n", sol[0]);
	printf("tab: %s\n", tab[1]);
	
	print_sol(tab, sol, 0, 0);
	


	
	
	
	
	
	
	
	
	
	ft_putgrid(tab, len);
	return (0);
}
