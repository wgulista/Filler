#include "../includes/filler.h"

void		get_piece(t_env *e, char **parse)
{
	e->piece.x = ft_atoi(parse[2]);
	e->piece.y = ft_atoi(parse[1]);
	free_tab(parse);
}

void		get_piece_map(t_env *e, char *line)
{
	int		i;

	i = -1;
	e->piece.map = (char **)malloc(sizeof(char *) * (e->piece.y + 1));
	while (++i < e->piece.y)
	{
		get_next_line(0, &line);
		e->piece.map[i] = ft_strdup(line);
		e->piece.map[i] = ft_strjoin(e->piece.map[i], "\n");
	}
}