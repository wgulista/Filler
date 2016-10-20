#include "../includes/filler.h"

int			delete_env(t_env *e)
{
	e->map_coord = set_point(0, 0);
	e->piece_coord = set_point(0, 0);
	return (1);
}

void			free_tab(char **tab)
{
	int			i;

	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
}

t_point			set_point(int x, int y)
{
	t_point		pts;

	pts.x = x;
	pts.y = y;
	return (pts);
}

void 			print_color_map(t_env *e)
{
	t_point		p;

	p.y = -1;
	ft_putstr_fd("\n", 2);
	while (++p.y < e->map_coord.y)
	{
		p.x = -1;
		while (++p.x < e->map_coord.x)
		{
			if (e->map[p.y][p.x] == 'O' || e->map[p.y][p.x] == 'o')
				ft_putstr_fd("\x1B[32mO\x1B[0m", 2);
			else if (e->map[p.y][p.x] == 'X' || e->map[p.y][p.x] == 'x')
				ft_putstr_fd("\x1B[35mX\x1B[0m", 2);
			else
				ft_putstr_fd("\x1B[37m.\x1B[0m", 2);
		}
		ft_putchar_fd('\n', 2);
	}
	ft_putchar_fd('\n', 2);
}