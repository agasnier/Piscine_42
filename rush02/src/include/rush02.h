/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elibouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:11:23 by elibouch          #+#    #+#             */
/*   Updated: 2025/07/26 15:08:06 by elibouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

//open,read
# include <fcntl.h>

//close
# include <unistd.h>

//malloc
# include <stdlib.h>

//printf
# include <stdio.h>


typedef struct	s_dict
{
	int number;
	char	*carac;
} t_Dict;

typedef struct s_my_struct
{
	int	my_var;
	int	my_string;
	char	my_char;
}	t_My_struct;

char	*ft_stock(void);

#endif
