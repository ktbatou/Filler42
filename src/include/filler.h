#ifndef FILLER_H
# define FILLER_H

#include "get_next_line.h"
#include <stdio.h>
#include <errno.h>

#define J_BORDER (j >= 0 && j < 16)
#define J_ABSO (j > 0 && j <= 16)
#define I_BORDER (i >= 0 && i < 14)
#define I_ABSO (i > 0 && i <= 14)

typedef	struct s_error
{
	/* data */
}				t_error;

typedef struct s_data
{
	char    player;
	char	**map;
	char	**piece;
}              t_data;

typedef  struct s_valeur
{
	int		i;
	int		j;
	int     x;
	int     y;
	int		xp;
	int		yp;
	int		flag;
	int		index;
	int		index1;
	int		tempx;
	int		tempy;
	int		tokenx;
	int		tokeny;
}              t_valeur;

typedef		struct s_map
{
	int		**heat;
	int		**piece;
	int		temp;
	int		heater;
	int		x;
	int		y;
}					t_map;

int		player(t_data *data);
int		map_size(t_valeur *valeur, t_data *data);
int		get_map(t_data *data, t_valeur *valeur);
void	struct_alloc(t_data *data, t_valeur *valeur);
void	initial(t_data *data, t_valeur *valeur, t_map *map);
int		piece_size(t_valeur *valeur);
int		piece(t_data *data, t_valeur *valeur);
int		ft_getline(int fd, char **line);
void	map_num(t_valeur *valeur, t_data *data, t_map *map);
void	piece_num(t_valeur *valeur, t_data *data, t_map *map);
void	heating(t_map *map, int i, int j);
void	heat_map(t_valeur *valeur, t_map *map);
void	place_piece(t_valeur *valeur, t_map *map);
void    free_temp(char **temp);
void    free_map(t_data *data, t_valeur *valeur);
void    free_piece(t_data *data, t_valeur *valeur);
void    free_heat(t_map *map, t_valeur *valeur);
int		count_score(t_map *map, t_valeur *valeur, int x, int y);
int		piece_testing(t_map *map, t_valeur *valeur, int x, int y);
int     it_fits1(t_map *map, t_valeur *valeur, int x, int y);
int		score_counting(t_map *map, t_valeur *valeur, int x, int y);
void    placing_piece(t_map *map, t_valeur *valeur);
int		position(t_map *map, t_valeur *valeur);
int     it_fits(int x, int y,t_map *map, t_valeur *valeur);
int		get_score(int x, int y,t_map *map, t_valeur *valeur);
#endif