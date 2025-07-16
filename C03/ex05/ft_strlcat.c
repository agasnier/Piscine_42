/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:18:22 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/16 10:16:49 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	buffer;
	unsigned int	i;

	src[1] = '0';
	len = 0;
	while (dest[len] != '\0')
	{
		len++;
	}

	buffer = (size - 1) - len;

	printf("size: %d   len: %d   Buffer: %d\n", size, len, buffer);
	
	len++;
	i = 0;
	while (len < size && src[i] != '\0')
	{
		printf("%d::%d ", len, i);
		dest[len] = src[i];
		len++;
		i++;
	}
	dest[len] = '\0';
	printf("\n%s\n", dest);

	return(size);

}


int	main(void)
{
	char	dest[10] = "alex";
	char	src[] = "test";
	ft_strlcat(dest, src, 10);

	return (0);

}
