#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

# define ABS(x) (x > 0 ? x : -x)

typedef struct		s_point
{
	char			c;
	char			**map;
	int				x;
	int				y;
}					t_point;

typedef struct 		s_env
{
	char			num_player;
	t_point			map;
	t_point			piece;
	t_point			player;
	t_point			opponent;
	t_point			solver;
}					t_env;

void				debug(t_env *e);
int					hypothenus(t_point a, t_point b);

int					length_tab(char **tab);
void				print_tab(char **tab);
void				free_tab(char **tab);
void				free_env(t_env **e);
void				init_env(t_env **e);
void				add_to_list(t_point **pos, int y, int x);

int					get_error(char **av, char **parse);
void				get_num_player(t_env *e, char **parse);
void				get_map(t_env *e, char **line);
void				get_coord_map(t_env *e, char **line);
void				get_piece(t_env *e, char **line);
void				get_piece_map(t_env *e, char **line);

void				search_player_pos(char c, t_env *e);
void				search_opponent_pos(char c, t_env *e);

int					create_map(char *line, t_env *e);
int					solve_filler(t_env *e);

#endif
