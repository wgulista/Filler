#include "../includes/filler.h"

/*int			pos_piece(int i, int j, t_env *e)
{
	int		k;
	int		l;
	char	player;

	k = -1;
	player = (e->num_player == 1) ? 'O' : 'X';
	while (++k < e->piece.y)
	{
		l = -1;
		while (++l < e->piece.x)
		{
			ft_putstr_fd("I + K = ", 2);
			ft_putnbr_fd(i + k, 2);
			ft_putendl_fd("", 2);
			e->solver.y = e->player.y + i + k;
			e->solver.x = e->player.x + j + l;
			return (1);
			//e->map.map[i + k][j + l];
			//ft_putchar_fd(e->piece.map[k][l], 2);
		}
		ft_putchar_fd('\n', 2);
	}
	return (1);
}*/

int			solve_filler(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < e->map.y)
	{
		j = -1;
		while (++j < e->map.x)
		{
			e->solver.x = e->player.x;
			e->solver.y = e->player.y;
			return (1);
			/*if (pos_piece(i, j, e))
				return (1);*/
		}
	}
	return (0);
}