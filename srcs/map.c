#include "../includes/filler.h"

void			get_coord_map(t_env *e, char **parse)
{
	e->map.x = ft_atoi(parse[2]);
	e->map.y = ft_atoi(parse[1]);
	free_tab(parse);
}

void			get_map(t_env *e, char *line)
{
	int			i;

	i = -1;
	get_next_line(0, &line);
	e->map.map = (char **)malloc(sizeof(char *) * (e->map.y + 1));
	while (++i < e->map.y)
	{
		get_next_line(0, &line);
		line += 4;
		e->map.map[i] = ft_strdup(line);
		e->map.map[i] = ft_strjoin(e->map.map[i], "\n");
	}
}
