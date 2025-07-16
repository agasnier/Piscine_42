/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:18:28 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/16 16:41:19 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	 ft_atoi(char *str)
{
	int	i;

	//clean all space and \t
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
	{
		i++;
	}	

	printf("%s\n", str);
	printf("%s\n", &str[i]);

	//sign even n "-" ->





	// return initial portion
	return (0);
}

int	main(void)
{
	char	str[] = "    ---+--+1234ab567";
	ft_atoi(str);
	//printf("%d", ft_atoi(str));

	return (0);
}
