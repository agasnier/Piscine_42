/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolacze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:55:41 by ykolacze          #+#    #+#             */
/*   Updated: 2025/07/20 10:32:38 by ykolacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

#include <unistd.h>
//sous fonction de second_check
void	ft_print_solution(char **tab, int l, int c)
{
	while (l < 5)
	{
		c = 1;
		while (c < 5)
		{
			write(1, &tab[l][c], 1);
			if (c != 4)
				write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		l++;
	}
}

//sous fonction de second_check
char	search_line_col(char **tab, int l, int c)
{
	int		nbr[5];
	int		i;
	char	to_return;

	i = 1;
	while (i++ < 5)
		nbr[i] = 0;
	i = 1;
	while (i++ < 5)
		nbr[(int)tab[i][c] - 48] = 1;
	i = 1;
	while (i++ < 5)
		nbr[(int)tab[l][i] - 48] = 1;
	i = 1;
	while(i++ < 5)
	{
		if (nbr[i] == 0 && to_return != '0')
			return ('0') ;
		else if (nbr[i] == 0)
			to_return = (char) nbr[i] + 48;
	}
	return (to_return);
}

//fonction et sa ses sous fonction pour les derniers chiffres et le print
void	ft_second_check(char **tab, int l, int c)
{
	int	resolved;

	resolved = 1;
	int j = 0;
	int k = 0;
	while (j < 6)
	{
		k = 0;
		while (k < 6)
		{
			printf("%c", tab[j][k]);
			k++;
		}
		printf("\n");
		j++;
	}
	while (l < 5)
	{
		c = 1;
		while (c < 5)
		{
			if ('1' <= tab[l][c] || tab[l][c] <= '4')
			{
				resolved = 0;
				tab[l][c] = search_line_col(tab, l, c);
				if (tab[l][c] != '0')
				{
					l = 0;
					c = 0;
					resolved = 1;
				}
			}
			c++;
		}
		l++;
	}
	if (resolved)
		ft_print_solution(tab, 1, 1);
	else
		write(1, "Error\n", 6);
}
