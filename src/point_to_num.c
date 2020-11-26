/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_to_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:17:32 by ktbatou           #+#    #+#             */
/*   Updated: 2020/11/06 01:30:53 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	map_num(t_valeur *valeur, t_data *data, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	map->heat = (int**)malloc(sizeof(int*) * valeur->y);
	while (i < valeur->y)
	{
		j = 0;
		map->heat[i] = (int*)malloc(sizeof(int) * valeur->x);
		while (j < valeur->x)
		{
			if (data->map[i][j] == data->player)
				map->heat[i][j] = -1;
			else if (data->map[i][j] != '.')
				map->heat[i][j] = -2;
			else
				map->heat[i][j] = 0;
			j++;
		}
		i++;
	}
	free_map(data, valeur);
}

void	piece_num(t_valeur *valeur, t_data *data, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	map->piece = (int**)malloc(sizeof(int*) * valeur->xp);
	while (i < valeur->xp)
	{
		j = 0;
		map->piece[i] = (int*)malloc(sizeof(int) * valeur->yp);
		while (j < valeur->yp)
		{
			if (data->piece[i][j] == '*')
				map->piece[i][j] = -1;
			else
				map->piece[i][j] = 0;
			j++;
		}
		i++;
	}
	free_piece(data, valeur);
}
