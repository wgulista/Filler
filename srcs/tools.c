#include "../includes/filler.h"

void		free_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
}