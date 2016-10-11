#include "../includes/filler.h"

int			pos_piece(int i, int j, t_env *e)
{
	int		k; //i
	int		l; //j
	int		overlay;

	k = -1;
	overlay = 0;
	(void)i;
	(void)j;
	while (++k < e->piece.y)
	{
		l = -1;
		while (++l < e->piece.x)
		{
			if (e->piece.map[k][l] == '*')
			{
				overlay = 1;
			}
		}
	}
	if (overlay == 1)
		return (1);
	return (0);
}

int			recur_solver(t_env *e, t_point *pos)
{
	int		x;
	int		y;


	if (!pos)
		return (1);
	y = -1;
	while (++y < e->piece.y)
	{
		x = -1;
		while (++x < e->piece.x)
		{
			if (e->piece.map[y][x] == '*')
			{
				//if (e->map.map[][] == )
			}
		}
	}
	return (recur_solver(e, pos->next));
}

int			solve_filler(t_env *e)
{
	int			i; //y
	int			j; //x
	t_point		*pos;

	i = -1;
	pos = NULL;
	while (++i < e->map.y)
	{
		j = -1;
		while (++j < e->map.x)
		{
			if (pos_piece(i, j, e))
				add_to_list(&pos, i, j);
		}
	}
	if (pos)
		recur_solver(e, pos);
	return (0);
}
