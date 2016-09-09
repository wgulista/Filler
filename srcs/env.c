#include "../includes/filler.h"


void		free_env(t_env *e)
{
	free_tab(e->map.map);
	free_tab(e->piece.map);
	free(e);
}

t_env		*init_env()
{
	t_env 	*ret;

	ret = (t_env *)malloc(sizeof(ret));
	ret->num_player = 0;
	ret->map.map = NULL;
	ret->map.x = 0;
	ret->map.y = 0;
	ret->piece.map = NULL;
	ret->piece.x = 0;
	ret->piece.y = 0;
	ret->player.map = NULL;
	ret->player.x = 0;
	ret->player.y = 0;
	ret->opponent.map = NULL;
	ret->opponent.x = 0;
	ret->opponent.y = 0;
	ret->solver.map = NULL;
	ret->solver.x = 0;
	ret->solver.y = 0;
	return (ret);
}