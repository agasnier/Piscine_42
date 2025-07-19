/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:28:34 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/19 11:53:23 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_solution()
{
	char *ptr[300];
	ptr[0] = (char *)malloc(sizeof(char)*5);

	ptr[0][0] = 'a';
	ptr[0][1] = 'b';
	ptr[0][2] = 'c';
	ptr[0][3] = 'd';
	ptr[0][4] = '\0';

	ptr[1] = (char *)malloc(sizeof(char)*5);

        ptr[1][0] = '1';
        ptr[1][1] = '2';
        ptr[1][2] = '3';
        ptr[1][3] = '4';
        ptr[1][4] = '\0';


	printf("%s", ptr[0]);
	printf("%s", ptr[1]);


}


int	main(void)
{
	ft_solution();
	return (0);

}

