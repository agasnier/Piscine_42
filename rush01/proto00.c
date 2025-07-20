/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykolacze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:37:54 by ykolacze          #+#    #+#             */
/*   Updated: 2025/07/20 10:31:57 by ykolacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>

#include <unistd.h>

void	ft_second_check(char **tab, int l, int c);

// Sous fonction de check_col
void	ft_put_col(char **tab, int l, int c, int pattern)
{
	if (pattern == 1)
	{
		tab[l]["100004"[c] - 48] = '4';
		tab[l]["400001"[c] - 48] = '3';
	}
	else if (pattern == 2)
	{
		tab[l]["100004"[c] - 48] = '4';
		tab[l]["400001"[c] - 48] = '2';
	}
	else if (pattern == 3)

	{
		tab[l]["400001"[c] - 48] = '1';
		tab[l]["300002"[c] - 48] = '2';
		tab[l]["200003"[c] - 48] = '3';
		tab[l]["100004"[c] - 48] = '4';
	}
	else if (pattern == 4)
		tab[l]["200003"[c] - 48] = '4';
}

// Fonction de verification des side to side des col left et right
void	ft_check_col(char **tab, int l, int c, int *count)
{
	while (l < 5)
	{
		if (tab[l][5 - c] == '1' && (tab[l][c] == '2' || tab[l][c] == '3'
			|| tab[l][c] == '4'))
		{
			*count = *count + 1;
			if (tab[l][c] == '2')
				ft_put_col(tab, l, 5 - c, 1);
			else if (tab[l][c] == '3')
				ft_put_col(tab, l, 5 - c, 2);
			else if (tab[l][c] == '4')
				ft_put_col(tab, l, 5 - c, 3);
		}
		else if (tab[l][5 - c] == '2' && (tab[l][c] == '2' || tab[l][c] == '3'))
		{
			*count = *count + 1;
			if (tab[l][c] == '2' && c == 5)
				*count = *count - 1;
			else if(tab[l][c] == '3')
				ft_put_col(tab, l, 5 - c, 4);
		}
		if (l == 4 && c == 5)
			ft_check_col(tab, 1, 0, count);
		l++;
	}
	int j = 0;
	int k;
	while (j < 6 && c == 0)
	{
		k = 0;
		while (k < 6)
		{
			printf("%c", tab[j][k]);
			k++;
		}

			printf("-----3\n");
		j++;
	}

}

// Sous fonction de check_line
void	ft_put_line(char **tab, int l, int c, int pattern)
{
	if (pattern == 1)
	{
		tab[("100004"[l] - 48)][c] = '4';
		tab[("400001"[l] - 48)][c] = '3';
	}
	else if (pattern == 2)
	{
		tab[("100004"[l] - 48)][c] = '4';
		tab[("400001"[l] - 48)][c] = '2';
	}
	else if (pattern == 3)
	{
		tab[("400001"[l] - 48)][c] = '1';
		tab[("300002"[l] - 48)][c] = '2';
		tab[("200003"[l] - 48)][c] = '3';
		tab[("100004"[l] - 48)][c] = '4';
	}	
	else if (pattern == 4)
		tab[("200003"[l] - 48)][c] = '4';
}

// Fonction de verification des side to side des lignes top et bottom 
void	ft_check_line(char **tab, int l, int c, int *count)
{
	while (c < 5)
	{
		if (tab[5 - l][c] == '1' && (tab[l][c] == '2' || tab[l][c] == '3'
			|| tab[l][c] == '4'))
		{
			*count = *count + 1;
			if (tab[l][c] == '2')
				ft_put_line(tab, 5 - l, c, 1);
			else if (tab[l][c] == '3')
				ft_put_line(tab, 5 - l, c, 2);
			else if (tab[l][c] == '4')
				ft_put_line(tab, 5 - l, c, 3);
		}
		else if (tab[5 - l][c] == '2' && (tab[l][c] == '2' || tab[l][c] == '3'))
		{
			*count = *count + 1;
			if (tab[l][c] == '2' && l == 5)
				*count = *count - 1;
			else if (tab[l][c] == '3')
				ft_put_line(tab, 5 - l, c, 4);
		}
		if (l == 5 && c == 4)
			ft_check_line(tab, 0, 1, count);
		c++;
	}
	int j = 0;
	int k = 0;
	while (j < 6 && l == 0)
	{
		k = 0;
		while (k < 6)
		{
			printf("%c", tab[j][k]);
			k++;
		}

			printf("------2\n");
		j++;
	}
	
}


// Fonction qu'il faudrait merge avec la fonction principale
void	ft_resolve(char **tab)
{
	int j = 0;
	int k = 0;

	while (j < 6)
	{
		k = 0;
		while (k < 6)
		{
			printf("%c", tab[j][k]);
			k++;
		}

			printf("-------0\n");
		j++;
	}
	int	count;

	count = 0;
	ft_check_line(tab, 5, 1, &count);
	ft_check_col(tab, 1, 5, &count);
	if (count != 8)
	{
		write(1, "Error\n", 6);
		return ;
	}
	j = 0;
	k = 0;
	while (j < 6)
	{
		k = 0;
		while (k < 6)
		{
			printf("%c", tab[j][k]);
			k++;
		}

			printf("-------1\n");
		j++;
	}
	ft_second_check(tab, 1, 1);
}
