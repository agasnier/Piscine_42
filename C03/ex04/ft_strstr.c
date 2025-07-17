/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:43:29 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/17 11:46:43 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
	{
		return (&str[i]);
	}
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
			{
				return (&str[i]);
			}
		}
		j = 0;
		i++;
	}
	return ((char *)0);
}

int main(void)
{
	char str[] = "Je savais que la correction serait severe";
	char to_find[] = "la";

	printf("%s", ft_strstr(str, to_find));

	return (0);
}
