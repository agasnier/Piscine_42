/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:51:02 by amartel           #+#    #+#             */
/*   Updated: 2025/07/26 14:16:49 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_atoi(char *str)
{
	int	nb;
	int	i;
	int negatif;
	
	nb = 0;
	negatif = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '+' || str[i] == '-') && 
		(str[i + 1] == '-' || str[i + 1] == '+'))
		return (0);
	else if (str[i] == '-')
	{
		negatif++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (negatif == 1)
		nb *= -1;
	return (nb);
}

char	*ft_rev(char *str)
{
	int i;
	int	j;
	char tmp;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	while (j < i / 2)
	{
		tmp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = tmp;
		j++;
	}
	return(str);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;
	
	dest = ft_rev(dest);
	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	dest = ft_rev(dest);
	return (dest);
}

int	ft_dict_is_exist(char *str)
{
	char	*base_file;
	char	*ptr;
	
	base_file = "/tcid/";
	ptr = ft_strncat(str, base_file, 14);
	printf("%s\n", ptr);
	if(open(ptr ,O_RDONLY))	
		return (0);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_atoi(argv[1]);
	}
	else if (argc == 3)
	{
		ft_dict_is_exist(argv[1]);
		ft_atoi(argv[2]);
	}
		// call function atoi for argv[2], argv[1] for refrence dict
	return (0);
}
