#include "../includes/filler.h"

int				get_map_size(t_env *e)
{
	char		*line;
	char		**size;

	if (get_next_line(0, &line) < 0)
		return (0);
	size = ft_strsplit(line, ' ');
	e->map_coord.x = ft_atoi(size[2]);
	e->map_coord.y = ft_atoi(size[1]);
	free(line);
	free_tab(size);
	return (1);
}

int				get_map(t_env *e)
{
	t_point		pts;
	char		*line;

	pts.y = -1;
	get_next_line(0, &line);
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
	char		*line;
	char		**size;

	if (get_next_line(0, &line) < 0)
		return (0);
	size = ft_strsplit(line, ' ');
	e->piece_coord.x = ft_atoi(size[2]);
	e->piece_coord.y = ft_atoi(size[1]);
	free(line);
	free_tab(size);
	return (1);
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
	{
		print_color_map(e);
		return (1);
	}
	return (0);
}