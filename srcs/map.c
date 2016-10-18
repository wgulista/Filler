#include "../includes/filler.h"

void				get_coord_map(t_env *e)
{
	char		*line;
	char		**parse;

	parse = NULL;
	if (get_next_line(0, &line) > 0)
	{
		parse = ft_strsplit(line, ' ');
		free(line);
	}
	e->map_coord.y = ft_atoi(parse[1]);
	e->map_coord.x = ft_atoi(parse[2]);
	free_tab(parse);
}

void			get_map(t_env *e)
{
	t_point	pts;
	char		*line;

	pts.y = -1;
	get_next_line(0, &line);
	free(line);
	e->map = (char **)malloc(sizeof(char *) * (e->map_coord.y + 1));
	while (++pts.y < e->map_coord.y)
	{
		e->map[pts.y] = (char *)malloc(sizeof(char) * (e->map_coord.x + 1));
		if (get_next_line(0, &line) > 0)
		{
			pts.x = -1;
			while (++pts.x < e->map_coord.x)
				e->map[pts.y][pts.x] = line[pts.x + 4];
			e->map[pts.y][pts.x] = '\0';
			free(line);
		}
	}
	e->map[pts.y] = NULL;
}
