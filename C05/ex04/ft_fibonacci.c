/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:27:20 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/18 11:35:17 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	res;
	if (index < 0)
		return (-1);
	if (index <= 2)
		return (1);
	
	res = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (res);
}

#include <stdio.h>

int	main(void)
{
	printf("%d", ft_fibonacci(5));

	return (0);
}
