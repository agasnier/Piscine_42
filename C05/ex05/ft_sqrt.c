/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 09:03:23 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/21 10:34:50 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt;

	if (nb <= 0)
		return (0);
	sqrt = 0;
	while (sqrt * sqrt <= nb)
	{
		if (sqrt * sqrt > nb)
			return (0);
		else if (sqrt * sqrt == nb)
			return (sqrt);
		sqrt++;
	}
	return (0);
}
