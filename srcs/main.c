#include "../includes/filler.h"

int			main()
{
	char	*line;
	t_env	e;

	init_env(&e);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$"))
		{
			ft_putstr_fd("Player 1\n", 2);
			ft_putstr_fd("$$$\n", 2);
		}
		if (ft_strstr(line, "Plateau"))
		{
			ft_putstr_fd(line, 2);
			ft_putstr_fd("\n", 2);
		}
		if (ft_strstr(line, "Piece"))
		{
			ft_putstr_fd(line, 2);
			ft_putstr_fd("\n", 2);
		}
		free(line);
	}
	//	Boucle pour tester les fuites
	//	while (1)
	//		;
	delete_env(&e);
	return (0);
}