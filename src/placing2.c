/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:50:45 by ktbatou           #+#    #+#             */
/*   Updated: 2020/11/26 23:34:24 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		placing_piece(t_map *map, t_valeur *valeur)
{
	int		x;
	int		y;
	int		score;
	int		temp;
	int		flag;
	
	x = 0;
	y = 0;
	score = 0;
	valeur->i = 0;
	temp = 0;
	flag = 0;
	while (valeur->i < valeur->y)
	{
		valeur->j = 0;
		while (valeur->j < valeur->x)
		{
			if (map->heat[valeur->i][valeur->j] == -1)
			{
				score = position(map, valeur);
				if ((score < temp && score != 0) || (flag == 0 && score != 0))
				{
					flag = 1;
					temp = score;
					x = valeur->i - map->x;
					y = valeur->j - map->y;
				}
			}
			valeur->j++;
		}
		valeur->i++;
	}
	dprintf(1, "%d %d\n", x, y);
}

int		position(t_map *map, t_valeur *valeur)
{
	int	i;
	int	j;
	int	score;
	int	temp;
	int flag;

	i = 0;
	score = 0;
	temp = 0;
	flag = 0;
	while (i < valeur->xp)
	{
		j = 0;
		while(j < valeur->yp)
		{
			if(map->piece[i][j] == -1)
			{
				if (it_fits(i, j, map, valeur) == 1)
				{
					score = get_score(i, j, map, valeur);
					if (score < temp || flag == 0)
					{
						flag = 1;
						temp = score;
						map->x = i;
						map->y = j;		
					}
				}	
			}
			j++;
		}
		i++;
	}
	return (score);
}

int     it_fits(int x, int y,t_map *map, t_valeur *valeur)
{
	int     i;
	int     j;
	int     flag;

	i = 0;
	flag = 0;
	while(i < valeur->xp)
	{
		j = 0;
		while (j < valeur->yp)
		{
			if (map->piece[i][j] == -1)
			{	
				if (valeur->i + (i - x) > (valeur->y - 1) || 
					valeur->j + (j - y) > (valeur->x - 1) || (valeur->j + (j - y) < 0) || valeur->i + (i - x) < 0)
					return (0);
				if (map->heat[valeur->i + (i - x)][valeur->j + (j - y)] == -1)
					flag++;
				if (map->heat[valeur->i + (i - x)][valeur->j + (j - y)] == -2)
					return (0);
				if (flag > 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		get_score(int x, int y,t_map *map, t_valeur *valeur)
{
	int	i;
	int	j;
	int	score;

	i = 0;
	score = 0;
	while(i < valeur->xp)
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