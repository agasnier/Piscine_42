/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:18:22 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/17 14:19:16 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	j;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size == 0)
	{
		return (src_len);
	}
	if (dest_len > size)
	{
		return (size + src_len);
	}
	i = 0;
	j = dest_len;
	while (j < size && src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	return (dest_len + src_len);
}
