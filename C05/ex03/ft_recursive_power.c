/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:20:21 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/17 16:38:47 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{

	if (power == 0)
                return (1);
	
	nb = nb * ft_recursive_power(nb, power - 1);

	return (nb);


	
}

#include <stdio.h>

int	main(void)
{
	printf("%d", ft_recursive_power(5, 2));
	return (0);
}
