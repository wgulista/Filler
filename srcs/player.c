#include "../includes/filler.h"

void		get_num_player(t_env *e, char **parse)
{
	if (ft_strequ(parse[2], "p1"))
		e->num_player = 1;
	else
		e->num_player = 2;
}

void		search_player_pos(char c, t_env *e)
{
	int		x;
	int		y;

	y = -1;
	while (++y < e->map.y)
	{
		x = -1;
		while (++x < e->map.x)
		{
			if (e->map.map[y][x] == ft_toupper(c))
			{
				e->player.x = x;
				e->player.y = y;
			}
		}
	}
}

void		search_opponent_pos(char c, t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < e->map.y)
	{
		j = -1;
		while (++j < e->map.x)
		{
			if (e->map.map[i][j] == ft_toupper(c))
			{
				e->opponent.x = j;
				e->opponent.y = i;
			}
		}
	}
}
