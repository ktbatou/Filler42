/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:55:43 by ktbatou           #+#    #+#             */
/*   Updated: 2020/11/26 22:48:57 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				main(void)
{
	t_data		*data;
	t_valeur	*valeur;
	t_map		*map;
	int  i;

	data = (t_data*)malloc(sizeof(t_data));
	valeur = (t_valeur*)malloc(sizeof(t_valeur));
	map = (t_map*)malloc(sizeof(t_map));
	initial(data, valeur, map);
	if (player(data) != 0 || map_size(valeur, data) != 0)
		perror("Error.");
	i = 1;
   while (i)
   {
	   	get_map(data, valeur);
	   	piece(data, valeur);
	  	map_num(valeur, data, map);
		piece_num(valeur, data, map);
		heat_map(valeur, map);
		placing_piece(map, valeur);
	}
	free(map);
	free(data);
	free(valeur);
   	return (0);
}
