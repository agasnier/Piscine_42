/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:54:48 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/23 16:22:41 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;
	if (min >= max)
		return (0);

	len = max - min;

	range = malloc((sizeof(int *) * len));
	if (!(range))
		return (0);

	i = 0;
	while (i < len)
	{
		range[i] = malloc((sizeof(int) * len));
		i++;
	}


	i = 0;
	while (i < len)
	{
		range[i][0] = min;
		min++;
		i++;
	}
	
	i = 0;
	while (i < len)
	{
		printf("%d\n", range[i][0]);
		i++;

	}

	return (0);

}



int	main(void)
{
	int **range;

	range = malloc(sizeof(int *));
	ft_ultimate_range(range,10,20);
	return (0);
}
