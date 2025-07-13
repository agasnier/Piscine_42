/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:27:24 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/13 16:33:02 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_is_printable(char a)
{
	if (a > 127 || a < 32)
	{
		return (0);
	}

	return (1);
}

int	ft_is_uppercase(char a)
{
	if (a < 'A' || a > 'Z')
	{
		return (0);
	}
	return (1);
}

int	ft_is_lowercase(char a)
{
	if (a < 'a' || a > 'z')
	{
		return (0);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_uppercase(str[i -1]) && !ft_is_lowercase(str[i - 1]))
		{
			
				str[i] -= 32;
				break;
			
		}
		i++;
	}
	printf("%s\n", str);
	return (str);
}

int main(void)
{
	char a[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_strcapitalize(a);
	return (0);
}
