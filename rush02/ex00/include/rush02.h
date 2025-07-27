/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elibouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:11:23 by elibouch          #+#    #+#             */
/*   Updated: 2025/07/27 18:41:14 by amartel          ###   ########.fr       */
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

typedef struct s_dict
{
	char	*number;
	char	*carac;
}	t_Dict;
void			ft_puttab(char *dst, char *src, int j);
int				ft_puttab_number(struct s_dict **paires, char *str);
int				ft_puttab_carac(struct s_dict **paires, char *str);
struct	s_dict	**ft_struct(char *str);
void			ft_putchar(char *str);
char			*ft_stock(char *str);
void			ft_convert_int_to_char(char *str, int i, struct s_dict **dict);
void			ft_print_aplha_num(char *c, struct s_dict **dict);
#endif
