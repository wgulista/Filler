#include "../includes/filler.h"

int			find_player(char *line, t_env *e)
{
	char	**player;

	player = ft_strsplit(line, ' ');
	if (!ft_strequ(line[0], "$$$") || !ft_strequ(line[1], "exec") || 
		!ft_strequ(line[4], "wgulista.filler"))
	{
		free_tab(player);
		return (0);
	}
	if (ft_strequ(line[2], "p1"))
	{
		e->got = 1;
		free_tab(player);
		return (1);

	}
	if (ft_strequ(line[2], "p1"))
	{
		e->got = 2;
		free_tab(player);
		return (1);
	}
	free_tab(player);
	return (0);
}