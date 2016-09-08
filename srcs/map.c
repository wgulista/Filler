#include "../includes/filler.h"

int			find_map(char *line, t_env *e)
{
	char	**map;

	map = NULL;
	if (ft_strstr(line, "Plateau") != NULL)
	{
		map = ft_strsplit(line, ' ');
		e->map_xy.x = ft_atoi(map[1]);
		e->map_xy.x = ft_atoi(map[2]);
		free_tab(map);
		return (1);
	}
	return (0);
}