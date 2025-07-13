/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:25:33 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/08 15:30:13 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
extern char *g_pattern;

void	ft_putchar(void)
{
	char c = g_pattern[0];
	write(1, &c, 1);
	c = g_pattern[1];
	write(1, &c, 1);
	c = g_pattern[2];
	write(1, &c, 1);
}
