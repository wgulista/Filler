#include "../includes/filler.h"

int			get_error(char **av, char **parse)
{
	if (!ft_strequ(parse[0], "$$$") && !ft_strequ(parse[1], "exec") && 
		!ft_strequ(parse[4], av[0]))
		return (1);
	return (0);
}