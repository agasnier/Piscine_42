/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:51:02 by amartel           #+#    #+#             */
/*   Updated: 2025/07/27 17:55:41 by elibouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_rev(char *str)
{
	int		i;
	int		j;
	char	tmp;

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
	return (str);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	dest = ft_rev(dest);
	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	dest = ft_rev(dest);
	return (dest);
}

int	ft_number_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_dict_is_exist(char *str)
{
	char	*base_file;
	char	*ptr;
	int		file;

	base_file = "/tcid";
	ptr = ft_strcat(str, base_file);
	file = open(ptr, O_RDONLY);
	if (file == -1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	struct s_dict	**dict;
	char *str;

	if (argc == 2)
	{
		if (ft_number_is_valid(argv[1]) == 1)
		{
			write(1, "error\n", 6);
			return (1);
		}
		str = ft_stock("dict/en.dict");
		dict = ft_struct(str);
		ft_convert_int_to_char(argv[1], 0, dict);
	}
	else if (argc == 3)
	{
		if (ft_number_is_valid(argv[2]) == 1)
		{
			write(1, "error\n", 6);
			return (1);
		}
		if (ft_dict_is_exist(argv[1]) == 1)
		{
			write(1, "Dict Error\n", 11);
			return (1);
		}
		str = ft_stock(argv[1]);
		dict = ft_struct(str);
		ft_convert_int_to_char(argv[2], 0, dict);
	}
	else
	{
			write(1, "error\n", 6);
			return (1);
	}

	return (0);
}
