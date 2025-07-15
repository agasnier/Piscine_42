/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:43:29 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/15 16:59:21 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	l;
	int	i;
	int	j;

	l = 0;
	while (to_find[l] != '\0')
	{
		l++;
	}

	if (l == 0)
	{
		return (str);
	}
	
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			j++;
			if (j == l)
	                {
        	                return(&str[i - (l - 1)]);
                	}
		}
		i++;
	}
	return(str);
}





int main(void)
{
	char str[] = "Coucou comment ca va[Diane ?";
	char to_find[] = "Diane";

	printf("%s", ft_strstr(str, to_find));
	return (0);
}
