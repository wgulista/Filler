#include "../includes/filler.h"

void		free_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
}

int			length_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

void		print_tab(char **tab)
{
	int 	i;

	i = 0;
	while (tab[i])
	{
		ft_putnbr_fd(i, 2);
		ft_putchar_fd(' ', 2);
		ft_putendl_fd(tab[i], 2);
		++i;
	}
}