#include "../includes/filler.h"

static int     is_overlay(t_env *e, char c, int *overlay, t_point p)
{
  if (p.x < 0 || p.y < 0 || p.y >= e->map_coord.y || p.x >= e->map_coord.x ||
		(c != '.' && e->map[p.y][p.x] != c && e->map[p.y][p.x] != c + 32))
    return (0);
  else if (e->player == c || e->player == c + 32)
    (*overlay)++;
  return (*overlay > 1 ? 0 : 1);
}

static int	is_better_place(t_env *e, t_point m)
{
	t_point		p;
	t_point		tmp;
	int				overlay;

	p.y = -1;
	overlay = 0;
	while (++p.y < e->piece_coord.y)
	{
		p.x = -1;
		while (++p.x < e->piece_coord.x)
		{
			if (e->piece[p.y][p.x] == '*')
			{
				tmp = set_point(p.x + m.x, p.y + m.y);
				if (!is_overlay(e, e->map[tmp.y][tmp.x], &overlay, tmp) ||
            tmp.x >= e->map_coord.x || tmp.y >= e->map_coord.y)
					return (0);
			}
		}
	}
	return ((overlay == 1 ? 1 : 0));
}

int					play_the_filler(t_env *e)
{
	t_point		p;

	p.y = -1;
	while (++p.y < e->map_coord.y)
	{
		p.x = -1;
		while (++p.x < e->map_coord.x)
		{
			if (is_better_place(e, p))
			{
        e->solver.x = p.x;
				e->solver.y = p.y;
        return (1);
			}
		}
	}
  return (0);
}
