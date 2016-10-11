#include "../includes/filler.h"

void			get_piece(t_env *e, char **line)
{
	char		**parse;

	get_next_line(0, line);
	parse = ft_strsplit(*line, ' ');
	e->piece.y = ft_atoi(parse[1]);
	e->piece.x = ft_atoi(parse[2]);
	free_tab(parse);
}

void			get_piece_map(t_env *e, char **line)
{
	int			i;

	i = -1;
	e->piece.map = (char **)malloc(sizeof(char *) * (e->piece.y + 1));
	i = -1;
	while (++i < e->piece.y)
	{
		get_next_line(0, line);
		e->piece.map[i] = ft_strdup(*line);
		e->piece.map[i] = ft_strjoin(e->piece.map[i], "\n");
	}
}
