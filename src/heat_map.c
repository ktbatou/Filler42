/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:47:20 by ktbatou           #+#    #+#             */
/*   Updated: 2020/12/03 03:16:24 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	heat_map(t_valeur *valeur, t_map *map)
{
	int		i;
	int		j;
	int		index;

	map->heater = 1;
	map->temp = -2;
	index = 0;
	while (index < valeur->x)
	{
		i = 0;
		while (i < valeur->y)
		{
			j = 0;
			while (j < valeur->x)
			{
				if (map->heat[i][j] == map->temp)
					heating(map, i, j);
				j++;
			}
			i++;
		}
		map->temp = map->heater;
		map->heater++;
		index++;
	}
}

void	heating(t_map *map, int i, int j)
{
	if ((j >= 0 && j < 16) && (map->heat[i][j + 1] == 0))
		map->heat[i][j + 1] = map->heater;
	if ((j > 0 && j <= 16) && map->heat[i][j - 1] == 0)
		map->heat[i][j - 1] = map->heater;
	if ((i >= 0 && i < 14) && map->heat[i + 1][j] == 0)
		map->heat[i + 1][j] = map->heater;
	if ((i > 0 && i <= 14) && map->heat[i - 1][j] == 0)
		map->heat[i - 1][j] = map->heater;
	if ((j >= 0 && j < 16) &&
		(i >= 0 && i < 14) && map->heat[i + 1][j + 1] == 0)
		map->heat[i + 1][j + 1] = map->heater;
	if ((i >= 0 && i < 14) &&
		(j > 0 && j <= 16) && map->heat[i + 1][j - 1] == 0)
		map->heat[i + 1][j - 1] = map->heater;
	if ((j >= 0 && j < 16) &&
		(i > 0 && i <= 14) && map->heat[i - 1][j + 1] == 0)
		map->heat[i - 1][j + 1] = map->heater;
	if ((i > 0 && i <= 14) &&
		(j > 0 && j <= 16) && map->heat[i - 1][j - 1] == 0)
		map->heat[i - 1][j - 1] = map->heater;
}
