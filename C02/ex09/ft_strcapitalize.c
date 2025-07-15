/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:27:24 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/14 16:05:19 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_is_alpha_num(char *letter, int *mot)
{
	if ((*letter >= 'A' && *letter <= 'Z')
		|| (*letter >= 'a' && *letter <= 'z')
		|| (*letter >= '0' && *letter <= '9'))
	{
		if (*mot == 0 && (*letter >= 'a' && *letter <= 'z'))
		{
			*letter -= 32 ;
		}
		else if (*mot == 1 && (*letter >= 'A' && *letter <= 'Z'))
		{
			*letter += 32;
		}
		*mot = 1;
	}
	else
	{
		*mot = 0;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	mot;

	mot = 0;
	i = 0;
	while (str[i] != '\0')
	{
		ft_is_alpha_num(&str[i], &mot);
		i++;
	}
	return (str);
}
