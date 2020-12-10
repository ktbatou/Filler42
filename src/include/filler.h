/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 03:19:03 by ktbatou           #+#    #+#             */
/*   Updated: 2020/12/10 23:24:29 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>

typedef	struct	s_data
{
	char	player;
	char	**map;
	char	**piece;
}				t_data;

typedef	struct	s_valeur
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		xp;
	int		yp;
	int		flag;
	int		index;
	int		index1;
	int		temp;
	int		tempy;
	int		tokenx;
	int		tokeny;
}				t_valeur;

typedef	struct	s_map
{
	int		**heat;
	int		**piece;
	int		temp;
	int		heater;
	int		x;
	int		y;
	int		tempx;
	int		tempy;
	int		flag;
	int		flag1;
}				t_map;

int				player(t_data *data);
int				map_size(t_valeur *valeur, t_data *data);
int				get_map(t_data *data, t_valeur *valeur);
void			initial(t_data *data, t_valeur *valeur, t_map *map);
int				piece_size(t_valeur *valeur);
int				piece(t_data *data, t_valeur *valeur);
void			map_num(t_valeur *valeur, t_data *data, t_map *map);
void			piece_num(t_valeur *valeur, t_data *data, t_map *map);
void			heating(t_map *map, int i, int j, t_valeur *valeur);
void			heat_map(t_valeur *valeur, t_map *map);
void			free_temp(char **temp);
void			free_map(t_data *data, t_valeur *valeur);
void			free_piece(t_data *data, t_valeur *valeur);
void			free_heat(t_map *map, t_valeur *valeur);
void			placing_piece(t_map *map, t_valeur *valeur);
int				position(t_map *map, t_valeur *valeur);
int				it_fits(int x, int y, t_map *map, t_valeur *valeur);
int				get_score(int x, int y, t_map *map, t_valeur *valeur);
void			initial_valeur(t_valeur *valeur);
void			print_cords(t_valeur *v);
void			cords(t_map *map, t_valeur *valeur);
int				score1(int i, int j, t_map *map, t_valeur *valeur);
int				checker(int i, int j, t_map *map, t_valeur *valeur);

#endif
