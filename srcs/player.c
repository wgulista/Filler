#include "../includes/filler.h"

void		get_num_player(t_env *e, char **parse)
{
	if (ft_strequ(parse[2], "p1"))
		e->num_player = 1;
	else
		e->num_player = 2;
	free_tab(parse);
}

void		search_player_pos(char c, t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < e->map.y)
	{
		j = -1;
		while (++j < e->map.x)
		{
			if (e->map.map[i][j] == c)
			{
				e->player.x = j;
				e->player.y = i;
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
			if (e->map.map[i][j] == c)
			{
				e->opponent.x = j;
				e->opponent.y = i;
			}
		}
	}
}