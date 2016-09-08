#include "../includes/filler.h"

int			find_player(char *line, t_env *e, char **av)
{
	char	**player;

	player = ft_strsplit(line, ' ');
	if (!ft_strequ(player[0], "$$$") || ft_strequ(player[1], "exec") ||
		!ft_strequ(player[4], av[0]))
	{
		free_tab(player);
		return (0);
	}
	if (ft_strequ(player[2], "p1"))
	{
		e->num_player = 1;
		free_tab(player);
		return (1);
	}
	if (ft_strequ(player[2], "p2"))
	{
		e->num_player = 2;
		free_tab(player);
		return (1);
	}
	free_tab(player);
	return (0);
}