/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 08:35:31 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/14 10:36:15 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	n;
	int	tmp;

	n = 0;
	while (n <= size)
	{
		if (tab[n] < tab[n - 1] && n != 0)
		{
			tmp = tab[n];
			tab[n] = tab[n - 1];
			tab[n - 1] = tmp;
			n--;
		}
		else
		{
			n++;
		}
	}
}
