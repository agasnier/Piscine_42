/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:34:19 by algasnie          #+#    #+#             */
/*   Updated: 2025/07/30 17:55:17 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_heatmap
{
	char	map;
	int		heat;
}	t_heatmap;

void		ft_first_set(t_heatmap **structs, char *charset);
void		put_in(char *str, t_heatmap **structs);
t_heatmap	**ft_struct(int line, int col);
int			*ft_find_it(t_heatmap **structs, int *max);
void		ft_put_cross(t_heatmap **structs, int *max, char *charset);
int			parsing(char *map, char *charset, int *nb_lines, int *nb_cols);
int			is_printable(char c);
int			extract_nb(int *nb_lines, int nb_lines_size, char *map);
int			check_number_of_lines(char *map, int *i);
void		ft_display_map(t_heatmap **structs);
int			ft_resolve(char *map, char *charset, int nb_lines, int nb_cols);
void		ft_argv(int argc, char *argv[], \
char *charset, int nb_lines_cols[2]);
void		ft_free_all(t_heatmap **structs);

#endif
