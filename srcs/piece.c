#include "../includes/filler.h"

void			get_coord_piece(t_env *e)
{
	char		*line;
	char		**parse;

	parse = NULL;
	if (get_next_line(0, &line) > 0)
	{
		parse = ft_strsplit(line, ' ');
		free(line);
	}
	e->piece_coord.y = ft_atoi(parse[1]);
	e->piece_coord.x = ft_atoi(parse[2]);
	free_tab(parse);
}

void			get_piece_map(t_env *e)
{
	t_point	pts;
	char		*line;

	pts.y = -1;
	e->piece = (char **)malloc(sizeof(char *) * (e->piece_coord.y + 1));
	while (++pts.y < e->piece_coord.y)
	{
		e->piece[pts.y] = (char *)malloc(sizeof(char) * (e->piece_coord.x + 1));
		if (get_next_line(0, &line) > 0)
		{
			pts.x = -1;
			while (++pts.x < e->piece_coord.x)
				e->piece[pts.y][pts.x] = line[pts.x];
			e->piece[pts.y][pts.x] = '\0';
			free(line);
		}
	}
	e->piece[pts.y] = NULL;
}
