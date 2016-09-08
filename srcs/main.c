#include "../includes/filler.h"

int 		start(t_env *e)
{
	char 	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strlen(line) > 0)
		{
			if (!find_player(line, &e))
				free(line);
			else if (!find_map(line, &e))
				free(line);
			else if (!find_piece(line, &e))
				free(line);
			else
			{
				free(line);
				return (1);
			}
		}
	}
	return (0);
}

void		print_coord(t_env *e)
{
	ft_putstr(ft_itoa(e->solve_x));
	ft_putchar(' ');
	ft_putendl(ft_itoa(e->solve_y));
}

int			main()
{
	t_env 	e;
	char	*line;

	if (start(e))
	{
		if (solve_filler(e))
			print_coord(&e);
		else
			ft_putendl("0 0");
	}
	ft_putendl("0 0");
	return (0);
}