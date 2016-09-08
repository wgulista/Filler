#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

typedef struct	s_point
{
	char		*map;
	int			x;
	int			y;
}				t_point;

typedef struct 	s_env
{
	char		num_player;
	t_point		map_xy;
	t_point		piece_xy;
	t_point		solve_xy;
}				t_env;

void			print_tab(char **tab);
void			free_tab(char **tab);
void			init_env(t_env *e);
int				find_map(char *line, t_env *e);
int				find_piece(char *line, t_env *e);
int				find_player(char *line, t_env *e, char **av);
int				create_map(char *line, t_env *e);
int				solve_filler(t_env *e);

#endif