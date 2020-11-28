/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detail.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 09:20:23 by ktbatou           #+#    #+#             */
/*   Updated: 2020/11/28 18:34:15 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		player(t_data *data)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) != 1)
		dprintf(1, "0 0\n");
	data->player = 'X';
	if (ft_strstr(line, "p1"))
		data->player = 'O';
	ft_strdel(&line);
	return (0);
}

int		map_size(t_valeur *valeur, t_data *data)
{
	char	*line;
	char	**temp;

	line = NULL;
	if (get_next_line(0, &line) != 1)
		dprintf(1, "0 0\n");
	if (ft_strstr(line, "Plateau"))
	{
		temp = ft_strsplit(line, ' ');
		valeur->y = ft_atoi(temp[1]);
		valeur->x = ft_atoi(temp[2]);
		free_temp(temp);
	}
	ft_strdel(&line);
	if (!(data->map = (char**)malloc(sizeof(char*) * valeur->y)))
		dprintf(1, "0 0\n");
	return (0);
}

int		get_map(t_data *data, t_valeur *valeur)
{
	char	*line;
	int		i;

	i = 0;
	if (valeur->flag == 1)
	{
		if (get_next_line(0, &line) != 1)
			dprintf(1, "0 0\n");
		ft_strdel(&line);
	}
	if (get_next_line(0, &line) != 1)
		dprintf(1, "0 0\n");
	ft_strdel(&line);
	while (i < valeur->y)
	{
		if (get_next_line(0, &line) != 1)
			dprintf(1, "0 0\n");
		data->map[i++] = ft_strdup(&line[4]);
		ft_strdel(&line);
	}
	valeur->flag = 1;
	return (0);
}

int		piece_size(t_valeur *valeur)
{
	char	**temp;
	char	*line;

	if (get_next_line(0, &line) != 1)
		dprintf(1, "0 0\n");
	if (ft_strstr(line, "Piece"))
	{
		temp = ft_strsplit(line, ' ');
		valeur->xp = ft_atoi(temp[1]);
		valeur->yp = ft_atoi(temp[2]);
		free_temp(temp);
	}
	ft_strdel(&line);
	return (0);
}

int		piece(t_data *data, t_valeur *valeur)
{
	char	*line;
	int		i;

	i = 0;
	piece_size(valeur);
	data->piece = (char**)malloc(sizeof(char*) * valeur->xp);
	while (i < valeur->xp)
	{
		if (get_next_line(0, &line) != 1)
			dprintf(1, "0 0\n");
		data->piece[i++] = ft_strdup(line);
		ft_strdel(&line);
	}
	return (0);
}
