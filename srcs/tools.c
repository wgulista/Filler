#include "../includes/filler.h"

void			free_tab(char **tab)
{
	int			i;

	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
}

void			print_tab(char **tab)
{
	int 		i;

	i = 0;
	while (tab[i])
	{
		ft_putnbr_fd(i, 2);
		ft_putchar_fd(' ', 2);
		ft_putendl_fd(tab[i], 2);
		++i;
	}
}

int				hypothenus(t_point a, t_point b)
{
	int			dist;

	dist = ABS(a.x - b.x) + ABS(a.y - b.y);
	return (dist);
}

void 			print_color_map(t_env *e)
{
	t_point	p;

	p.y = -1;
	ft_putstr_fd("\n\n", 2);
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
