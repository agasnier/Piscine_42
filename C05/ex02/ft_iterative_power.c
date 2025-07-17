/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:30:32 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/17 16:40:48 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power == 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);

	res = nb;
	while (power - 1 > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}
