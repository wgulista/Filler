#include "../includes/filler.h"

t_point			get_pos_player(t_env *e, char c)
{
	t_point		p;
	t_point		ret;

	p.y = -1;
	while (++p.y < e->map_coord.y && (p.x = -1))
	{
		while (++p.x < e->map_coord.x)
		{
			if (e->map[p.y][p.x] == c)
			{
				ret.x = p.x;
				ret.y = p.y;
				return (ret);
			}
		}
	}
	return (set_point(0, 0));
}

t_piece			*min_dist(t_piece *pieces)
{
	t_piece		*ret;

	ret = pieces;
	pieces = pieces->next;
	while (pieces)
	{
		if (ret->dist > pieces->dist)
			ret = pieces;
		pieces = pieces->next;
	}
	return (ret);
}

int				flood_fill(t_env *e, t_piece *pieces)
{
	int			swap;
	t_point		ennemy;
	t_point		p;

	if (!pieces)
		return (1);
	p.y = -1;
	ennemy = get_pos_player(e, e->ennemy);
	pieces->dist = ft_sqrt(ennemy.x - pieces->pts.x) + ft_sqrt(ennemy.y - pieces->pts.y);
	while (++p.y < e->piece_coord.y && (p.x = -1))
	{
		while (++p.x < e->piece_coord.x)
		{
			swap = ft_sqrt(ennemy.x - (pieces->pts.x + p.x)) + ft_sqrt(ennemy.y - (pieces->pts.y + p.y));
			if (e->piece[p.y][p.x] == '*' && swap < pieces->dist)
				pieces->dist = swap;
		}
	}
	return (flood_fill(e, pieces->next));
}

int				filler(t_env *e, t_piece *pieces)
{
	t_piece		*ret;

	flood_fill(e, pieces);
	ret = min_dist(pieces);
	e->solver = set_point(ret->pts.x, ret->pts.y);
	return (1);
}
