#include "../includes/filler.h"

void			init_env(t_env *e)
{
	e->num_player = 0;
	e->map_xy.map = NULL;
	e->map_xy.x = 0;
	e->map_xy.y = 0;
	e->piece_xy.map = NULL;
	e->piece_xy.x = 0;
	e->piece_xy.y = 0;
	e->solve_xy.map = NULL;
	e->solve_xy.x = 0;
	e->solve_xy.y = 0;
}