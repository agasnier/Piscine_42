/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:33:01 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/19 13:33:53 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	i;


	//generer en fonction du nombre de vue
	char	comb[] = "3421";
	char	tmp;
	int    row_left;
	int 	j;
	row_left = 1;

	i = 0;
	j = 0;
	while (comb[i + 1] != '\0')
	{
		tmp = comb[i];
		comb[i] = comb[i + 1];
		comb[i + 1] = tmp;
		while (comb[j] != '\0')
		{
			if (j > 0 && comb[j - 1] > comb[j])
				break;
			j++;
		}
		if (j == row_left)
		{
			printf("%s\n", comb);
		}
		i++;
	}
}
