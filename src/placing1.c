/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:50:45 by ktbatou           #+#    #+#             */
/*   Updated: 2020/12/04 02:59:42 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		placing_piece(t_map *map, t_valeur *valeur)
{
	valeur->i = 0;
	valeur->temp = 0;
	valeur->flag = 0;
	valeur->tokenx = 0;
	valeur->tokeny = 0;
	while (valeur->i < valeur->y)
	{
		valeur->j = 0;
		while (valeur->j < valeur->x)
		{
			if (map->heat[valeur->i][valeur->j] == -1)
				cords(map, valeur);
			valeur->j++;
		}
		valeur->i++;
	}
	print_cords(valeur);
	free_heat(map, valeur);
}

int			position(t_map *map, t_valeur *valeur)
{
	int	i;
	int	j;
	int	score;

	i = 0;
	score = 0;
	map->temp = 0;
	map->flag = 0;
	while (i < valeur->xp)
	{
		j = 0;
		while (j < valeur->yp)
		{
			if (map->piece[i][j] == -1)
				if (it_fits(i, j, map, valeur) == 1)
					score = score1(i, j, map, valeur);
			j++;
		}
		i++;
	}
	return (score);
}

int			it_fits(int x, int y, t_map *map, t_valeur *valeur)
{
	int		i;
	int		j;

	i = 0;
	map->flag1 = 0;
	map->tempx = 0;
	map->tempy = 0;
	while (i < valeur->xp)
	{
		j = 0;
		while (j < valeur->yp)
		{
			if (map->piece[i][j] == -1)
			{
				map->tempx = x;
				map->tempy = y;
				if (checker(i, j, map, valeur) == 0)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int			get_score(int x, int y, t_map *map, t_valeur *valeur)
{
	int	i;
	int	j;
	int	score;

	i = 0;
	score = 0;
	while (i < valeur->xp)
	{
		j = 0;
		while (j < valeur->yp)
		{
			if (map->piece[i][j] == -1)
				score += map->heat[valeur->i + (i - x)][valeur->j + (j - y)];
			j++;
		}
		i++;
	}
	return (score);
}

void		print_cords(t_valeur *v)
{
	char	*x;
	char	*y;
	int		i;

	i = 0;
	x = ft_itoa(v->tokenx);
	y = ft_itoa(v->tokeny);
	while (x[i] && i <= 1)
		write(1, &x[i++], 1);
	write(1, " ", 1);
	i = 0;
	while (y[i] && i <= 1)
		write(1, &y[i++], 1);
	write(1, "\n", 1);
}
