/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:47:04 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/15 09:38:29 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	while (dest[len] != '\0')
	{
		len++;
	}
	
	i = 0;
	while ((dest[i] != '\0' || src[i] != '\0') && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	printf("%d\n", len);
	return (len);
}

int main(void)
{
	char src[] = "Alexandre";
	char dest[4];

	printf("%s\n%s\n", src, dest);
	ft_strlcpy(dest, src, 8);

}
