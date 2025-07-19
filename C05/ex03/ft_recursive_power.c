/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:20:21 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/18 09:16:00 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{

	if (nb == 0 && power == 0)
                return (1);
	if (power <= 0)
		return (0);
	if (power >= 2)
	{
		nb = nb * ft_recursive_power(nb, power - 1);
	}
	return (nb);


	
}

#include <stdio.h>

int	main(void)
{
	printf("%d", ft_recursive_power(0, 0));
	return (0);
}
