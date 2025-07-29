/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:11:06 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/29 09:55:52 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_strcpy(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	**ft_put_in(char **strs, int word, char *str, char *charset)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (i < word)
	{
		while (str[j] != '\0' && ft_is_sep(str[j], charset))
			j++;
		len = 0;
		while (str[j + len] != '\0' && ft_is_sep(str[j + len], charset) != 1)
			len++;
		strs[i] = malloc(sizeof(char) * (len + 1));
		if (strs[i] == NULL)
			return (NULL);
		ft_strcpy(strs[i], &str[j], len);
		j += len;
		while (ft_is_sep(str[j], charset) == 1 && str[j] != '\0')
			j++;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (ft_is_sep(str[i], charset) == 0)
		{
			word++;
			while (ft_is_sep(str[i], charset) == 0 && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	strs = malloc(sizeof(char *) * (word + 1));
	if (strs == NULL)
		return (NULL);
	strs = ft_put_in(strs, word, str, charset);
	if (strs == NULL)
		return (NULL);
	return (strs);
}
