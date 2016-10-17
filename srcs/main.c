#include "../includes/filler.h"
#include <stdio.h>

t_point		set_point(int x, int y)
{
	t_point	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

static int  parse_data(t_env *e)
{
	get_coord_map(e);
  get_map(e);
  get_coord_piece(e);
  get_piece_map(e);
  return (1);
}

static void		print_coord(t_env *e)
{
	if (e->solver.y == -100 && e->solver.x == -100)
		ft_putendl_fd("0 0", 1);
	else
	{
		ft_putstr_fd(ft_itoa(e->solver.y), 1);
		ft_putchar_fd(' ', 1);
		ft_putendl_fd(ft_itoa(e->solver.x), 1);
	}
}

int         main(void)
{
	char			*line;
  t_env     e;

  e.map_coord = set_point(0, 0);
	if (get_next_line(0, &line) > 0)
	{
		e.player = (line[10] == '1' ? 'O' : 'X');
		e.ennemy = (line[10] == '1' ? 'X' : 'O');
		free(line);
	}
  while (parse_data(&e))
  {
	  play_the_filler(&e);
		print_coord(&e);
  }
	delete(&e);
	ft_putendl_fd("0 0", 1);
  return (0);
}
