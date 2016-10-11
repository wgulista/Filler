#include "../includes/filler.h"

void		free_env(t_env **e)
{
	t_env	*tmp;

	tmp = *e;
	tmp->map.x = 0;
	tmp->map.y = 0;
	free(tmp->map.map);
	tmp->piece.x = 0;
	tmp->piece.y = 0;
	free(tmp->piece.map);
	tmp->solver.x = 0;
	tmp->solver.y = 0;
	tmp->player.x = 0;
	tmp->player.y = 0;
	tmp->opponent.x = 0;
	tmp->opponent.y = 0;
	free(tmp);
}

void		init_env(t_env **e)
{
	t_env 	*tmp;

	tmp = (t_env *)malloc(sizeof(t_env));
	tmp->num_player = 0;
	tmp->map.map = NULL;
	tmp->map.x = 0;
	tmp->map.y = 0;
	tmp->piece.map = NULL;
	tmp->piece.x = 0;
	tmp->piece.y = 0;
	tmp->player.map = NULL;
	tmp->player.x = 0;
	tmp->player.y = 0;
	tmp->opponent.map = NULL;
	tmp->opponent.x = 0;
	tmp->opponent.y = 0;
	tmp->solver.map = NULL;
	tmp->solver.x = 0;
	tmp->solver.y = 0;
	*e = tmp;
	free(tmp);
}
