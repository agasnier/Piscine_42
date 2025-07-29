/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:23:56 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/29 09:52:00 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strs_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_str_len(strs[i]);
		i++;
	}
	len += (size - 1) * ft_str_len(sep);
	return (len);
}

void	ft_remplissage(int size, char **strs, char *sep, char *ptr)
{
	int	k;
	int	j;
	int	i;

	k = 0;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (strs[j][i] != '\0')
		{
			ptr[k] = strs[j][i];
			i++;
			k++;
		}
		i = 0;
		while (sep[i] != '\0' && j < size - 1)
		{
			ptr[k] = sep[i];
			i++;
			k++;
		}
		j++;
	}
	ptr[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*ptr;

	len = ft_strs_len(size, strs, sep);
	if (size == 0)
		len = 0;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	if (size > 0)
		ft_remplissage(size, strs, sep, ptr);
	return (ptr);
}
