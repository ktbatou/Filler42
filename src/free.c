/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:23:39 by ktbatou           #+#    #+#             */
/*   Updated: 2020/12/04 02:44:27 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_temp(char **temp)
{
	int	i;

	i = 0;
	while (i < 3)
		free(temp[i++]);
	free(temp);
}

void	free_map(t_data *data, t_valeur *valeur)
{
	int i;

	i = 0;
	while (i < valeur->y)
		ft_strdel(&data->map[i++]);
	ft_strdel(data->map);
}

void	free_piece(t_data *data, t_valeur *valeur)
{
	int	i;

	i = 0;
	while (i < valeur->xp)
		free(data->piece[i++]);
	free(data->piece);
}

void	free_heat(t_map *map, t_valeur *valeur)
{
	int i;

	i = 0;
	while (i < valeur->y)
		free(map->heat[i++]);
	free(map->heat);
	i = 0;
	while (i < valeur->xp)
		free(map->piece[i++]);
	free(map->piece);
}
