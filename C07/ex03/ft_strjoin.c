/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:23:56 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/23 16:56:54 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */






//calcul de len entiere + sep * (size - 1)
int	ft_len_size(int size, char **strs, char *sep)
{
	int	i;
	int len;

	i = 0;
	j = 0;
	len = 0 + (size - 1);
	while (i <= size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}



char	*ft_strjoin(int size, char **strs, char *sep)
{
	//function calcul de la taille entiere


	//malloc pour creation string


	//iz size = 0





	retrun (str);
}



