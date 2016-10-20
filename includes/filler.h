#ifndef FILLER_H
# define FILLER_H
# include "../libft/includes/libft.h"

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct 		s_piece
{
	t_point			pts;
	int				dist;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_env
{
	char			player;
	char			ennemy;
	t_point			map_coord;
	char			**map;
	t_point			piece_coord;
	char			**piece;
	t_point			solver;
}					t_env;

/* check.c */
int					limit_cross_map(t_env *e, int x, int y);
int					limit_cross_piece(t_env *e, int x, int y);
int					is_player(t_env *e, char c);
int					is_ennemy(t_env *e, char c);

/* math.c */
int					ft_abs(int num);
int					ft_sqrt(int num);
int					hypothenus(t_point a, t_point b);

/* tools.c */
int					delete_env(t_env *e);
t_point				set_point(int x, int y);
void				free_tab(char **tab);
void 				print_color_map(t_env *e);

/* parse.c */
int					parse_data(t_env *e);

/* list_pieces.c */
t_piece				*set_piece(int x, int y);
void				add_to_list(t_piece **pieces, t_piece *new);

/* flood_fill.c */
int					filler(t_env *, t_piece *pieces);
int					flood_fill(t_env *e, t_piece *pieces);

/* filler.c */
int					play_the_filler(t_env *e);
#endif
