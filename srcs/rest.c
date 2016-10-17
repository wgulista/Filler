#include "../includes/filler.h"

void  delete(t_env *e)
{
  e->map_coord = set_point(0, 0);
  free_tab(e->map);
  e->piece_coord = set_point(0, 0);
  free_tab(e->piece);
}
