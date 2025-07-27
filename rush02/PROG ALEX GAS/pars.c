/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:02:40 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/27 18:02:31 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/rush02.h"

int	ft_verif(char *str, int *j)
{
	int	i;

	i = *j;
	while (str[i] != '\n')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (!(str[i] == ' ' || str[i] == ':'))
			return (1);
		while (str[i] == ' ')
			i++;
		if (str[i] != ':')
			return (1);
		if (str[i] == ':')
			i++;
		if (!(str[i] >= ' ' && str[i] <= '~'))
			return (1);
		while (str[i] >= ' ' && str[i] <= '~')
			i++;
	}
	*j = i;
	return (0);
}

int	ft_str_good(char *str)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		if (ft_verif(str, &j))
			return (1);
		j++;
	}
	return (0);
}

void	ft_pars(char *str, char *tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tmp[i] != '\0')
	{
		while (tmp[i] >= '0' && tmp[i] <= '9')
			str[j++] = tmp[i++];
		while (tmp[i] == ' ')
			i++;
		if (tmp[i] == ':')
			str[j++] = tmp[i++];
		while (tmp[i] == ' ')
			i++;
		while ((tmp[i] >= ' ' && tmp[i] <= '~'))
			str[j++] = tmp[i++];
		while (str[i] == '\n')
			i++;
		str[j++] = '\n';	
	}
	str[j] = '\0';
}

char	*ft_stock(void)
{
	int		fd;
	int		t_read;
	char	tmp[2048];
	char	*str;

	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		return (NULL);
	t_read = read(fd, tmp, 2048);
	if (t_read == -1)
		return (NULL);
	tmp[t_read] = '\0';
	if (ft_str_good(tmp) == 1)
	{
		write(1, "Dict Error\n", 11);
		return (NULL);
	}
	str = malloc((sizeof(char) * t_read) + 1);
	if (str == NULL)
		return (NULL);
	ft_pars(str, tmp);
	close(fd);
	return (str);
}


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
	{
		i++;
	}
	if (s1[i] != s2[i])
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}





int	main(void)
{
	struct s_dict	**dict;
	char			*str;
	int				i;
	/* -------------------------------------------  */
	str = ft_stock();
	if (str == NULL)
		return (1);
	/* --------------------------------------------*/	
	dict = ft_struct(str);
	if (dict == NULL)
		return (1);
	/*------------------------------------------------*/
	
	//char test[] = "100";
	i = 0;
	while (dict[i] != NULL && i < 10)
	{
		//if (ft_strcmp(dict[i]->number, test) == 0)
		//{
			printf("\nNumber:%s\n", dict[i]->number);
			printf("Caractere: %s\n", dict[i]->carac);
		//}
		i++;
	}
	return (0);
}
