/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:36:58 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/29 09:53:05 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_nbr_len(int nbr, int base_len);
int	ft_str_len(char *str);
int	ft_verif_base(char *base);

char	*ft_atoi(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			*sign *= -1;
		}
		i++;
	}
	return (&str[i]);
}

int	ft_in_base(char *str, char *base)
{
	int	j;

	j = 0;
	while (base[j] != '\0')
	{
		if (*str == base[j])
			return (j);
		j++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	nbr;
	int	len;
	int	i;

	sign = 1;
	len = ft_str_len(base);
	str = ft_atoi(str, &sign);
	i = 0;
	nbr = 0;
	while (ft_in_base(&str[i], base) >= 0)
	{
		nbr *= len;
		nbr += ft_in_base(&str[i], base);
		i++;
	}
	return (nbr * sign);
}

void	ft_putnbr_base(int nbr, char *base, int len_base, char *result)
{
	long	lnbr;
	int		i;

	lnbr = nbr;
	if (nbr < 0)
	{
		result[0] = '-';
		lnbr *= -1;
	}
	if (lnbr == 0)
	{
		result[0] = base[0];
		return ;
	}
	i = ft_nbr_len(nbr, len_base) - 1;
	while (lnbr > 0)
	{
		result[i--] = base[lnbr % len_base];
		lnbr /= len_base;
	}
}

char	*ft_convert_base(char *nbr_value, char *base_from, char *base_to)
{
	int		nbr;
	int		len_base_to;
	int		len_nbr_base_to;
	char	*result;

	if (ft_verif_base(base_from) || ft_verif_base(base_to))
		return (NULL);
	nbr = ft_atoi_base(nbr_value, base_from);
	len_base_to = ft_str_len(base_to);
	len_nbr_base_to = ft_nbr_len(nbr, len_base_to);
	result = malloc(sizeof(char) * (len_nbr_base_to + 1));
	if (result == NULL)
		return (NULL);
	result[len_nbr_base_to] = '\0';
	len_nbr_base_to--;
	ft_putnbr_base(nbr, base_to, len_base_to, result);
	return (result);
}
