#include "../includes/filler.h"

int			pos_piece(int i, int j, t_env *e)
{
	(void)j;
	(void)i;
	e->solver.x = e->player.x;
	e->solver.y = e->player.y;
	return (1);
}

int			solve_filler(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < e->map.y)
	{
		j = -1;
		while (++j < e->map.x)
		{
			if (i == e->player.y && j == e->player.x)
			{
				if (pos_piece(i, j, e))
					return (1);
			}
		}
	}
	return (0);
}
