/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:18:28 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/18 09:23:41 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	while (!(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] >= 9 && str[i] <= 13)
		{
			continue;
		}
		else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			return (0);
		}
		else if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	number *= sign;
	return (number);
}

int	main(void)
{
	char	str[] = "    ---+--+ia1234ab567";

	ft_atoi(str);
	printf("%d", ft_atoi(str));
	return (0);
}
