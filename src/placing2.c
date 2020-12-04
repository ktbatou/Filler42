/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 02:04:24 by ktbatou           #+#    #+#             */
/*   Updated: 2020/12/04 03:00:56 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	cords(t_map *map, t_valeur *valeur)
{
	int	score;

	score = 0;
	score = position(map, valeur);
	if ((score < valeur->temp && score != 0) ||
	(valeur->flag == 0 && score != 0))
	{
		valeur->flag = 1;
		valeur->temp = score;
		valeur->tokenx = valeur->i - map->x;
		valeur->tokeny = valeur->j - map->y;
	}
}

int		score1(int i, int j, t_map *map, t_valeur *valeur)
{
	int	score;

	score = 0;
	score = get_score(i, j, map, valeur);
	if (score < map->temp || map->flag == 0)
	{
		map->flag = 1;
		map->temp = score;
		map->x = i;
		map->y = j;
	}
	return (score);
}

int		checker(int i, int j, t_map *map, t_valeur *valeur)
{
	int	x;
	int	y;

	x = map->tempx;
	y = map->tempy;
	if (valeur->i + (i - x) > (valeur->y - 1) ||
		valeur->j + (j - y) > (valeur->x - 1) ||
		(valeur->j + (j - y) < 0) || valeur->i + (i - x) < 0)
		return (0);
	if (map->heat[valeur->i + (i - x)][valeur->j + (j - y)] == -1)
		map->flag1++;
	if (map->heat[valeur->i + (i - x)][valeur->j + (j - y)] == -2)
		return (0);
	if (map->flag1 > 1)
		return (0);
	return (1);
}
