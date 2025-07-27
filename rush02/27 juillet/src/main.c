/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:51:02 by amartel           #+#    #+#             */
/*   Updated: 2025/07/27 10:12:52 by amartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rush02.h"

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

char	*ft_strncat(char *dest, char *src)
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

int	ft_dict_is_exist(char *str)
{
	char	*base_file;
	char	*ptr;
	
	base_file = "/tcid/..";
	printf("%s\n", ptr);
	if(open(ptr ,O_RDONLY))	
		return (0);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		return (0);
	}
	else if (argc == 3)
	{
		ft_dict_is_exist(argv[1]);
		return (0);
	}
		// call function atoi for argv[2], argv[1] for refrence dict
	return (0);
}
