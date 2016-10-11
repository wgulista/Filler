#include "../includes/filler.h"

void			get_coord_map(t_env *e, char **line)
{
	char		**parse;

	get_next_line(0, line);
	parse = ft_strsplit(*line, ' ');
	e->map.y = ft_atoi(parse[1]);
	e->map.x = ft_atoi(parse[2]);
	free_tab(parse);
}

void			get_map(t_env *e, char **line)
{
	int			i;

	i = -1;
	get_next_line(0, line);
	e->map.map = (char **)malloc(sizeof(char *) * (e->map.y + 1));
	i = -1;
	while (++i < e->map.y)
	{
		get_next_line(0, line);
		*line += 4;
		e->map.map[i] = ft_strdup(*line);
		e->map.map[i] = ft_strjoin(e->map.map[i], "\n");
	}
}
