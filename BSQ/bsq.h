/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:34:19 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/29 10:35:36 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_heatmap
{
	char	map;
	int	heat;
}	t_heatmap;

void	ft_first_set(t_heatmap **structs);
int	size_hor(char *str);
int	size_vert(char *str);
void	put_in(char *str, t_heatmap **structs);
t_heatmap **ft_struct(int line, int col);
int	*ft_find_it(t_heatmap **structs, int *max);
void	ft_put_cross(t_heatmap **structs, int *max);


#endif
