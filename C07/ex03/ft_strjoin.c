/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:23:56 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/23 16:56:54 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>




//calcul de len entiere + sep * (size - 1)
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

int ft_strs_len(int size, char **strs, char *sep)
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


char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int len;
	int	k;
	char	*ptr;

	len = ft_strs_len(size, strs, sep);
	ptr = malloc(sizeof(char) * len + 1);
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
	return (ptr);
}

int	main(void)
{
	char *strs[3];
	strs[0] = "Alex";
	strs[1] = "Alba";
	strs[2] = "Dian";
	char *sep = ", ";
	printf("%s" ,ft_strjoin(3, strs, sep));



	return (0);
}


