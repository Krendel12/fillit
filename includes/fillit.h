/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:07:27 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/12 11:07:28 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_tetrim
{
	int			x[4];
	int			y[4];
	char		index;
}				t_tetr;

void			*ft_memalloc(size_t size);
void			ft_putendl(char const *s);
size_t			ft_strlen(char const *s);
char			*get_line(char *fname);
int				check_line_get_ttrnum(char *line);
t_tetr			*paste_xy(char *line, t_tetr *t, char index);
t_tetr			*get_tetr_arr(char *line, int ttrnum);
int				validate_tetr_arr(t_tetr *t);
char			**solver_start_point(t_tetr *arr, char **map, int side);
void			map_print(char	**map);
char			**get_new_map(int side);
char			**removefrommap(t_tetr *t, char **map);
int				get_side(int ttrnum);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_putchar(char c);
void			ft_putendl(char const *s);
double			ft_d_sqrt(double x);

#endif
