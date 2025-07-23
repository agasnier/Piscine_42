/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:24:28 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/23 10:55:29 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
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

	len = ft_str_len(base);
	if (len < 2)
		return (1);
	i = 0;
	j = 0;
	while (i < len)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (1);
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


char	*ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	return (&str[i]);
}



// retourne l'index du carac dans la base
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



int	ft_print_base(char *str, char *base)
{
	int	len;
	int	nbr;
	int	i;

	len = ft_str_len(base);
	//parsing de la base pour trouver la position du carac
	i = 0;
	nbr = 0;
	while (ft_in_base(&str[i], base) >= 0)
	{
		nbr *= len;
		nbr += ft_in_base(&str[i], base);
		i++;
	}

	return (nbr);
}




int	ft_atoi_base(char *str, char *base)
{
	//verifier base valid
	if (ft_verif_base(base) == 1)
		return (0);

	//trouver les premiers valeur aui sont dans la base
	str = ft_atoi(str);
	printf("%s\n", str);

	//convertir la base en int
	printf("%d",ft_print_base(str, base));


	return (0);


}


int	main(void)
{
	char	base[] = "0123456789ABCDEF";
	char	str[] = "    ---+499450D5abc";
	ft_atoi_base(str, base);
	return (0);



}
