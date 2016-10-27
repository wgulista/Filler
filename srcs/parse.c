/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:38:13 by wgulista          #+#    #+#             */
/*   Updated: 2016/10/21 03:12:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				get_map_size(t_env *e)
{
	char		*keep;
	char		*line;

	if (!get_next_line(0, &line))
		return (0);
	if (ft_strstr(line, "Plateau"))
	{
		keep = ft_strchr(line, ' ');
		e->map_coord.y = ft_atoi(++keep);
		keep = ft_strchr(line, ' ');
		e->map_coord.x = ft_atoi(++keep);
		free(line);
		return (1);
	}
	return (0);
}

int				get_map(t_env *e)
{
	t_point		pts;
	char		*line;

	pts.y = -1;
	if (!get_next_line(0, &line))
		return (0);
	free(line);
	e->map = (char **)ft_strnew(sizeof(char *) * (e->map_coord.y + 1));
	while (++pts.y < e->map_coord.y && (pts.x = -1))
	{
		e->map[pts.y] = (char *)ft_strnew(sizeof(char) * (e->map_coord.x + 1));
		if (get_next_line(0, &line) > 0)
		{
			while (++pts.x < e->map_coord.x)
				e->map[pts.y][pts.x] = line[pts.x + 4];
			e->map[pts.y][pts.x] = '\0';
			free(line);
		}
	}
	e->map[pts.y] = NULL;
	return (1);
}

int				get_piece_size(t_env *e)
{
	char		*keep;
	char		*line;

	if (!get_next_line(0, &line))
		return (0);
	if (ft_strstr(line, "Piece"))
	{
		keep = ft_strchr(line, ' ');
		e->piece_coord.y = ft_atoi(++keep);
		keep = ft_strchr(line, ' ');
		e->piece_coord.x = ft_atoi(++keep);
		free(line);
	}
	return (0);
}

int				get_piece(t_env *e)
{
	t_point		pts;
	char		*line;

	pts.y = -1;
	e->piece = (char **)malloc(sizeof(char *) * (e->piece_coord.y + 1));
	while (++pts.y < e->piece_coord.y && (pts.x = -1))
	{
		e->piece[pts.y] = (char *)malloc(sizeof(char) * (e->piece_coord.x + 1));
		if (get_next_line(0, &line) > 0)
		{
			while (++pts.x < e->piece_coord.x)
				e->piece[pts.y][pts.x] = line[pts.x];
			e->piece[pts.y][pts.x] = '\0';
			free(line);
		}
	}
	e->piece[pts.y] = NULL;
	return (1);
}

int				parse_data(t_env *e)
{
	get_map_size(e);
	get_map(e);
	get_piece_size(e);
	get_piece(e);
	if (play_the_filler(e))
		return (1);
	return (0);
}
