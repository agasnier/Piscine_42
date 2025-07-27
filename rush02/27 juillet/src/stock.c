/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 09:13:13 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/26 16:38:51 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/include/rush02.h"

char	*ft_stock(void)
{
	int		fd;
	int		t_read;
	char	tmp[1024];
	char	*str;
	int		i;

	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		return (NULL);
	t_read = read(fd, tmp, 1024);
	if (t_read == -1)
		return (NULL);
	tmp[t_read] = '\0';
	str = malloc((sizeof(char) * t_read) + 1);
	i = 0;
	while (tmp[i])
	{
		str[i] = tmp[i];
		i++;
	}
	str[i] = '\0';
	close(fd);
	return (str);
}

void	ft_puttab(struct s_dict **paires, char *src, int j, int index)
{
	int	i;

	paires[index]->number = malloc(sizeof(char) * (j + 1));
	i = 0;
	while (i < j)
	{
		paires[index]->number[i] = src[i];
		i++;
	}
	paires[index]->number[i] = '\0';
}

void	ft_pars(struct s_dict **paires, char *str)
{
	int	i;
	int	index;
	int	j;

	i = 0;
	index = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] >= '0' && str[i] <= '9')
		{
			
			
			while (str[i + j] >= '0' && str [i + j] <= '9')
				j++;
			printf("J::::%d\n\n", j);
			//paires[index]->number = malloc(sizeof(char) * (j + 1));
			ft_puttab(paires, &str[i], j, index);
		}
		i +=j;
		j = 0;
		
		if (str[i] == '\n' && str[i + 1] != '\0')
			index++;
		i +=j;
		i++;
		printf("%d\n", index);
	}
		
		
		
//remplissage carac		
		/*if (str[i] >= '!' && str[i] <= '~')
		{
			while (str[i + j] >= '!' && str[i + j] <= '~')
				j++;
			paires[index]->carac = malloc(sizeof(char) * (j + 1));
			ft_puttab(paires[index]->carac, &str[i], j);
		}*/
		
		
		

}

struct	s_dict	**ft_struct(char *str)
{
	int			count;
	int			i;
	struct s_dict	**paires;

	count = 0;
	i = 0;
	while (str[i++] != '\0')
		if (str[i] == '\n')
			count++;
	paires = malloc(sizeof(struct s_dict *) * (count + 1));
	if (paires == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		paires[i] = malloc(sizeof(struct s_dict));
		if (paires[i] == NULL)
			return (NULL);
		i++;
	}
	paires[i] = NULL;
	ft_pars(paires, str);
	return (paires);
}

int	main(void)
{
	struct s_dict	**dict;
	char		*str;

	str = ft_stock();
	printf("%s\n", str);
	printf("\nImpression du dict:\n%s\n", str);
	dict = ft_struct(str);
	printf("\n\n struc:%s\n", dict[3]->number);
	return (0);
}
