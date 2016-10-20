#include "../includes/filler.h"

int				check_piece(t_env *e, t_point m)
{
	int			overlap;
	t_point		p;
	t_point		tmp;

	overlap = 0;
	p.y = -1;
	while (++p.y < e->piece_coord.y && (p.x = -1))
	{
		while (++p.x < e->piece_coord.x)
		{
			if (e->piece[p.y][p.x] == '*')
			{
				tmp = set_point(p.x + m.x, p.y + m.y);
				if (limit_cross_map(e, tmp.x, tmp.y) || is_ennemy(e, e->map[tmp.y][tmp.x]))
					return (0);
				else if (is_player(e, e->map[tmp.y][tmp.x]))
					if (++overlap > 1)
						return (0);
			}
		}
	}
	if (overlap == 1)
		return (1);
	return (0);
}

int				play_the_filler(t_env *e)
{
	t_point		p;
	t_piece		*pieces;

	p.y = -1;
	pieces = NULL;
	while (++p.y < e->map_coord.y && (p.x = -1))
	{
		while (++p.x < e->map_coord.x)
		{
			if (check_piece(e, p))
				add_to_list(&pieces, set_piece(p.x, p.y));
		}
	}
	if (pieces)
		return (filler(e, pieces));
	e->solver = set_point(0, 0);
	return (0);
}