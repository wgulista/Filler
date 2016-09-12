#include "../includes/filler.h"

void		debug(t_env *e)
{
	ft_putstr_fd("Num player = ", 2);
	ft_putnbr_fd(e->num_player, 2);
	ft_putendl_fd("", 2);

	ft_putstr_fd("Map X = ", 2);
	ft_putnbr_fd(e->map.x, 2);
	ft_putendl_fd("", 2);

	ft_putstr_fd("Map Y = ", 2);
	ft_putnbr_fd(e->map.y, 2);
	ft_putendl_fd("", 2);

	ft_putstr_fd("Piece X = ", 2);
	ft_putnbr_fd(e->piece.x, 2);
	ft_putendl_fd("", 2);

	ft_putstr_fd("Piece Y = ", 2);
	ft_putnbr_fd(e->piece.y, 2);
	ft_putendl_fd("", 2);

	ft_putstr_fd("Player X = ", 2);
	ft_putnbr_fd(e->player.x, 2);
	ft_putendl_fd("", 2);

	ft_putstr_fd("Player Y = ", 2);
	ft_putnbr_fd(e->player.y, 2);
	ft_putendl_fd("", 2);

	ft_putstr_fd("Opponent X = ", 2);
	ft_putnbr_fd(e->opponent.x, 2);
	ft_putendl_fd("", 2);

	ft_putstr_fd("Opponent Y = ", 2);
	ft_putnbr_fd(e->opponent.y, 2);
	ft_putendl_fd("", 2);
}

int		parse(t_env *e, char **av)
{
	char	*line;
	char	**parse;
	char	player;
	char	opponent;

	get_next_line(0, &line);
	parse = ft_strsplit(line, ' ');
	if (get_error(av, parse) == 1)
		free_tab(parse);
	if (e->num_player == 0)
		get_num_player(e, parse);
	get_next_line(0, &line);
	parse = ft_strsplit(line, ' ');
	get_coord_map(e, parse);
	get_map(e, line);
	player = (e->num_player == 1) ? 'O' : 'X';
	opponent = (e->num_player == 1) ? 'X' : 'O';
	search_player_pos(player, e);
	search_opponent_pos(opponent, e);
	get_next_line(0, &line);
	parse = ft_strsplit(line, ' ');
	get_piece(e, parse);
	get_piece_map(e, line);
	if (line != NULL)
		free(line);
	free_tab(parse);
	return (1);
}

void		print_coord(t_env *e)
{
	ft_putstr_fd(ft_itoa(e->solver.y), 1);
	ft_putchar_fd(' ', 1);
	ft_putendl_fd(ft_itoa(e->solver.x), 1);
	free_env(e);
}

int			main(int ac, char **av)
{
	t_env 	*e;

	(void)ac;
	e = init_env();
	if (parse(e, av))
	{
		solve_filler(e);
		print_coord(e);
	}
	else
	{
		ft_putendl_fd("0 0", 1);
		free(e);
	}
	free(e);
	return (0);
}
