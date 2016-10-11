#include "../includes/filler.h"

int		parse(t_env *e, char **line, char **av)
{
	char	**parse;
	char	player;
	char	opponent;

	ft_put
	get_next_line(0, line);
	parse = ft_strsplit(*line, ' ');
	if (get_error(av, parse) == 1)
		free_tab(parse);
	if (e->num_player == 0)
		get_num_player(e, parse);
	get_coord_map(e, line);
	get_map(e, line);
	player = (e->num_player == 1) ? 'o' : 'x';
	opponent = (e->num_player == 1) ? 'x' : 'o';
	search_player_pos(player, e);
	search_opponent_pos(opponent, e);
	get_piece(e, line);
	get_piece_map(e, line);
	return (1);
}

void		print_coord(t_env *e)
{
	ft_putstr_fd(ft_itoa(e->solver.y), 1);
	ft_putchar_fd(' ', 1);
	ft_putendl_fd(ft_itoa(e->solver.x), 1);
}

int			main(int ac, char **av)
{
	t_env 	*e;
	char	*line;

	(void)ac;
	init_env(&e);
	while (get_next_line(0, &line))
		if (ft_strlen(line) > 0)
		{
			parse(e, &line, av);
			solve_filler(e);
			print_coord(e);
		}
	debug(e);
	free_env(&e);
	return (0);
}
