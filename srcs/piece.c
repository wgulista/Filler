#include "../includes/filler.h"

int 		find_piece(char *line, t_env *e)
{
	char	**piece;

	piece = NULL;
	if (ft_strstr(line, "Piece") != NULL)
	{
		piece = ft_strsplit(line, ' ');
		e->piece_xy.x = ft_atoi(piece[1]);
		e->piece_xy.y = ft_atoi(piece[2]);
		free_tab(piece);
		return (1);
	}
	return (0);
}