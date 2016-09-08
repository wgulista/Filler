#include "../includes/filler.h"

int 		start(t_env *e, char **av)
{
	char 	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!find_player(line, e, av) || !find_map(line, e) || !find_piece(line, e))
			free(line);
		else
		{
			free(line);
			return (1);
		}
	}
	return (0);
}

void		debug(t_env *e)
{
	ft_putnbr_fd(e->num_player, 2);
	ft_putendl_fd("", 2);

	ft_putnbr_fd(e->map_xy.x, 2);
	ft_putendl_fd("", 2);

	ft_putnbr_fd(e->map_xy.y, 2);
	ft_putendl_fd("", 2);

	ft_putnbr_fd(e->piece_xy.x, 2);
	ft_putendl_fd("", 2);

	ft_putnbr_fd(e->piece_xy.y, 2);
	ft_putendl_fd("", 2);

	ft_putnbr_fd(e->solve_xy.x, 2);
	ft_putendl_fd("", 2);

	ft_putnbr_fd(e->solve_xy.y, 2);
	ft_putendl_fd("", 2);
}

void		print_coord(t_env *e)
{
	ft_putstr(ft_itoa(e->solve_xy.x));
	ft_putchar(' ');
	ft_putendl(ft_itoa(e->solve_xy.y));
}

int			main(int ac, char **av)
{
	t_env 	e;

	(void)ac;
	if (start(&e, av))
	{
		debug(&e);
		if (solve_filler(&e))
			print_coord(&e);
		else
			ft_putendl_fd("0 0", 2);
	}
	return (0);
}