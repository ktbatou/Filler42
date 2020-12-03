/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:55:43 by ktbatou           #+#    #+#             */
/*   Updated: 2020/12/03 03:55:53 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_structures(t_map *map, t_data *data, t_valeur *valeur)
{
	if (map)
		free(map);
	if (data)
		free(data);
	if (valeur)
		free(valeur);
}

int		main(void)
{
	t_data		*data;
	t_valeur	*valeur;
	t_map		*map;

	data = (t_data*)malloc(sizeof(t_data));
	valeur = (t_valeur*)malloc(sizeof(t_valeur));
	map = (t_map*)malloc(sizeof(t_map));
	initial(data, valeur, map);
	if (player(data) != 1 || map_size(valeur, data) != 1)
		perror("Error.");
	while (1)
	{
		if (get_map(data, valeur) == 0 || piece(data, valeur) == 0)
		{
			write(1, "0 0\n", 4);
			break ;
		}
		map_num(valeur, data, map);
		piece_num(valeur, data, map);
		heat_map(valeur, map);
		placing_piece(map, valeur);
	}
	free_structures(map, data, valeur);
	return (0);
}
