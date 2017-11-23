/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:03:05 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/12 17:03:06 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		name_this(char *line)
{
	int		ttrnum;
	char	**map;
	t_tetr	*t;
	int		side;

	if (!(ttrnum = check_line_get_ttrnum(line)))
		return (0);
	if (!(t = get_tetr_arr(line, ttrnum)))
		return (0);
	if (!(validate_tetr_arr(t)))
	{
		free(t);
		return (0);
	}
	side = get_side(ttrnum);
	if (!(map = get_new_map(side)))
		return (0);
	map_print(map = solver_start_point(t, map, side));
	return (1);
}

int		main(int argc, char **argv)
{
	char	*line;

	if (argc != 2)
	{
		ft_putendl("error");
		return (0);
	}
	if (!(line = get_line(argv[1])))
	{
		ft_putendl("error");
		return (0);
	}
	if (!(name_this(line)))
		ft_putendl("error");
	free(line);
	return (0);
}
