/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:47:04 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/15 10:27:53 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	
	i = 0;
	if (size > 0)
	{	
		while (dest[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	i++;
	dest[i] = '\0';
	return (size);
}
