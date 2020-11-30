/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:55:48 by ktbatou           #+#    #+#             */
/*   Updated: 2020/11/30 18:16:48 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	initial(t_data *data, t_valeur *valeur, t_map *map)
{
	if (data != NULL)
	{
		data->player = 0;
		data->map = 0;
		data->piece = 0;
	}
	if (valeur != NULL)
	{
		valeur->x = 0;
		valeur->y = 0;
		valeur->xp = 0;
		valeur->yp = 0;
		valeur->flag = 0;
		valeur->index = 0;
		valeur->index1 = 0;
		valeur->i = 0;
		valeur->j = 0;
		valeur->tokenx = 0;
		valeur->tokeny = 0;
	}
	if (map != NULL)
	{
		map->heat = 0;
		map->heater = 0;
		map->temp = 0;
		map->piece = 0;
		map->x = 0;
		map->y = 0;
	}
}
