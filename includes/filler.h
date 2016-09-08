#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

typedef struct 	s_env
{
	char		num_player;
	int 		map_x;
	int 		map_y;
	int 		solve_x;
	int 		solve_Y;

}				t_env;

void			free_tab(char **tab);
void			init_env(t_env *e);

//int			find_player(char *line, t_env *e);

#endif