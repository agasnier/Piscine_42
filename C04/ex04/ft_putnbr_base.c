/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:30:04 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/22 16:51:09 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_len_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_verif_base(char *base)
{
	int	i;
	int	j;
	int	len;

	len = ft_len_base(base);
	if (len < 2)
		return (1);
	i = 0;
	j = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	if (ft_verif_base(base) == 0)
	{
		len = ft_len_base(base);
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr *= -1;
		}
		if (nbr / len != 0)
			ft_putnbr_base(nbr / len, base);
		write(1, &base[nbr % len], 1);
	}
}

int	main(void)
{
	int nbr = -987654321;
	char base[] = "0123456789ABCDEF";
	ft_putnbr_base(nbr, base);
}
