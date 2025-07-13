/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:20:45 by cboucher          #+#    #+#             */
/*   Updated: 2025/07/13 11:26:52 by cboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	update_line(int y, int j, char charac[])
{
	if (j == y)
	{
		charac[0] = 'A';
		charac[1] = 'B';
		charac[2] = 'C';
	}
	else if (j == 1)
	{
		charac[0] = 'C';
		charac[1] = 'B';
		charac[2] = 'A';
	}
	else
	{
		charac[0] = 'B';
		charac[1] = ' ';
		charac[2] = 'B';
	}
}

void	display_map(int x, int y)
{
	int		i;
	int		j;
	char	charac[3];

	j = y;
	while (j > 0)
	{
		update_line(y, j, charac);
		i = x;
		while (i != 0)
		{
			if (i == x)
				ft_putchar(charac[0]);
			else if (i == 1)
				ft_putchar(charac[2]);
			else
				ft_putchar(charac[1]);
			i--;
		}
		ft_putchar('\n');
		j--;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
		write(1, "Error42: A value is equal to 0 or negative", 42);
	else
		display_map(x, y);
}
