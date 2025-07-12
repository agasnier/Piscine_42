/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 11:19:02 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/12 12:39:27 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_a_line(char s, char m, char e, int x)
{
	//int	i;

	m = e;

	if (x <= 0)
	{
		write(1, "error\n", 6);
	}
	else if (x == 1)
	{
		ft_putchar(s);
		ft_putchar('\n');
	}
	else
	{
		ft_putchar(s);
		while ((x 
		ft_putchar('\n');
	}

}





void	rush(int x, int y)
{
	char	s = 'A';
	char	m = 'B';
	char	e = 'C';
	int 	i;

	i = 0;
	while (i < y)
	{
		print_a_line(s, m, e, x);
		i++;
	}
}






int	main(/*int argc, char **argv*/)
{
	/*if (argc <= 1)
	{
		write(1, "Mettez le numero du rush voulu\n", 31);
		return (0);
	}

	else
	{
		char	s;
		char	m;
		char	e;
	
		if (*argv[1] == '2')
		{
			s = 'A';
			m = 'B';
			e = 'C';
		}
		else
		{
			s = 'E';
			m = 'X';
			e = 'W';
		}
	
		ft_putchar(s);
		ft_putchar(m);
		ft_putchar(e);
		return (0);
	}*/


	rush(1, 10);
	ft_putchar('\n');
	rush(2, 3);






}
