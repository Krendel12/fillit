/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:18:44 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/09 15:18:45 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr	*xy_backward(t_tetr *t)
{
	int		i;

	while (t->x[0] > 0 && t->x[1] > 0 && t->x[2] > 0 && t->x[3] > 0)
	{
		i = -1;
		while (++i < 4)
			t->x[i] -= 1;
	}
	while (t->y[0] > 0 && t->y[1] > 0 && t->y[2] > 0 && t->y[3] > 0)
	{
		i = -1;
		while (++i < 4)
			t->y[i] -= 1;
	}
	return (t);
}

t_tetr	*xy_forward(t_tetr *t, int side)
{
	int		i;

	i = -1;
	if (t->x[0] < side && t->x[1] < side && t->x[2] < side &&\
		t->x[3] < side)
		while (++i < 4)
			t->x[i] += 1;
	else if (t->y[0] < side && t->y[1] < side && t->y[2] < side &&\
		t->y[3] < side)
	{
		while (++i < 4)
			t->y[i] += 1;
		while (t->x[0] > 0 && t->x[1] > 0 && t->x[2] > 0 && t->x[3] > 0)
		{
			i = -1;
			while (++i < 4)
				t->x[i] -= 1;
		}
	}
	else
		return (0);
	return (t);
}

char	**pastetomap(t_tetr *t, char **map)
{
	int		i;
	int		side;

	i = -1;
	if (!t)
		return (0);
	side = 0;
	while (map[0][side])
		side++;
	if (t->x[0] < side && t->y[0] < side && t->x[1] < side && t->y[1] < side &&\
		t->x[2] < side && t->y[2] < side && t->x[3] < side && t->y[3] < side)
	{
		if (map[t->x[0]][t->y[0]] == '.' && map[t->x[1]][t->y[1]] == '.' &&\
			map[t->x[2]][t->y[2]] == '.' && map[t->x[3]][t->y[3]] == '.')
			while (++i < 4)
				map[t->x[i]][t->y[i]] = t->index;
		else
			return (0);
	}
	else
		return (0);
	return (map);
}

char	**solver(t_tetr *t, char **map, int side)
{
	char	**curmap;
	t_tetr	*temp;

	if (t->index == 0)
		return (map);
	curmap = 0;
	temp = t;
	xy_backward(temp);
	while (!curmap && temp != 0)
	{
		if ((curmap = pastetomap(temp, map)) != 0)
			curmap = solver(t + 1, curmap, side);
		if (!curmap)
			removefrommap(t, map);
		temp = xy_forward(temp, side - 1);
	}
	return (curmap);
}

char	**solver_start_point(t_tetr *t, char **map, int side)
{
	if (!(map = solver(t, map, side)))
	{
		ft_memdel((void **)map);
		side++;
		map = get_new_map(side);
		map = solver_start_point(t, map, side);
	}
	return (map);
}
