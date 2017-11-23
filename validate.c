/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:06:13 by astrelov          #+#    #+#             */
/*   Updated: 2017/11/12 11:06:14 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_line(char *fname)
{
	int		fd;
	int		len;
	char	temp;
	char	*line;

	if (!(fd = open(fname, O_RDONLY)))
		return (0);
	len = 0;
	while (read(fd, &temp, 1))
		len++;
	close(fd);
	if (len > 21 * 26 - 1)
		return (0);
	if (!(line = ft_memalloc(len + 1)))
		return (0);
	if (!(fd = open(fname, O_RDONLY)))
		return (0);
	while (read(fd, &temp, 1))
		*line++ = temp;
	close(fd);
	return (line - len);
}

int		check_line_get_ttrnum(char *line)
{
	int		i;
	int		nlnum;
	int		dotnum;
	int		hashnum;
	int		res;

	i = -1;
	dotnum = 0;
	nlnum = 0;
	hashnum = 0;
	while (++i < 20 && *(line + i))
	{
		(*(line + i) == '\n') ? nlnum++ : 1;
		(*(line + i) == '.') ? dotnum++ : 1;
		(*(line + i) == '#') ? hashnum++ : 1;
	}
	if (dotnum != 12 || hashnum != 4 || nlnum != 4)
		return (0);
	res = 1;
	if (*(line + i) == '\n' || *(line + i) == '.' || *(line + i) == '#')
	{
		res = check_line_get_ttrnum(line + i + 1);
		(res == 0) ? 1 : res++;
	}
	return (res);
}

t_tetr	*get_tetr_arr(char *line, int ttrnum)
{
	char	ind;
	t_tetr	*t;

	if (!(t = ft_memalloc(sizeof(t_tetr) * (ttrnum + 1))))
		return (0);
	ind = 'A';
	while (*line == '#' || *line == '.')
	{
		t = paste_xy(line, t, ind++);
		line += 21;
		t++;
	}
	t->index = 0;
	return (t - ttrnum);
}

t_tetr	*paste_xy(char *line, t_tetr *t, char index)
{
	int		x;
	int		y;
	int		i;
	int		ind;

	i = -1;
	x = 0;
	y = 0;
	ind = 0;
	while (++i < 20)
	{
		((i + 1) % 5 == 0) ? y++ : 1;
		if (*(line + i) == '#')
		{
			t->x[ind] = x;
			t->y[ind++] = y;
		}
		(x++ == 4) ? x = 0 : 1;
	}
	t->index = index;
	return (t);
}

int		validate_tetr_arr(t_tetr *t)
{
	int		amount;
	int		i;
	int		j;

	amount = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i != j)
			{
				(t->x[i] + 1 == t->x[j] && t->y[i] == t->y[j]) ? amount++ : 1;
				(t->y[i] + 1 == t->y[j] && t->x[i] == t->x[j]) ? amount++ : 1;
				(t->x[i] - 1 == t->x[j] && t->y[i] == t->y[j]) ? amount++ : 1;
				(t->y[i] - 1 == t->y[j] && t->x[i] == t->x[j]) ? amount++ : 1;
			}
		}
	}
	if (amount < 6)
		return (0);
	if ((t + 1)->index != 0)
		return (validate_tetr_arr(t + 1));
	return (1);
}
