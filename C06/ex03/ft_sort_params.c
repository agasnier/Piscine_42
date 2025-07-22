/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:36:47 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/21 16:54:57 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
	{
		i++;
	}
	if (s1[i] != s2[i])
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}*/
#include <stdio.h>
int	ft_swap(char *tab1, char *tab2)
{
	char *tmp;
	
	tmp = tab1;
	printf("%s tab2\n", tab2);
	tab1 = tab2;
	printf("%s tab2\n", tab2);
	tab2 = tmp;
	printf("%s tab2 \n", tab2);
	return (1);
}







int	main(int argc, char *argv[])
{	
	if (argc)
	{
		if (ft_swap(argv[0], argv[1]) == 1)
		{
			printf("%s\n", argv[0]);
			printf("%s", argv[1]);
		}
		
	}
	return (0);
}
