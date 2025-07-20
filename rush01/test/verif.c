/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 202/07/20 12:32:38 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/20 16:47:44 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_verif_left(char **sol, char **tab, int line, int len)
{
	int     i;
        int     comp;
        char    max;

        i = 0;
        comp = 0;
        max = '0';

        while (i < len)
        {
                if (sol[line][i] > max)
                {
                        max = sol[line][i];
                        comp++;
                }
                i++;
        }
	if (comp + '0' != tab[line + 1][0])
		return (1);
	return (0);

}

int     ft_verif_right(char **sol, char **tab, int line, int len)
{
        int     i;
        int     comp;
        char    max;

        i = len - 1;
        comp = 0;
        max = '0';

        while (i >= 0)
        {
                if (sol[line][i] > max)
                {
                        max = sol[line][i];
                        comp++;
                }
                i--;
        }
        if (comp + '0' != tab[line + 1][5])
                return (1);
        return (0);

}

int     ft_verif_up(char **sol, char **tab, int col, int len)
{
        int     i;
        int     comp;
        char    max;

        i = 1;
        comp = 0;
        max = '0';

        while (i < len )
        {
                if (sol[i][col] > max)
                {
                        max = sol[i][col];
                        comp++;
                }
                i++;
        }
        if (comp + '0' > tab[0][col + 1])
                return (1);
        return (0);

}

int     ft_verif_down(char **sol, char **tab, int col, int len)
{
        int     i;
        int     comp;
        char    max;

        i = len - 2;
        comp = 0;
        max = '0';

        while (i > 0 )
        {
                if (sol[i][col] > max)
                {
                        max = sol[i][col];
                        comp++;
                }
                i--;
        }
        if (comp + '0' > tab[0][col + 1])
                return (1);
        return (0);

}

int	ft_verif(char **sol, char **tab, int line)
{
	int i = 0;
	int len = 6;
	if (ft_verif_left(sol, tab, line, len) == 1 || ft_verif_right(sol, tab, line, len) == 1)
		return (1);
	
	while (i < 4)
	{
		if (ft_verif_up(sol, tab, i, len) == 1 || ft_verif_down(sol, tab, i, len) == 1)
			return (1);
		i++;
	}

	return (0);
}
