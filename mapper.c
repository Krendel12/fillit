/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:11:02 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/09 12:11:03 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_side(int ttrnum)
{
	int		area;
	int		side;

	side = 0;
	area = 3;
	while (ttrnum * 4 > side * side)
		side = (int)ft_d_sqrt(++area);
	return (side);
}

void	map_print(char **map)
{
	int		i;
	int		j;
	int		side;

	i = -1;
	if (!map)
		return ;
	side = 0;
	while (map[0][side])
		side++;
	while (++i < side)
	{
		j = -1;
		while (++j < side)
			ft_putchar(map[j][i]);
		ft_putchar('\n');
	}
}

void	map_dotter(char **map, int side)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < side)
	{
		j = 0;
		while (j < side)
			map[i][j++] = '.';
	}
	map[side] = 0;
}

char	**get_new_map(int side)
{
	char	**map;
	int		i;

	if (!(map = (char **)ft_memalloc(sizeof(char *) * (side + 1))))
		return (0);
	i = -1;
	while (++i < side)
		if (!(map[i] = (char *)ft_memalloc(side + 1)))
			return (0);
	map_dotter(map, side);
	return (map);
}

char	**removefrommap(t_tetr *t, char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == t->index)
				map[i][j] = '.';
	}
	return (map);
}
