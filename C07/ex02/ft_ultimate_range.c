/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:54:48 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/29 09:49:42 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;
	int	*ptr;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	len = max - min;
	ptr = malloc(sizeof(int) * len);
	if (ptr == NULL)
		return (-1);
	*range = ptr;
	i = 0;
	while (i < len)
	{
		ptr[i] = min + i;
		i++;
	}
	return (len);
}
