/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:43:29 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/16 09:17:56 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == to_find[j])
		{
			i++;
			j++;
			if (to_find[j] == '\0')
			{
				return (&str[i - j]);
			}
		}
		j = 0;
		i++;
	}
	return ((char *)0);
}

int	main(void)
{
	char	str[] = "Coucou (Diacomment ca va[Diane ?";
	char	to_find[] = "Dian";

	printf("%s", ft_strstr(str, to_find));
	return (0);
}
