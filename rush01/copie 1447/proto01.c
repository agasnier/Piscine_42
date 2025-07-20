/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolacze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:55:41 by ykolacze          #+#    #+#             */
/*   Updated: 2025/07/20 14:33:30 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_init_tab(char **tab, int *nbr, int l, int c)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		nbr[i] = 0;
		i++;
	}
	i = 1;
	while (i < 5)
	{
		if ('1' <= tab[i][c] && tab[i][c] <= '4' && i != l)
			nbr[tab[i][c] - 48] = 1;
		i++;
	}
	i = 1;
	while (i < 5)
	{
		if ('1' <= tab[l][i] && tab[l][i] <= '4' && i != c)
			nbr[tab[l][i] - 48] = 1;
		i++;
	}
}

int	search_line_col(char **tab, int l, int c)
{
	int	nbr[5];
	int	i;
	int	count;
	int	to_return;

	i = 1;
	count = 0;
	ft_init_tab(tab, nbr, l, c);
	while (i < 5)
	{
		if (nbr[i] == 0)
		{
			count++;
			to_return = i;
		}
		i++;
	}
	if (count == 1)
		return (to_return);
	return (55);
}

int	ft_second_check(char **tab, int l, int c)
{
	while (l < 5)
	{
		c = 1;
		while (c < 5)
		{
			if ('1' > tab[l][c] || tab[l][c] > '4')
			{
				tab[l][c] = '0' + search_line_col(tab, l, c);
				if ('1' <= tab[l][c] && tab[l][c] <= '4')
				{
					l = 1;
					c = 1;
				}
			}
			c++;
		}
		l++;
	}
	l = 1;
	while (l < 5)
	{
		c = 1;
		while (c < 5)
		{
			if ('1' > tab[l][c] || tab[l][c] > '4')
						return (1);
			c++;
		}
		l++;
	}
	return (0);
}
