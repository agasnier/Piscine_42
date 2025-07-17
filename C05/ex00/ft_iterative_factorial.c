/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:20:29 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/17 11:28:56 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb < 0)
	{
		return (0);
	}

	i = nb;
	while (i == 0)
	{
		nb *= nb - 1;
		i--;
	}

	return (nb);	
}

int	main(void)
{
	int	nb = 2;
	printf("%d\n", ft_iterative_factorial(nb));
	return (0);
}
