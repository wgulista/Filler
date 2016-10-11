#include "../includes/filler.h"

int		parse(t_env *e, char **av)
{
	char	*line;
	char	**parse;

	get_next_line(0, &line);
	parse = ft_strsplit(line, ' ');
	if (get_error(av, parse) == 1)
		free_tab(parse);
	if (e->num_player == 0)
		get_num_player(e, parse);
	get_coord_map(e, &line);
	get_map(e, &line);
	e->player.c = (e->num_player == 1) ? 'o' : 'x';
	e->opponent.c = (e->num_player == 1) ? 'x' : 'o';
	search_player_pos(e->player.c, e);
	search_opponent_pos(e->opponent.c, e);
	get_piece(e, &line);
	get_piece_map(e, &line);
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

	(void)ac;
	init_env(&e);
	if (parse(e, av))
	{
		solve_filler(e);
		print_coord(e);
		free_env(&e);
	}
	else
		ft_putstr_fd("0 0\n", 1);
	return (0);
}
