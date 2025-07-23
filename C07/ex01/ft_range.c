/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:23:23 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/23 15:27:23 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*tab;
	int	i;
	if (min >= max)
		return (0);

	len = max - min;

	tab = malloc((sizeof(int) * len));
	if (!(tab))
		return (0);


	i = 0;
	while (i < len)
	{
		tab[i] = min;
		min++;
		i++;
	}
	
	i = 0;
	while (i < len)
	{
		printf("%d\n", tab[i]);
		i++;

	}

	return (tab);
}

int	main(void)
{
	ft_range(10,20);
	return (0);
}
